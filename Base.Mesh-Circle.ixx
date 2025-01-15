export module Base.Mesh:Circle;

import <vector>;
import Base.Point;

// Բ�������
export struct CircleMesh
{
	double r;//Բ�뾶
	int rNumber; //Բ�뾶��������
};

export void GenerateCircleMesh(std::vector<Point2D>& p_circleMeshVertixs, CircleMesh& p_circleMesh);