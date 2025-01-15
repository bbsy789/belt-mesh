module;


#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>;
module Base.Mesh:Circle;

import Base.Point;



void GenerateCircleMesh(std::vector<Point2D>& p_circleMeshVertixs, CircleMesh& p_circleMesh)
{
	double thetaIncrement = 2 * M_PI / p_circleMesh.rNumber;
	for (int i = 0; i < p_circleMesh.rNumber + 1; ++i)
	{
		p_circleMeshVertixs.emplace_back(i + 1, cos(i * thetaIncrement) * p_circleMesh.r, sin(i * thetaIncrement) * p_circleMesh.r);
	}
}
