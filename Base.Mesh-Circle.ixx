export module Base.Mesh:Circle;

import <vector>;
import Base.Point;
import Base.Type;
// Բ�������
export struct CircleMesh
{
	double r;//Բ�뾶
	std::size_t rNumber; //Բ�뾶��������
};

export index_t GenerateCircleMesh(std::vector<Point2D>& p_circleMeshVertixs
								, CircleMesh& p_circleMesh,
								index_t p_beginIndex = 1);