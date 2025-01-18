export module Base.Mesh:Circle;

import <vector>;
import Base.Point;
import Base.Type;
// 圆网格参数
export struct CircleMesh
{
	double r;//圆半径
	std::size_t rNumber; //圆半径划分数量
};

export index_t GenerateCircleMesh(std::vector<Point2D>& p_circleMeshVertixs
								, CircleMesh& p_circleMesh,
								index_t p_beginIndex = 1);