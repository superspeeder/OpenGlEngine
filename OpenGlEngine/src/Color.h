#pragma once
class Color
{
public:

	Color(float r, float g, float b, float a);
	Color(float r, float g, float b);
	Color(float graytone);
	~Color();

	void SetColor(float r, float g, float b, float a);
	void SetColor(float r, float g, float b);
	void SetColor(float graytone);


	float r, g, b, a;
};

