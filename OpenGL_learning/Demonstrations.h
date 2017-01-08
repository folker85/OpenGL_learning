#pragma once

#include <GLFW/glfw3.h>

namespace demo
{
	struct Data
	{
		GLfloat x, y, z;
	};

	void gaussianDemo(float sigma);
	void draw2DHeatMap(const Data* data, int num_points);

}
