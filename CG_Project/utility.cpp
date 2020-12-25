#include <vector>
#include <gl/glut.h>
#include "utility.h"

void drawLine(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2)
{
	glBegin(GL_LINES);
		glVertex2f(x1, y1);
		glVertex2f(x2, y2);
	glEnd();
}
void drawLine(int x1, int y1, int z1, int x2, int y2, int z2)
{
	glBegin(GL_LINES);
	glVertex3i(x1, y1, z1);
	glVertex3i(x2, y2, z2);
	glEnd();
}
void drawLine(GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2,  GLfloat z2)
{
	glBegin(GL_LINES);
	glVertex3f(x1, y1, z1);
	glVertex3f(x2, y2, z2);
	glEnd();
}


void drawLine(GLint x1, GLint y1, GLint x2, GLint y2)
{
	glBegin(GL_LINES);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glEnd();
}

void draw2DBar(GLfloat x, GLfloat y, int width)
{
	glBegin(GL_POLYGON);
		glVertex2i(x - ((float)width/2), 0);
		glVertex2i(x + ((float)width / 2), 0);
		glVertex2i(x + ((float)width / 2), y);
		glVertex2i(x - ((float)width / 2), y);
	glEnd();
}
void cuboid(GLfloat sizeX, GLfloat sizeY, GLfloat sizeZ, std::vector<GLfloat> cubeC,std::vector<GLfloat> edgeC)
{
	static GLfloat n[6][3] =
	{
		{-1.0, 0.0, 0.0},
		{0.0, 1.0, 0.0},
		{1.0, 0.0, 0.0},
		{0.0, -1.0, 0.0},
		{0.0, 0.0, 1.0},
		{0.0, 0.0, -1.0}
	};
	static GLint faces[6][4] =
	{
		{0, 1, 2, 3},
		{3, 2, 6, 7},
		{7, 6, 5, 4},
		{4, 5, 1, 0},
		{5, 6, 2, 1},
		{7, 4, 0, 3}
	};
	GLfloat v[8][3];
	GLint i;

	v[0][0] = v[1][0] = v[2][0] = v[3][0] = -sizeX / 2;
	v[4][0] = v[5][0] = v[6][0] = v[7][0] = sizeX / 2;
	v[0][1] = v[1][1] = v[4][1] = v[5][1] = -sizeY / 2;
	v[2][1] = v[3][1] = v[6][1] = v[7][1] = sizeY / 2;
	v[0][2] = v[3][2] = v[4][2] = v[7][2] = -sizeZ / 2;
	v[1][2] = v[2][2] = v[5][2] = v[6][2] = sizeZ / 2;
	glColor3f(cubeC[0], cubeC[1], cubeC[2]);
	for (i = 5; i >= 0; i--) {
		glBegin(GL_POLYGON);
		glNormal3fv(&n[i][0]);
		glVertex3fv(&v[faces[i][0]][0]);
		glVertex3fv(&v[faces[i][1]][0]);
		glVertex3fv(&v[faces[i][2]][0]);
		glVertex3fv(&v[faces[i][3]][0]);
		glEnd();
	}
	glColor3f(edgeC[1], edgeC[1], edgeC[1]);
	for (i = 5; i >= 0; i--) {
		glBegin(GL_LINE_LOOP);
		glVertex3fv(&v[faces[i][0]][0]);
		glVertex3fv(&v[faces[i][1]][0]);
		glVertex3fv(&v[faces[i][2]][0]);
		glVertex3fv(&v[faces[i][3]][0]);
		glEnd();
	}
}