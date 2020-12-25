#pragma once
#include <gl/glew.h>
#include<gl/glut.h>
#include <iostream>
#include <vector>
#include "graph.h"

void reShape(int width, int height);
void reShape2(int width, int height);

void DemoMouseAction(int button, int state, int x, int y);
void DemoInit();
void DemoDraw();
void DemoFinalInit();

void piChartInit();
void piChartFinalInit();
void piChartDraw();

void bar2dMenus();
void bar2dChartInit();
void bar2dChartDraw();
void bar2dFinalInit();


void setLineGraph(int _nol);
void lineGraphInit();
void lineGraphDraw();
void lineMouseAction(int button, int state, int x, int y);
void LineGraphInit();

void pressKey(int key, int xx, int yy);
void releaseKey(int key, int x, int y);
void Bar3dGraphInit();
void barGraph3dInit();
void barGraph3dDraw();
void barMouseMove(int x, int y);
void barMouseButton(int button, int state, int x, int y);

float calc(float x);
void special(int key, int x, int y);
void surfacePlotInit();
void surfacePlotDraw();
void surfacePlotFinalInit();