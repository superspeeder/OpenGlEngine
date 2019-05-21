#include "Display.h"

#include <iostream>


Display::Display(GLFWwindow* win)
{
	window = win;
}


Display::~Display()
{
}

void Display::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void Display::SetBackgroundColor(Color *color)
{
	backgroundColor = color;
	glClearColor(color->r, color->g, color->b, color->a);
}
