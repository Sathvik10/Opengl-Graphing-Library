#include <Gl/glut.h>
#include <vector>
#include "graph.h"
#include "utility.h"


void Graph::setXMax(int _xMax)
{
	xMax = _xMax;
}

void Graph::setYMax(int _yMax)
{
	if (_yMax % yDivision != 0)
		yMax = _yMax + (yDivision - (_yMax % yDivision));
	else
		yMax = _yMax;
}

void Graph::setYDivision(int _yDiv)
{
	yDivision = _yDiv;
	if (yMax % yDivision != 0)
		yMax = yMax + (yDivision - (yMax % yDivision));
}

void Graph::setCompact(bool _com)
{
	compact = _com;
}

void Graph::appendXData(std::vector<int> x)
{
	xData = x;
}


