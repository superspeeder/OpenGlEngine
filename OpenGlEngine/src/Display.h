#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Color.h"

class Display
{
private:
	GLFWwindow* window;
	Color* backgroundColor;
public:
	Display(GLFWwindow* win);
	~Display();
	void Clear();
	void SetBackgroundColor(Color* color);
};

