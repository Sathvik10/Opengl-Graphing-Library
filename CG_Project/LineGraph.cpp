#include <Gl/glut.h>
#include <vector>
#include <iostream>
#include "graph.h"
#include "utility.h"

void LineGraph::appendYData(std::vector<int> y, int _nol)
{
	if (_nol > numberOfLines || y.size() > xData.size())
	{
		//Print Tthe error
		return;
	}
	yData[_nol - 1] = y;
	computeScale();
}
void LineGraph::setYDivision(int _yDiv)
{
	yDivision = _yDiv;
	if (yMax % yDivision != 0)
	{
		if (yMax > 17)
			yMax = yMax - (yMax % yDivision);
		else
			yMax = yMax + (yDivision - (yMax % yDivision));
	}
		
	computeScale();
}

void LineGraph::computeScale()
{
	if (xData.size() == 0)
		return;
	xScale = (float)xMax / xData.size();
	int max = -1000000;
	for (auto vec : yData)
	{
		for (int x : vec)
		{
			if (x > max)
				max = x;
		}
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


void LineGraph::setLineColor(std::vector <GLfloat> rgb, int _nol)
{
	if (_nol > numberOfLines)
		return;
	lineColor[_nol - 1] = rgb;
}


void LineGraph::updateData(std::vector<int> y, int _nol)
{
	if (_nol > numberOfLines)
		return;
	yData[_nol - 1] = y;
	computeScale();
}

int LineGraph::getLineNumber()
{
	return numberOfLines;
}

void LineGraph::draw()
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
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
	}

	glRasterPos2f(-2.0f, (float)yMax / 2);
	for (char c : yLabel)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
	}

	if (yData.size() == 0 || (xData.size() != yData[0].size()))
	{
		return;
	}


	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	for (int i=0 ;i < xData.size(); i++)
	{
		std::string str = std::to_string(xData[i]);
		glRasterPos2f(xScale * (i+1) - 0.5f, -1.0f);
		for (char c : str)
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
		}
	}

	int yMarkLabel = yMax / yDivision;
	int ydisplayLabel = yDataMax / yDivision;
	for (int i = 0;i < yDivision; i++)
	{
		std::string str = std::to_string(ydisplayLabel * (i+1));
		glRasterPos2f(-1.0f, (float)(yMarkLabel * (i + 1)));
		for (char c : str)
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
		}
	}
	//scale display
	std::string xscaletext ="X-Scale:" + std::to_string(xScale);
	std::string yscaletext = "Y-Scale:" + std::to_string(yScale);
	
	glRasterPos2d((float)xMax, (float)yMax);
	for (char c : xscaletext)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
	}

	glRasterPos2d((float)xMax, (float)yMax-2.0f);
	for (char c : yscaletext)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
	}

	for (int j = 0; j < yData.size(); j++)
	{
		glColor4f(lineColor[j][0], lineColor[j][1], lineColor[j][2], 1.0f);
		for (int i = 1; i <= xData.size() - 1; i++)
		{
			drawLine(xScale * i, (float)yData[j][i - 1] * yScale, xScale * (i + 1), (float)yData[j][i] * yScale);
		}
	}
}