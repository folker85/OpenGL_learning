#include "PrimitivesDrawingTools.h"

namespace drawingTools
{
	void drawPoint(const Vertex& v, GLfloat point_size)
	{
		glPointSize(point_size);

		glBegin(GL_POINTS);
		glColor4f(v.r, v.g, v.b, v.a);
		glVertex3f(v.x, v.y, v.z);
		glEnd();
	}

	void drawLineSegment(const Vertex& v1, const Vertex& v2, GLfloat line_width)
	{
		glLineWidth(line_width);

		glBegin(GL_LINES);
		glColor4f(v1.r, v1.g, v1.b, v1.a);
		glVertex3f(v1.x, v1.y, v1.z);
		glColor4f(v2.r, v2.g, v2.b, v2.a);
		glVertex3f(v2.x, v2.y, v2.z);
		glEnd();
	}

	void drawTriangle(const Vertex& v1, const Vertex& v2, const Vertex& v3)
	{
		glBegin(GL_TRIANGLES);
		glColor4f(v1.r, v1.g, v1.b, v1.a);
		glVertex3f(v1.x, v1.y, v1.z);
		glColor4f(v2.r, v2.g, v2.b, v2.a);
		glVertex3f(v2.x, v2.y, v2.z);
		glColor4f(v3.r, v3.g, v3.b, v3.a);
		glVertex3f(v3.x, v3.y, v3.z);
		glEnd();
	}

	void drawGrid(GLfloat width, GLfloat height, GLfloat grid_width)
	{
		//horizontal lines
		for (float i = -height; i < height; i += grid_width)
		{
			Vertex v1 = { -width, i, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f };
			Vertex v2 = { width, i, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f };
			drawLineSegment(v1, v2);
		}
		//vertical lines
		for (float i = -width; i < width; i += grid_width)
		{
			Vertex v1 = { i, -height, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f };
			Vertex v2 = { i, height, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f };
			drawLineSegment(v1, v2);
		}
	}
}
