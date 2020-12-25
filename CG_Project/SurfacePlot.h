#pragma once
#include <GL/glew.h>
#include <GL/glut.h>

class SurfacePlot {
	float (*fun_ptr)(float) = NULL;
	bool assetDraw = false;
	int mode = 0;
	float xPos = 0;
	float scale = 1;
public:
	void SpecialFunc(int key, int x, int y);
	GLuint vbo;
	GLuint lbo;
	void SetFunction(float (*f)(float));
	float function(float x);
	void fillBuffer();
	void draw();
}; 

