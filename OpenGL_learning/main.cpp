
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>

#include "PrimitivesDrawingTools.h"

const int WINDOWS_WIDTH = 640 * 2;
const int WINDOWS_HEIGHT = 800;

int main()
{
	GLFWwindow* window;
	if (!glfwInit())
		exit(EXIT_FAILURE);
	window = glfwCreateWindow(WINDOWS_WIDTH, WINDOWS_HEIGHT, "OpenGL_learning", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);

	glEnable(GL_POINT_SMOOTH);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	GLfloat current_x_pos = 0.0f;

	while (!glfwWindowShouldClose(window))
	{
		float ratio;
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		ratio = (float)width / (float)height;
		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT);
		
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		/*glRotatef((float)glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
		glBegin(GL_TRIANGLES);
		glColor3f(1.f, 0.f, 0.f);
		glVertex3f(-0.6f, -0.4f, 0.f);
		glColor3f(0.f, 1.f, 0.f);
		glVertex3f(0.6f, -0.4f, 0.f);
		glColor3f(0.f, 0.f, 1.f);
		glVertex3f(0.f, 0.6f, 0.f);
		glEnd();*/

		Vertex v = { current_x_pos, 0.0f, 0.0f, 0.5f, 1.0f, 1.0f, 1.0f };
		//drawingTools::drawPoint(v, 60.0f);

		//Vertex v1 = { 0.0f, 0.0f, 0.0f, 0.5f, 1.0f, 1.0f, 1.0f };
		//Vertex v2 = { -1.0f, -1.0f, 0.0f, 0.5f, 1.0f, 1.0f, 1.0f };
		//drawingTools::drawLineSegment(v1, v2, 2.0f);

		drawingTools::drawGrid(5.0f, 1.0f, 0.1f);

		Vertex v1 = { 0.0f, 0.8f, 0.0f, 1.0f, 0.0f, 0.0f, 0.6f };
		Vertex v2 = { -1.0f, -0.8f, 0.0f, 0.0f, 1.0f, 0.0f, 0.6f };
		Vertex v3 = { 1.0f, -0.8f, 0.0f, 0.0f, 0.0f, 1.0f, 0.6f };
		drawingTools::drawTriangle(v1, v2, v3);
		
		current_x_pos += 0.01f;
		if (current_x_pos >= 1.0f)
			current_x_pos = 0.0f;
		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}
