#include "ShaderClass.h"
#include <filesystem>
#include <stdexcept>
#include <cstring>
#include <cerrno>

// Reads a text file and returns its contents (throws on error)
std::string Shader::get_file_contents(const char* filename)
{
    std::ifstream in(filename, std::ios::binary);
    if (!in) {
        int err = errno;
        throw std::runtime_error(std::string("Failed to open file '") + filename + "': " + std::strerror(err));
    }

    // Seek to end to determine size
    in.seekg(0, std::ios::end);
    std::streampos size = in.tellg();
    if (size == std::streampos(-1)) {
        throw std::runtime_error(std::string("Failed to determine size of file '") + filename + "'");
    }
    std::string contents;
    contents.resize(static_cast<size_t>(size));
    in.seekg(0, std::ios::beg);
    in.read(&contents[0], contents.size());
    return contents;
}

// Constructor that builds the Shader Program from 2 (or 3) shader files
Shader::Shader(const char* vertexFile, const char* fragmentFile, const char* geometryFile)
{
    // Read vertex and fragment files (throw on failure)
    std::string vertexCode = get_file_contents(vertexFile);
    std::string fragmentCode = get_file_contents(fragmentFile);

    // Geometry is optional: only load if a non-empty path was provided and the file exists
    std::string geometryCode;
    if (geometryFile != nullptr && std::strlen(geometryFile) > 0) {
        std::filesystem::path geometryPath(geometryFile);
        if (!std::filesystem::exists(geometryPath)) {
            std::cout << "GEOMETRY SHADER FILE NOT FOUND: " << geometryFile << std::endl;
            geometryFile = nullptr; // treat as not provided
        }
        else {
            geometryCode = get_file_contents(geometryFile);
        }
    }

    const char* vertexSource = vertexCode.c_str();
    const char* fragmentSource = fragmentCode.c_str();

    // Create and compile vertex shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);
    compileErrors(vertexShader, "VERTEX");

    // Create and compile fragment shader
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);
    compileErrors(fragmentShader, "FRAGMENT");

    // Geometry shader (optional)
    GLuint geometryShader = 0;
    if (!geometryCode.empty()) {
        const char* geometrySource = geometryCode.c_str();
        geometryShader = glCreateShader(GL_GEOMETRY_SHADER);
        glShaderSource(geometryShader, 1, &geometrySource, NULL);
        glCompileShader(geometryShader);
        compileErrors(geometryShader, "GEOMETRY");
    }

    // Create program and attach shaders
    ID = glCreateProgram();
    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragmentShader);
    if (geometryShader != 0) {
        glAttachShader(ID, geometryShader);
    }

    glLinkProgram(ID);
    compileErrors(ID, "PROGRAM");

    // Clean up shader objects
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    if (geometryShader != 0) {
        glDeleteShader(geometryShader);
    }
}

// Activate and Delete unchanged
void Shader::Activate() { glUseProgram(ID); }
void Shader::Delete() { glDeleteProgram(ID); }

// Improved compile/link error reporting
void Shader::compileErrors(unsigned int shader, const char* type)
{
    GLint success = 0;
    char infoLog[1024] = { 0 };

    // Compare type contents properly
    if (std::strcmp(type, "PROGRAM") != 0) {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (success == GL_FALSE) {
            glGetShaderInfoLog(shader, sizeof(infoLog), NULL, infoLog);
            std::string msg = std::string("SHADER_COMPILATION_ERROR for:") + type + "\n" + infoLog;
            std::cout << msg << std::endl;
        }
    }
    else {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (success == GL_FALSE) {
            glGetProgramInfoLog(shader, sizeof(infoLog), NULL, infoLog);
            std::string msg = std::string("SHADER_LINKING_ERROR for:") + type + "\n" + infoLog;
            std::cout << msg << std::endl;
        }
    }
}
