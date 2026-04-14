#include "Camera.h"

SpectateCamera::SpectateCamera(float width, float height, vec3 Position) : Camera(width, height, Position)
{
    
    this->Orientation = vec3(0.0f, 0.0f, -1.0f);
    this->Up = vec3(0.0f, 1.0f, 0.0f);
    this->cameraMatrix = glm::mat4(1.0f);


    this->ShadowPerspective = false;
    this->TestShadowPerspective = false;

    // Yaw and pitch
    this->yaw = -90.0f; // Facing -Z
    this->pitch = 0.0f;

    this->speed = 0.01f;
    this->sensitivity = 0.2f;

	this->Position = Position;
	this->width = width;
	this->height = height;
	this->Orientation = vec3(0.0f, 0.0f, -1.0f);
	this->Up = vec3(0.0f, 1.0f, 0.0f);
}

void SpectateCamera::updateMatrix(float FOV, float nearPlane, float farPlane)
{
    if (TestShadowPerspective) {
        return;
    }
	mat4 view = mat4(1.0f);
	mat4 projection = mat4(1.0f);

	view = lookAt(Position, Position + Orientation, Up);
	projection = perspective(radians(FOV), width / height, nearPlane, farPlane);

	cameraMatrix = projection * view;
}

void SpectateCamera::Matrix(Shader& shader, const char* uniform)
{
    if (TestShadowPerspective) {
        glm::mat4 orthonalProjection = glm::ortho(-5.0f, 5.0f, -5.0f, 5.0f, 0.1f, 50.0f);
        glm::mat4 directonalLightView = glm::lookAt(vec3(-20.0f, 20.0f, 20.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f));
        glm::mat4 lightProjection = orthonalProjection * directonalLightView;
        glUniformMatrix4fv(glGetUniformLocation(shader.ID, uniform), 1, GL_FALSE, value_ptr(lightProjection));
    }
    else {
        glUniformMatrix4fv(glGetUniformLocation(shader.ID, uniform), 1, GL_FALSE, value_ptr(cameraMatrix));
    }
}

void SpectateCamera::Inputs(GLFWwindow* window)
{
    if (TestShadowPerspective) {
        return;
    }
    // Movement speed adjustment
    float currentSpeed = speed;
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
        currentSpeed *= 2.5f; // Faster movement when Shift is held

    // WASD movement
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        Position += Orientation * currentSpeed;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        Position -= Orientation * currentSpeed;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        Position -= normalize(cross(Orientation, Up)) * currentSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        Position += normalize(cross(Orientation, Up)) * currentSpeed;
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
        Position -= Up * currentSpeed;
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
        Position += Up * currentSpeed;

    // Mouse look with RMB
    static bool firstClick = true;
    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS)
    {
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);

        static double lastX = width / 2.0;
        static double lastY = height / 2.0;

        if (firstClick)
        {
            lastX = xpos;
            lastY = ypos;
            firstClick = false;
        }

        float xoffset = static_cast<float>(xpos - lastX);
        float yoffset = static_cast<float>(lastY - ypos); // Reversed since y-coordinates go from bottom to top

        lastX = xpos;
        lastY = ypos;

        xoffset *= sensitivity;
        yoffset *= sensitivity;

        yaw += xoffset;
        pitch += yoffset;

        // Clamp pitch
        if (pitch > 89.0f) pitch = 89.0f;
        if (pitch < -89.0f) pitch = -89.0f;

        // Update orientation
        vec3 direction;
        direction.x = cos(radians(yaw)) * cos(radians(pitch));
        direction.y = sin(radians(pitch));
        direction.z = sin(radians(yaw)) * cos(radians(pitch));
        Orientation = normalize(direction);
    }
    else
    {
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        firstClick = true;
    }
}
