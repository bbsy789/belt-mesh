module;


#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>;
module Base.Mesh:Circle;

import Base.Point;
import Base.Type;

index_t GenerateCircleMesh(std::vector<Point2D>& p_circleMeshVertixs, CircleMesh& p_circleMesh, index_t p_beginIndex)
{
	index_t Index = p_beginIndex; 
	double thetaIncrement = 2 * M_PI / p_circleMesh.rNumber;
	for (int i = 0; i < p_circleMesh.rNumber; ++i)
	{
		p_circleMeshVertixs.emplace_back(Index, cos(i * thetaIncrement) * p_circleMesh.r, sin(i * thetaIncrement) * p_circleMesh.r);
		++Index;
	}
	return Index;
}
