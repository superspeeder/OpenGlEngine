#include "Color.h"



Color::Color(float r, float g, float b, float a)
{
	SetColor(r,g,b,a);
}

Color::Color(float r, float g, float b)
{
	SetColor(r,g,b);
}

Color::Color(float graytone)
{
	SetColor(graytone);
}

void Color::SetColor(float r_, float g_, float b_, float a_)
{
	r = r_;
	g = g_;
	b = b_;
	a = a_;
}

void Color::SetColor(float r_, float g_, float b_)
{
	r = r_;
	g = g_;
	b = b_;
	a = 1.0f;
}

void Color::SetColor(float graytone)
{
	SetColor(graytone, graytone, graytone);
}


Color::~Color()
{
}
