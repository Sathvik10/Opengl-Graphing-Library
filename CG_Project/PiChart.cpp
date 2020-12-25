#include <vector>
#include <string>
#include <iostream>
#include <GL/glut.h>
#include <math.h>
#include "PiChart.h"

void PiChart::appendXData(std::vector<std::string> x)
{
	xData = x;
	assertDraw = false;
}

void PiChart::appendyData(std::vector<float> y)
{
	if (xData.size() != y.size())
	{
		//Print tye error
		std::cout << "Size of the x input and y input is different" << xData.size() << " " << y.size();
		assertDraw = false;
		return;
	}
	assertDraw = true;
	yData = y;
	computeScale();
}


void PiChart::computeScale()
{
	totalYData = 0;
	for (float y : yData)
	{
		totalYData += y;
	}
	degScale = (float)totalYData / 360;
}

void PiChart::updateXData(std::vector<std::string> x)
{
	xData = x;
	degScale = 0;
	totalYData = 0;
	assertDraw = false;
	yData = {};
}

void PiChart::updateYData(std::vector<float> y)
{
	if (xData.size() != y.size())
	{
		std::cout << "Size of the x input and y input is different" << xData.size() << " " << y.size();
		assertDraw = false;
		return;
	}
	assertDraw = true;
	yData = y;
	computeScale();
}

void PiChart::drawArc(float cx, float cy, float radius, float start_angle, float arc_angle)
{
	float radius1 = radius - width / 2;
	float radius2 = radius + width / 2;
	int sa = (int)start_angle;
	int end_angle = sa + arc_angle;

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(cx, cy);
	for (int i = sa; i <= end_angle; i += iterationIncrement)
	{
		GLfloat ang = (GLfloat)(i * M_PI) / 180;
		glVertex2f((float)(10 + cos(ang) * (radius1)), (float)(10 + sin(ang) * (radius1)));
		glVertex2f((float)(10 + cos(ang) * (radius2)), (float)(10 + sin(ang) * (radius2)));
	}
	GLfloat ang = (GLfloat)(end_angle * M_PI) / 180;
	glVertex2f((float)(10 + cos(ang) * (radius1)), (float)(10 + sin(ang) * (radius1)));
	glVertex2f((float)(10 + cos(ang) * (radius2)), (float)(10 + sin(ang) * (radius2)));
	glEnd();
}

void PiChart::setColor(std::vector<std::vector<GLfloat>> _color)
{
	if (_color.size() != yData.size())
	{
		std::cout << "Size of the color set and y input is different";
		assertDraw = false;
		return;
	}
	assertDraw = true;
	PiColor = _color;
}

void PiChart::draw()
{
	if (!assertDraw)
	{
		std::cout << "There is error in the input. Please initialise it from the start";
		return;
	}

	std::string str  = "1 deg = " + std::to_string(degScale);
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	glRasterPos2f(10, 18);
	for (char c : str)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
	}

	int legendX = cx + radius + 2;
	int legendY = cy + radius + 2;
	
	for (int i = 0;i < xData.size(); i++)
	{
		
		int boxX = legendX - 1;
		glColor3f(PiColor[i][0], PiColor[i][1], PiColor[i][2]);
		glBegin(GL_POLYGON);
		glVertex2f((float)boxX, (float)legendY+0.25);
		glVertex2f((float)boxX, (float)legendY-0.25);
		glVertex2f((float)boxX+0.5, (float)legendY-0.25);
		glVertex2f((float)boxX+0.5, (float)legendY+0.25);

		glEnd();

		std::string str = xData[i];
		glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
		glRasterPos2f(legendX , legendY );
		for (char c : xData[i])
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
		}
		legendY = legendY - 1;
	}
	
	float startAngle = 0;
	for (int i = 0; i < yData.size(); i++)
	{
		glColor3f(PiColor[i][0], PiColor[i][1], PiColor[i][2]);

		float angle =(float) (yData[i]*360) / totalYData;
		drawArc(cx , cy, radius, startAngle,  angle);

		glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
		int percent = (int)(yData[i] * 100) / totalYData;
		std::string str = std::to_string(percent);
		writePercent(str, startAngle, angle);

		startAngle += angle;
		glFlush();
	}


}

void
PiChart::writePercent(std::string str, float startAngle, float arcAngle)
{
	GLfloat ang = (GLfloat)((startAngle + arcAngle/2 ) * M_PI) / 180;
	float x = cx + cos(ang) * radius;

	float y = cy + sin(ang) * radius;

	str = str + " %";
	glRasterPos2f(x, y);
	for (char c : str)
	{
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, c);
	}
}

void PiChart::setWidth(int _nos)
{
	width = _nos;
}

void PiChart::setIterationIncrement(int _ii)
{
	iterationIncrement = _ii;
}
void PiChart::updateColor(std::vector<GLfloat> _color, int _nop)
{
	if (_nop > PiColor.size())
	{
		std::cout << "Out Of Bound";
			return;
	}
	PiColor[_nop] = _color;
}
