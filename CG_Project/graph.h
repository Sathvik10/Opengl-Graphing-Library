#pragma once
#include <string>

class Graph {
protected:
	std::vector<int> xData;
	int xMax = 16;
	int yMax = 16;
	float xScale = 0;
	float yScale = 0;
	int yDivision = 4;
	int yDataMax = 0;
	float yMarkDiv = 0.0f;
	bool compact = true;
	std::string xLabel = "X-Label";
	std::string yLabel = "Y-Label";
public:
	virtual void draw() = 0;
	void setYDivision(int _yDiv);
	void setCompact(bool _com);
	void appendXData(std::vector<int> x);
	void setXMax(int _xMax);
	void setYMax(int _yMax);
};


class LineGraph : public Graph{
private:
	std::vector<std::vector<int>> yData;
	std::vector<std::vector<GLfloat>> lineColor;
	int numberOfLines;
public:
	LineGraph(int _nol)
	{
		numberOfLines = _nol;
		std::vector<std::vector<int>> temp(_nol);
		yData = temp;
		std::vector<GLfloat> defCol = { 1.0f, 0.0f,0.0f };
		std::vector<std::vector <GLfloat>> tempc(_nol, defCol);
		lineColor = tempc;
	}
	//Virtual Functions
	void draw();
	void computeScale();
	int getLineNumber();
	void setYDivision(int _yDiv);
	void setLineColor(std::vector <GLfloat> rgb, int _nol);
	void appendYData(std::vector<int> y, int _nol);
	void updateData(std::vector<int> y, int _nol);

};


class Bar2DGraph {
private:
	std::vector<int> xData;
	std::vector<int> yData;
	std::vector<GLfloat> lineColor;
	int xMax = 16;
	int yMax = 16;
	float xScale = 0;
	float yScale = 0;
	int yDivision = 4;
	int barWidth;
	int yDataMax = 0;
	float yMarkDiv = 0.0f;
	bool compact = true;
	std::string xLabel = "X-Label";
	std::string yLabel = "Y-Label";
public:
	Bar2DGraph()
	{
		std::vector<GLfloat> defCol = { 1.0f, 1.0f,0.0f };
		lineColor = defCol;
		barWidth = 2;
	}
	void openglDisplay();
	void setBarWidth(int _width);
	void setBarColor(std::vector <GLfloat> rgb);
	void setYDivision(int _yDiv);
	void setCompact(bool _com);
	void appendYData(std::vector<int> y);
	void appendXData(std::vector<int> x);
	void updateData(std::vector<int> y);
	void draw();
	void setXMax(int _xMax);
	void setYMax(int _yMax);
	void computeScale();
};


class Bar3dGraph {
public:
	std::vector<int> xData;
	std::vector<int> yData;
	std::vector<int> zData;
	float lx = 0.0f, lz = -1.0f;

	// XZ position of the camera
	float x = 0.0f, z = 2.0f;
	std::vector<GLfloat> barColor = {1.0f, 1.0f, 0.0f};
	std::vector<GLfloat> edgeColor = { 0.0f, 0.0f, 0.0f };
	int xMax = 16;
	int yMax = 16;
	int zMax = 16;
	float yScale = 0;
	int zDivision = 5;
	int xDivision = 5;
	int yDivision = 4;

	float cubeWidth = 2.0f;
	int barWidth;
	int yDataMax = 0;
	float yMarkDiv = 0.0f;
	bool compact = true;
	std::string xLabel = "X-Label";
	std::string yLabel = "Y-Label";
	bool assertDraw = false;
public:
	void setBarWidth(float _width);
	void setEdgeColor(std::vector <GLfloat> rgb);
	void setBarColor(std::vector <GLfloat> rgb);
	void appendYData(std::vector<int> y);
	void appendXData(std::vector<int> x);
	void appendZData(std::vector<int> z);

	void updateYData(std::vector<int> z);

	//void updateData(std::vector<int> y);
	void draw();
	void drawBackGround();
	void drawGridLines();
	void drawCubes(int x, int y, int z);
	//void setXMax(int _xMax);
	//void setYMax(int _yMax);
	void computeScale();
};