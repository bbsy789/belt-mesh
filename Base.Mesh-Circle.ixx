export module Base.Mesh:Circle;

import <vector>;
import Base.Point;

// 圆网格参数
export struct CircleMesh
{
	double r;//圆半径
	int rNumber; //圆半径划分数量
};

export void GenerateCircleMesh(std::vector<Point2D>& p_circleMeshVertixs, CircleMesh& p_circleMesh);