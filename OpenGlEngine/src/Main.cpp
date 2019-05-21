#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <vector>


#include "Display.h"
#include "Color.h"
#include "Renderer.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Utils.h"
#include "ShaderProgram.h"
#include "Main.h"

int main(void) {
	
	if (!glfwInit()) {
		std::cout << "GLFW failed to initialize" << std::endl;
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

	GLFWwindow* window;
	window = glfwCreateWindow(800, 800, "Window", NULL, NULL);

	if (!window) {
		return -1;
	}

	glfwMakeContextCurrent(window);


	if (glewInit() != GLEW_OK) {
		return -1;
	}

	glfwSwapInterval(1);
	{
		Display display(window);

		Color backgroundColor = Color(0.5f);

		display.SetBackgroundColor(&backgroundColor);

		Renderer renderer;

		float positions[] = {
			1.0f , 0.0f,
			-1.0f, 0.0f,
			0.0f , 1.0f,
			0.0f ,-1.0f
		};

		unsigned int indicies[] = {
			0,1,2,
			0,1,3
		};


		VertexBuffer vertBuffer = VertexBuffer(positions, 8 * sizeof(float));
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
		vertBuffer.Unbind();

		IndexBuffer indexBuffer = IndexBuffer(indicies, 6 * sizeof(unsigned int));

		ShaderProgram basicShader = ShaderProgram("res/shaders/basic");

		while (!glfwWindowShouldClose(window)) {
			display.Clear();

			//basicShader->Use();
			indexBuffer.Bind();
			vertBuffer.Bind();

			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);



			glfwSwapBuffers(window);

			glfwPollEvents();
		}
		glfwTerminate();
	}

	return 0;
}