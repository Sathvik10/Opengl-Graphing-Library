#pragma once
#include <GL/GL.h>

void drawLine(GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2);
void drawLine(int x1, int y1, int z1, int x2, int y2, int z2);

void drawLine(GLint x1, GLint y1, GLint x2, GLint y2);
void drawLine(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
void draw2DBar(GLfloat x, GLfloat y, int width);
void cuboid(GLfloat sizeX, GLfloat sizeY, GLfloat sizeZ, std::vector<GLfloat> cubeC, std::vector<GLfloat> edgeC);
