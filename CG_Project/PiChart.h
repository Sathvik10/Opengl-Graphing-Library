#pragma once
#include <vector>
#include <string>
#include <GL/glut.h>
#ifndef M_PI
#    define M_PI 3.14159265358979323846
#endif

class PiChart {
public:
	std::vector<std::string> xData;
	std::vector<float> yData;
	std::vector<std::vector<GLfloat>> PiColor;
	int width = 1;
	int iterationIncrement = 5;
	float totalYData;
	float degScale = 0;
	bool compact = true;
	bool assertDraw = true;
	float cx = 10;
	float cy = 10;
	float radius = 5;
	void writePercent(std::string str, float startAngle, float arcAngle);

public:
	void draw();
	void setIterationIncrement(int _ii);
	void drawArc(float cx, float cy, float r, float start_angle, float arc_angle);
	void computeScale();
	void setWidth(int _nos);
	void setColor(std::vector<std::vector<GLfloat>> _color);
	void updateColor(std::vector<GLfloat> _color, int _nop);
	void updateXData(std::vector<std::string> x);
	void updateYData(std::vector<float> y);
	void appendXData(std::vector<std::string> x);
	void appendyData(std::vector<float> y);
};
