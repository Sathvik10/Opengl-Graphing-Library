#include <Gl/glut.h>
#include <vector>
#include <iostream>
#include "graph.h"
#include "utility.h"

void Bar2DGraph::appendYData(std::vector<int> y)
{
	if (y.size() > xData.size())
	{
		//Print the error 
		return;
	}
	yData = y;
	computeScale();
}

void Bar2DGraph::setBarWidth(int _width)
{
	barWidth = _width;
}


void Bar2DGraph::setXMax(int _xMax)
{
	xMax = _xMax;
}

void Bar2DGraph::setYMax(int _yMax)
{
	if (_yMax % yDivision != 0)
		yMax = _yMax + (yDivision - (_yMax % yDivision));
	else
		yMax = _yMax;
}

void Bar2DGraph::setYDivision(int _yDiv)
{
	yDivision = _yDiv;
	if (yMax % yDivision != 0)
		yMax = yMax + (yDivision - (yMax % yDivision));
}

void Bar2DGraph::computeScale()
{
	if (xData.size() == 0)
		return;
	xScale = (float)xMax / xData.size();
	int max = -1000000;
	for (int x : yData)
	{
		if (x > max)
			max = x;
	}
	if (max % yDivision == 0)
	{
		yDataMax = max;
	}
	else
	{
		yDataMax = max + (yDivision - (max % yDivision));
	}
	yScale = ((float)yMax / yDataMax);
	yMarkDiv = (float)yMax / yDivision;
}

void Bar2DGraph::setCompact(bool _com)
{
	compact = _com;
}

void Bar2DGraph::appendXData(std::vector<int> x)
{
	xData = x;
}

void Bar2DGraph::setBarColor(std::vector<GLfloat> rgb)
{
	lineColor = rgb;
}

void Bar2DGraph::updateData(std::vector<int> y)
{
	yData = y;
	computeScale();
}

void Bar2DGraph::openglDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	draw();
	glFlush();
}

void Bar2DGraph::draw()
{
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	drawLine(0, 0, xMax + 2, 0);
	drawLine(0, 0, 0, yMax + 2);

	glColor4f(0.9f, 0.9f, 0.9f, 0.1f);

	for (int i = 1; i <= yDivision; i++)
	{
		drawLine(0.0f, yMarkDiv * i, (float)xMax, yMarkDiv * i);
	}

	glColor4f(1.0f, 0.0f, 0.0f, 0.5f);

	glRasterPos2f((float)xMax / 2, -2.0f);
	for (char c : xLabel)
	{
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, c);
	}

	glRasterPos2f(-2.0f, (float)yMax / 2);
	for (char c : yLabel)
	{
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, c);
	}

	if (yData.size() == 0 || (xData.size() != yData.size()))
	{
		return;
	}

	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	for (int i = 0;i < xData.size(); i++)
	{
		std::string str = std::to_string(xData[i]);
		glRasterPos2f(xScale * (i + 1) - 0.5f, -1.0f);
		for (char c : str)
		{
			glutBitmapCharacter(GLUT_BITMAP_8_BY_13, c);
		}
	}
	int yMarkLabel = yMax / yDivision;
	int ydisplayLabel = yDataMax / yDivision;
	for (int i = 0;i < yDivision; i++)
	{
		std::string str = std::to_string(ydisplayLabel * (i + 1));
		glRasterPos2f(-1.0f, (float)(yMarkLabel * (i + 1)));
		for (char c : str)
		{
			glutBitmapCharacter(GLUT_BITMAP_8_BY_13, c);
		}
	}
	//scale display
	std::string xscaletext = "X-Scale:" + std::to_string(xScale);
	std::string yscaletext = "Y-Scale:" + std::to_string(yScale);
	glRasterPos2d((float)xMax - 5, (float)yMax + 3);
	for (char c : xscaletext)
	{
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, c);
	}

	glRasterPos2d((float)xMax - 5, (float)yMax +1.0f);
	for (char c : yscaletext)
	{
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, c);
	}

	glColor4f(lineColor[0], lineColor[1], lineColor[2], 1.0f);
	for (int i = 0; i < xData.size(); i++)
	{
		draw2DBar(xScale * (i + 1), (float)yData[i] * yScale, barWidth);
	}
}