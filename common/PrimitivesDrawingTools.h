#pragma once

#include "Vertex.h"

namespace drawingTools
{
	void drawPoint(const Vertex& v, GLfloat point_size = 1.0f);
	void drawLineSegment(const Vertex& v1, const Vertex& v2, GLfloat line_width = 1.0f);
	void drawTriangle(const Vertex& v1, const Vertex& v2, const Vertex& v3);

	void drawGrid(GLfloat width, GLfloat height, GLfloat grid_width);
}
