#include <iostream>
#include <stdio.h>
#include <chrono>

#include "World/World.h"
#include "World/Camera.h"

#include "GlobalSettings.h"

#include "Windows/ViewportWindow.h"
#include "Windows/Window.h"

#include "Subsystems/Saving/SaveManager.h"



// Main code
int SolarMain(int, char**)
{
	SaveManager Saver;
	
	World world;

	world.ConstructWorld();

	windowPtr->InitFrameBuffer();

	// Initialize Engine Windows
	ViewportWindow viewportWindow;
	ViewportWindow ShadowWindow;

	glEnable(GL_DEPTH_TEST);

	float window_width = 0, window_height = 0;
	float Shadow_width = 512, Shadow_height = 512;


	Camera camera(window_width, window_height, glm::vec3(0.0f, 0.0f, 2.0f));
	Camera camera2(Shadow_width, Shadow_height, glm::vec3(0.0f, 0.0f, 2.0f));
	globals::cam = &camera;
	globals::cam2 = &camera2;
	camera.ShadowPerspective = false;
	camera2.ShadowPerspective = false;
	camera2.TestShadowPerspective = true;

	using clock = std::chrono::high_resolution_clock;
	auto lastTime = clock::now();

	glfwSwapInterval(0);

	while (!glfwWindowShouldClose(globals::window1.getWindow()))
	{
		//glfwSwapInterval(0); // Enable vsync
		// Calculate delta time
		auto currentTime = clock::now();
		std::chrono::duration<float> elapsed = currentTime - lastTime;
		float deltaTime = elapsed.count();
		lastTime = currentTime;

		glfwPollEvents();
		if (glfwGetWindowAttrib(globals::window1.getWindow(), GLFW_ICONIFIED) != 0)
		{
			//ImGui_ImplGlfw_Sleep(10);
			continue;
		}

		windowPtr->NewFrame();

		//Render Viewport
		viewportWindow.Draw(window_width, window_height, camera, *windowPtr,false);

		ShadowWindow.Draw(Shadow_width, Shadow_height, camera2, *windowPtr, true, "ShadowView");

		windowPtr->getFrameBuffer2()->Bind();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glViewport(0, 0, 4096, 4096);
		world.Render(windowPtr, &camera2);
		windowPtr->getFrameBuffer2()->Unbind();

		glViewport(0, 0, window_width, window_height);

		//Begin rendering to viewport frame-buffer
		windowPtr->getFrameBuffer()->Bind();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		camera.Inputs(windowPtr->getWindow());
		camera.updateMatrix(45.0f, 0.01f, 100000.0f);

		// Update the physics
		// If you take larger steps than 1 / 60th of a second you need to do multiple collision steps in order to keep the simulation stable.
		const int cCollisionSteps = 2;
		physics_system.Update(deltaTime, cCollisionSteps, &temp_allocator, &job_system);

		world.TickWorld(deltaTime);
		world.Render(windowPtr, &camera);

		

		windowPtr->EndFrame();
		
	}

	FileDatabase::Save("FileNameDatabase.ini");

	// Cleanup
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();

		windowPtr->getFrameBuffer()->Delete();

		glfwDestroyWindow(windowPtr->getWindow());
		glfwTerminate();
	}

	return 0;
}