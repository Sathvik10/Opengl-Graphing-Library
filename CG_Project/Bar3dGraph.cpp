#include <GL/glew.h>
#include <Gl/glut.h>
#include <vector>
#include <string.h>
#include <iostream>
#include "graph.h"
#include "utility.h"

void Bar3dGraph::setEdgeColor(std::vector <GLfloat> rgb)
{
	edgeColor = rgb;
}

void Bar3dGraph::setBarWidth(float _width)
{
	cubeWidth = _width;
}

void Bar3dGraph::setBarColor(std::vector<GLfloat> rgb)
{
	barColor = rgb;
}
void Bar3dGraph::drawBackGround()
{
	glColor3f(0.3f, 0.3f, 0.3f);
	glBegin(GL_POLYGON);
	glVertex3f(0, -0.001, 0);
	glVertex3f(0, -0.001, -zMax);
	glVertex3f(xMax, -0.001, -zMax);
	glVertex3f(xMax, -0.001, 0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(0, 0, -zMax);
	glVertex3f(0, yMax, -zMax);
	glVertex3f(xMax, yMax, -zMax);
	glVertex3f(xMax, 0, -zMax);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(xMax, 0, -zMax);
	glVertex3f(xMax, yMax, -zMax);
	glVertex3f(xMax, yMax, 0);
	glVertex3f(xMax, 0, 0);
	glEnd();
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINE_LOOP);
	glVertex3f(xMax, -0.001, 0);
	glVertex3f(xMax, -0.001, -zMax);
	glVertex3f(0, -0.001, -zMax);
	glVertex3f(0, -0.001, 0);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex3f(0, 0, -zMax);
	glVertex3f(0, yMax, -zMax);
	glVertex3f(xMax, yMax, -zMax);
	glVertex3f(xMax, 0, -zMax);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex3f(xMax, 0, -zMax);
	glVertex3f(xMax, yMax, -zMax);
	glVertex3f(xMax, yMax, 0);
	glVertex3f(xMax, 0, 0);
	glEnd();
}

void Bar3dGraph::drawGridLines()
{
	glColor3f(0.2f, 0.2f, 0.2f);
	for (int i = 1; i <= zDivision; i++)
	{
		drawLine(0, 0, -i * 4, xMax, 0, -i * 4);
	}
	for (int i = 0; i <= xDivision; i++)
	{
		drawLine(i*4, 0, 0, i * 4, 0, -zMax);
	}

	for (int i = 0; i <= yDivision; i++)
	{
		drawLine(xMax, i*4, 0, xMax, i*4, -zMax);
	}
	for (int i = 0; i <= zDivision; i++)
	{
		drawLine(xMax, 0, -i*4, xMax, yMax, -i*4);
	}

	for (int i = 0; i <= yDivision; i++)
	{
		drawLine(0, i * 4, -zMax, xMax, i * 4, -zMax);
	}
	for (int i = 0; i <= xDivision; i++)
	{
		drawLine(i * 4, 0, -zMax, i * 4,yMax ,-zMax);
	}
}

void Bar3dGraph::drawCubes(int x, int y, int z)
{
	glColor3f(1.0f, 1.0f, 0.0f);
	glPushMatrix();
	glTranslatef((float)x*4, (float)y / 2 + 0.2f, -(float)z*4);
	cuboid(cubeWidth, (float)y, cubeWidth,barColor, edgeColor);
	glPopMatrix();
}

void Bar3dGraph::draw()
{
	if (!assertDraw)
		return;
	glPushMatrix();
	glRotatef(45.0f, 0.0f, 1.0f, 0.0f);
	drawBackGround();
	drawGridLines();

	glColor3f(0.0f, 0.0f, 0.0f);
	for (int i = 0; i < xData.size(); i++)
	{
		std::string str = std::to_string(xData[i]);
		glRasterPos3f((float)(i+1)*4, 0 , 1.0f);
		for (char c : str)
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
		}
	}
	glColor3f(0.0f, 0.0f, 0.0f);
	for (int i = 0; i < zData.size(); i++)
	{
		std::string str = std::to_string(zData[i]);
		glRasterPos3f(-1.0f, 0 ,-(float)(i + 1) * 4);
		for (char c : str)
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
		}
	}

	glColor3f(0.0f, 0.0f, 0.0f);
	float yMark = yDataMax / yDivision;
	for (int i = 1; i <= yDivision; i++)
	{
		std::string str = std::to_string(i * (1/yScale) * 4);
		glRasterPos3f(xMax + 3, i * 4, -1.0f);
		for (char c : str)
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
		}
	}


	int x = 1;
	int z = 1;
	for (int i = 0; i < yData.size(); i++)
	{
		drawCubes(x, yData[i] * yScale, z);
		x++;
		if (x % xDivision == 0)
		{
			x = 1;
			z++;
		}
	}
	glPopMatrix();
	std::string yscaletext = "Y-Scale:" + std::to_string(yScale);

	glRasterPos3d((float)10, (float)20, -2);
	for (char c : yscaletext)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, c);
	}

}

void Bar3dGraph::appendYData(std::vector<int> y)
{
	if (y.size() > (xDivision - 1) * (zDivision - 1))
	{
		assertDraw = false;;
		std::cout << "SOmethingg wrogm";
		return;
	}
	assertDraw = true;
	yData = y;
	computeScale();
}
void Bar3dGraph::appendXData(std::vector<int> x)
{
	xData = x;
	xDivision = xData.size() + 1;
	xMax = 4 * xDivision;
}
void Bar3dGraph::appendZData(std::vector<int> z)
{
	zData = z;
	zDivision = zData.size() + 1;
	zMax = 4 * zDivision;
}

void Bar3dGraph::computeScale()
{
	int max = -1000000;
	for (int z : yData)
	{
		if (max < z)
			max = z;
	}
	yDataMax = max;
	yScale =(float) yMax / (float)max;
	std::cout << yScale;
}

void Bar3dGraph::updateYData(std::vector<int> y)
{
	if (y.size() > (xDivision - 1) * (zDivision - 1))
	{
		assertDraw = false;;
		std::cout << "SOmethingg wrogm";
		return;
	}
	assertDraw = true;
	yData = y;
	computeScale();
}