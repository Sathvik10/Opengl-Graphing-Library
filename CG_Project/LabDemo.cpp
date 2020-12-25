#include <gl/glew.h>
#include<gl/glut.h>
#include <iostream>
#include <vector>
#include <string>
#include "graph.h"
#include "PiChart.h"
#include "SurfacePlot.h"
#include "LabDemo.h"
#include "utility.h"

int window1;
int window2;
int window3;
int window4;

void reShape(int width, int height)
{
	float ar;
	if (height == 0)
		height = width;
	ar = (float)width / height;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (width <= height)
	{
		gluOrtho2D(-2, 20, -2 * ((float)height / (float)width), 20 * ((float)height / (float)width));
	}
	else
	{
		gluOrtho2D(-2, 20, -2 * ((float)width / (float)height), 20 * ((float)width / (float)height));
	}
	glMatrixMode(GL_MODELVIEW);
}

void reShape2(int width, int height)
{
	//if (width != height)
	//{
		//glViewport(0, 0, width, width);
	//}
	glViewport(0, 0, width, height);

}

LineGraph *l1;
std::vector<int> ypoints = {1, 1, 1, 4};
int lineNumber = 1;
void setLineGraph(int _nol)
{
	l1 = new LineGraph(_nol);
}
void setLineNumberMenu(int id)
{
	lineNumber = id;
}


void colorMenu(int id) {
	switch (id) {
	case 0:
		break;
	case 1:
		l1->setLineColor({ 0.0,0.0, 1.0 }, lineNumber);
		break;
	case 2:
		l1->setLineColor({ 0.0,1.0, 0.0 }, lineNumber);
		break;
	case 4:
		l1->setLineColor({ 1.0,0.0, 0.0 }, lineNumber);
		break;
	case 3:
		l1->setLineColor({ 0.0,1.0, 1.0 }, lineNumber);
		break;
	case 5:
		l1->setLineColor({ 1.0,0.0, 1.0 }, lineNumber);
		break;
	case 6:
		l1->setLineColor({ 1.0,1.0, 0.0 }, lineNumber);
		break;
	case 7:
		l1->setLineColor({ 1.0,1.0, 1.0 }, lineNumber);
		break;
	default:
		break;
	}
	lineGraphDraw();
}
void main_menu(int id) {


}
void setYdivision(int id)
{
	l1->setYDivision(id);
}
void lineGraphInit()
{
	std::vector<int> x = { 1 , 2, 3, 4 };
	std::vector<int> y = ypoints;
	std::vector<int> y1 = { 4, 1, 2, 3 };
	int setLineId = 0;
	int setYd = 0;
	if (l1)
	{
		l1->appendXData(x);
		l1->appendYData(y, 1);
		l1->appendYData(y1, 2);

		l1->setLineColor({ 1.0f, 0.0f, 0.0f }, 1);
		l1->setLineColor({ 1.0f, 0.0f, 1.0f }, 2);


		setLineId = glutCreateMenu(setLineNumberMenu);
		for (int i = 1; i <= l1->getLineNumber(); i++)
		{
			std::string str = "Line " + std::to_string(i);

			glutAddMenuEntry(str.c_str() , i);
		}
		glutAttachMenu(GLUT_LEFT_BUTTON);

		setYd = glutCreateMenu(setYdivision);
		for (int i = 3; i <= 6; i++)
		{
			std::string str = std::to_string(i);

			glutAddMenuEntry(str.c_str(), i);
		}
		glutAttachMenu(GLUT_LEFT_BUTTON);
	}

	int colorId = glutCreateMenu(colorMenu);
	glutAddMenuEntry("Red", 4);
	glutAddMenuEntry("Green", 2);
	glutAddMenuEntry("Blue", 1);
	glutAddMenuEntry("Black", 0);
	glutAddMenuEntry("Yellow", 6);
	glutAddMenuEntry("Cyan", 3);
	glutAddMenuEntry("Magenta", 5);
	glutAddMenuEntry("white", 7);
	glutAttachMenu(GLUT_LEFT_BUTTON);
	glutCreateMenu(main_menu);
	glutAddSubMenu("colors", colorId);
	glutAddSubMenu("Select Line", setLineId);
	glutAddSubMenu("Set Y Div", setYd);
	glutAttachMenu(GLUT_LEFT_BUTTON);

	glClearColor(1, 1, 1, 1);
	glColor4f(1.0, 0.0, 0.0, 1.0f);
	glLineWidth(2.5);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-2, 20, -2, 20);
	glMatrixMode(GL_MODELVIEW);
}

void lineGraphDraw()
{
		glClear(GL_COLOR_BUFFER_BIT);
		if(l1)
			l1->draw();
		glFlush();
}

void lineMouseAction(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		std::vector<int> y = { 12, 8, 9, 1 };
		l1->updateData(y, 1);
	}
}

void LineGraphInit()
{
	glutInitWindowPosition(400, 5);
	glutInitWindowSize(400, 400);
	window1 = glutCreateWindow("Line Graph");
	setLineGraph(2);
	lineGraphInit();
	glutMouseFunc(lineMouseAction);
	glutReshapeFunc(reShape);
	glutDisplayFunc(lineGraphDraw);
}



//PiChart
PiChart p1;
int piNumber = 0;
void setPiNumberMenu(int id)
{
	piNumber = id;
}
void picolorMenu(int id) {
	switch (id) {
	case 0:
		break;
	case 1:
		p1.updateColor({ 0.0,0.0, 1.0 }, piNumber);
		break;
	case 2:
		p1.updateColor({ 0.0,1.0, 0.0 }, piNumber);

		break;
	case 4:
		p1.updateColor({ 1.0,0.0, 0.0 }, piNumber);

		break;
	case 3:
		p1.updateColor({ 0.0,1.0, 1.0 }, piNumber);

		break;
	case 5:
		p1.updateColor({ 1.0,0.0, 1.0 }, piNumber);

		break;
	case 6:
		p1.updateColor({ 1.0,1.0, 0.0 }, piNumber);

		break;
	case 7:
		p1.updateColor({ 1.0,1.0, 1.0 }, piNumber);
		break;
	default:
		break;
	}
	piChartDraw();
}
void piChartInit()
{

	glClearColor(1, 1, 1, 1);
	glColor4f(1.0, 0.0, 0.0, 1.0f);
	glLineWidth(2.5);
	

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-2, 20, -2, 20);
	glMatrixMode(GL_MODELVIEW);

	p1.appendXData({ "FIrst", "Second", "Third" , "Fourth" });
	std::vector<float> yvalues = { (float)ypoints[0], (float)ypoints[1],(float)ypoints[2],(float)ypoints[3] };
	p1.appendyData(yvalues);
	p1.setColor({ {1.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, {1.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 1.0f} });

	int piId = glutCreateMenu(setPiNumberMenu);
	for (int i = 1; i <= p1.xData.size(); i++)
	{
		std::string str = p1.xData[i - 1];
		glutAddMenuEntry(str.c_str(), i-1);
	}
	glutAttachMenu(GLUT_LEFT_BUTTON);

	int colorId = glutCreateMenu(picolorMenu);
	glutAddMenuEntry("Red", 4);
	glutAddMenuEntry("Green", 2);
	glutAddMenuEntry("Blue", 1);
	glutAddMenuEntry("Black", 0);
	glutAddMenuEntry("Yellow", 6);
	glutAddMenuEntry("Cyan", 3);
	glutAddMenuEntry("Magenta", 5);
	glutAddMenuEntry("white", 7);
	glutAttachMenu(GLUT_LEFT_BUTTON);

	glutCreateMenu(main_menu);
	glutAddSubMenu("colors", colorId);

	glutAddSubMenu("Select Line", piId);
	glutAttachMenu(GLUT_LEFT_BUTTON);

}
void piChartDraw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	p1.draw();
	glFlush();
}
void piChartFinalInit()
{
	glutInitWindowPosition(800, 5);

	glutInitWindowSize(400, 400);
	window3 = glutCreateWindow("Pi Chart");
	piChartInit();
	//glutMouseFunc(lineMouseAction);
	glutReshapeFunc(reShape);
	glutDisplayFunc(piChartDraw);
}



//Bar2gGraph
Bar2DGraph b1;
void bar2dcolormenu(int id) {
	switch (id) {
	case 0:
		break;
	case 1:
		b1.setBarColor({ 0.0,0.0, 1.0 });
		break;
	case 2:
		b1.setBarColor({ 0.0,1.0, 0.0 });

		break;
	case 4:
		b1.setBarColor({ 1.0,0.0, 0.0 });

		break;
	case 3:
		b1.setBarColor({ 0.0,1.0, 1.0 });

		break;
	case 5:
		b1.setBarColor({ 1.0,0.0, 1.0 });

		break;
	case 6:
		b1.setBarColor({ 1.0,1.0, 0.0 });

		break;
	case 7:
		b1.setBarColor({ 1.0,1.0, 1.0 });
		break;
	default:
		break;
	}
	bar2dChartDraw();
}
void setWidthDiv(int id)
{
	b1.setBarWidth(id);
	bar2dChartDraw();
}
void bar2dMenus()
{
	int colorId = glutCreateMenu(bar2dcolormenu);
	glutAddMenuEntry("Red", 4);
	glutAddMenuEntry("Green", 2);
	glutAddMenuEntry("Blue", 1);
	glutAddMenuEntry("Black", 0);
	glutAddMenuEntry("Yellow", 6);
	glutAddMenuEntry("Cyan", 3);
	glutAddMenuEntry("Magenta", 5);
	glutAddMenuEntry("white", 7);
	glutAttachMenu(GLUT_LEFT_BUTTON);

	int setWidth = glutCreateMenu(setWidthDiv);
	for (int i = 1; i <= 3; i++)
	{
		std::string str = std::to_string(i);
		glutAddMenuEntry(str.c_str(), i);
	}
	glutAttachMenu(GLUT_LEFT_BUTTON);

	glutCreateMenu(main_menu);
	glutAddSubMenu("colors", colorId);
	glutAddSubMenu("Width", setWidth);
	glutAttachMenu(GLUT_LEFT_BUTTON);
}
void bar2dChartInit()
{
	glClearColor(1, 1, 1, 1);
	glColor4f(1.0, 0.0, 0.0, 1.0f);
	glLineWidth(2.5);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-2, 20, -2, 20);
	glMatrixMode(GL_MODELVIEW);
	
	b1.appendXData({ 1,2,3,4 });
	b1.appendYData(ypoints);
	b1.setBarColor({ 1.0f, 0.0f, 1.0f });
	bar2dMenus();
}
void bar2dChartDraw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	b1.draw();
	glFlush();
}
void bar2dFinalInit()
{
	glutInitWindowPosition(400, 405);

	glutInitWindowSize(400, 400);
	window4 = glutCreateWindow("Bar Chart 2d");
	bar2dChartInit();
	//glutMouseFunc(lineMouseAction);
	glutReshapeFunc(reShape2);
	glutDisplayFunc(bar2dChartDraw);
}

//BarGraph
Bar3dGraph b3;
void barGraph3dInit()
{
	b3.appendXData({ 1,2 });
	b3.appendZData({ 1,2 });
	b3.appendYData(ypoints);
	glClearColor(1, 1, 1, 1);
	glColor4f(1.0, 0.0, 0.0, 1.0f);
	glLineWidth(2.5);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, 1.0f, 0.1f, 100.0f);
	//gluPerspective(45.0, 1.0f, 0.1f, 10.0f);
	//glOrtho(-2.0, 20.0, -2.0, 20.0, -2.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
}
// the key states. These variables will be zero
//when no key is being presses
float deltaAngle = 0.0f;
float deltaMove = 0;
int xOrigin = -1;
// angle of rotation for the camera direction
float angle = 0.0f;

// actual vector representing the camera's direction
float lx = 0.0f, lz = -1.0f;

// XZ position of the camera
float x = 0.0f, z = 40.0f;

void computePos(float deltaMove) {

	x += deltaMove * lx * 0.1f;
	z += deltaMove * lz * 0.1f;
}

void barGraph3dDraw()
{
	if (deltaMove)
		computePos(deltaMove);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	// Set the camera
	gluLookAt(x, 20.0f, z,
			x + lx, 19.9f, z + lz,
		0.0f, 1.0f, 0.0f);
	b3.draw();
	glPopMatrix();
	glFlush();
}

void barMouseMove(int x, int y) {
	// this will only be true when the left button is down
	if (xOrigin >= 0) {

		// update deltaAngle
		deltaAngle = (x - xOrigin) * 0.001f;

		// update camera's direction
		lx = sin(angle + deltaAngle);
		lz = -cos(angle + deltaAngle);
	}
}

void barMouseButton(int button, int state, int x, int y) {

	// only start motion if the left button is pressed
	if (button == GLUT_LEFT_BUTTON) {

		// when the button is released
		if (state == GLUT_UP) {
			angle += deltaAngle;
			xOrigin = -1;
		}
		else {// state = GLUT_DOWN
			xOrigin = x;
		}
	}
}

void pressKey(int key, int xx, int yy) {
	switch (key) {
	case GLUT_KEY_LEFT:
		x = x + lz * 0.1f;
		z = z - lx * 0.1f;
		break;
	case GLUT_KEY_RIGHT:
		x = x - lz * 0.1f;
		z = z + lx * 0.1f;
		break;
	case GLUT_KEY_UP: deltaMove = 0.5f; break;
	case GLUT_KEY_DOWN: deltaMove = -0.5f; break;
	}
	barGraph3dDraw();
}
void releaseKey(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:
	case GLUT_KEY_DOWN: deltaMove = 0;break;
	}
	barGraph3dDraw();
}
void Bar3dGraphInit()
{
	glutInitWindowPosition(900, 405);

	glutInitWindowSize(400, 400);
	window2 = glutCreateWindow("Bar 3d Graph");

	glutSpecialFunc(pressKey);
	glutSpecialUpFunc(releaseKey);
	glutMouseFunc(barMouseButton);
	glutMotionFunc(barMouseMove);
	glutDisplayFunc(barGraph3dDraw);
	barGraph3dInit();
}
//
SurfacePlot s1;
float calc(float x)
{
	return  3*sin(x * 10.0) / (1.0 + x * x);
}

void surfacePlotInit()
{
	glClearColor(1, 1, 1, 1);
	glColor4f(1.0, 0.0, 0.0, 1.0f);
	glLineWidth(2.5);


	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 20, 0, 20);
	glMatrixMode(GL_MODELVIEW);

	s1.SetFunction(calc);
	s1.fillBuffer();
}
void surfacePlotDraw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	s1.draw();
	glFlush();
}
void special(int key, int x, int y) {
	s1.SpecialFunc(key, x, y);
	glutPostRedisplay();
}
void surfacePlotFinalInit()
{
	glutInitWindowPosition(5, 405);
	glutInitWindowSize(400, 400);
	window2 = glutCreateWindow("Surface2d Graph");
	GLenum glew_status = glewInit();

	if (GLEW_OK != glew_status) {
		fprintf(stderr, "Error: %s\n", glewGetErrorString(glew_status));
		return;
	}
	surfacePlotInit();
	glutSpecialFunc(special);
	glutDisplayFunc(surfacePlotDraw);

}



//Add Draw Functions here
void UpdateDraw()
{
	glutSetWindow(window1);
	glutPostRedisplay();
	
	glutSetWindow(window2);
	glutPostRedisplay();

	glutSetWindow(window3);
	std::vector<float> yvalues = { (float)ypoints[0], (float)ypoints[1],(float)ypoints[2],(float)ypoints[3] };
	p1.updateYData(yvalues);
	glutPostRedisplay();

	glutSetWindow(window4);
	glutPostRedisplay();
}

void DemoMouseAction(int button, int state, int x, int y)
{
	x = x - 200;
	y = 200 - y;
	std::cout << x << " " << y << "\n";

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (x > 0)
		{
			if (y > 0)
			{
				ypoints[0]++;
				l1->updateData(ypoints, 1);
				b3.updateYData(ypoints);
				b1.updateData(ypoints);

			}
			else
			{
				ypoints[3]++;
				l1->updateData(ypoints, 1);
				b3.updateYData(ypoints);
				b1.updateData(ypoints);

			}
		}
		else
		{
			if (y > 0)
			{
				ypoints[1]++;
				l1->updateData(ypoints, 1);
				b3.updateYData(ypoints);
				b1.updateData(ypoints);

			}
			else
			{
				ypoints[2]++;
				l1->updateData(ypoints, 1);
				b3.updateYData(ypoints);
				b1.updateData(ypoints);

			}
		}
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
	}
	UpdateDraw();
}

void DemoInit()
{
	glClearColor(1, 1, 1, 1);
	glColor4f(1.0, 0.0, 0.0, 1.0f);
	glLineWidth(2.5);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-5, 5, -5, 5);
	glMatrixMode(GL_MODELVIEW);
}
void DemoDraw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f);
	drawLine(0, -5, 0, 5);
	drawLine(-5, 0, 5, 0);
	glFlush();
}
void DemoFinalInit()
{
	glutInitWindowSize(500, 500);
	int windowId = glutCreateWindow("Main Screen");

	glutMouseFunc(DemoMouseAction);
	glutDisplayFunc(DemoDraw);
	DemoInit();
}