#include <gl/glew.h>
#include<gl/glut.h>
#include <iostream>
#include <vector>
#include "LabDemo.h"
//#include "graph.h"
//#include "PiChart.h"
//#include "SurfacePlot.h"
//#include "Surface3dPlot.h"

/*
PiChart p1;
SurfacePlot s1;
Surface3dPlot s2;
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
	glPushMatrix();
		s2.draw();
	glPopMatrix();
	glFlush();
}

float calc(float x)
{
	return  sin(x * 10.0) / (1.0 + x * x);
}

void minit()
{
	std::vector<std::string> x = { "CRIC", "FOOT", "TT" , "BADMI" };
	std::vector<float> y = { 3.0, 1.0, 1.0, 1.0 };
	p1.appendXData(x);
	p1.appendyData(y);
	p1.setColor({ {1.0f,1.0f,0.0f}, {0.0f,1.0f,1.0f}, {1.0f,0.0f,0.0f}, {1.0f,0.0f,1.0f} });
	s1.SetFunction(calc);
	s1.fillBuffer();
	s2.fillBuffer();
	/*
	b1.appendXData(x);
	std::vector<int> y1 = { 3,1,6,9 };
	b1.appendYData(y,1);
	b1.setLineColor({ 0.0f, 1.0f, 1.0f },1);
	b1.appendYData(y1, 2);
	b1.setLineColor({ 1.0f, 0.0f, 1.0f }, 2);

	glClearColor(1, 1, 1, 1);
	glColor4f(1.0, 0.0, 0.0, 1.0f);
	glLineWidth(2.5);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, 1.0f, 0.1f, 10.0f);
	//gluOrtho2D(-2, 20, -2, 20);
	glMatrixMode(GL_MODELVIEW);
}
void mouseAction(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		std::vector<float> y = { 12.0, 8.0, 9.0, 1.0 };
		p1.updateYData(y);
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

	}
}
void special(int key, int x, int y) {
	s1.SpecialFunc(key, x, y);
	glutPostRedisplay();
}
*/
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(5, 5);

	//glutCreateWindow("CSE");
	DemoFinalInit();

	//setLineGraph(2);
	//glutMouseFunc(lineMouseAction);
	//glutMouseFunc(mouseButton);
	//glutMotionFunc(mouseMove);
	//glutDisplayFunc(barGraph3dDraw);
	//glutSpecialFunc(special);
	//barGraph3dInit();
	surfacePlotFinalInit();

	Bar3dGraphInit();
	LineGraphInit();
	piChartFinalInit();
	bar2dFinalInit();

	//surfacePlotFinalInit();
	glutMainLoop();

	return 1;
}

