export module Base.Mesh:Element;

import Base.Point;
import Base.Type;
import :Inter;
import <iostream>;
import <vector>;
// 六面体单元类
export struct C3D8
{
	void PrintElement() const
	{
		std::cout << Index   << "," <<
					 p1Index << "," << 
			         p2Index << "," <<
					 p3Index << "," <<
					 p4Index << "," <<
					 p5Index << "," <<
					 p6Index << "," <<
					 p7Index << "," <<
					 p8Index << "\n";
	}
	index_t Index;
	index_t p1Index;
	index_t p2Index;
	index_t p3Index;
	index_t p4Index;
	index_t p5Index;
	index_t p6Index;
	index_t p7Index;
	index_t p8Index;
};

//从节点数组中根据IJK获得节点索引
export inline index_t GetVertixIndex(std::vector<Vertixs3D>& p_Vertixs, index_t p_i, index_t p_j, index_t p_k);
//根据网格划分数据获得节点索引
export inline index_t GetVertixIndex(InterMesh p_interMesh, index_t p_i, index_t p_j, index_t p_k);


// 实现结构化映射网格生成函数
export inline index_t GenerateElements(std::vector<Vertixs3D>& p_Vertixs, InterMesh& p_interMesh, std::vector<C3D8>& p_Elements);

