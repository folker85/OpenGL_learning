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
}
