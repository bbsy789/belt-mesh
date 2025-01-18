export module Base.Mesh:Element;

import Base.Type;
import :Inter;
import <iostream>;
// 六面体单元类
export class C3D8
{
public:
	C3D8(index_t p_Index,index_t p1Index, index_t p2Index, index_t p3Index, index_t p4Index, index_t p5Index, index_t p6Index, index_t p7Index, index_t p8Index)
	{
        this->Index = p_Index;
		this->p1Index = p1Index;
		this->p2Index = p2Index;
		this->p3Index = p3Index;
		this->p4Index = p4Index;
		this->p5Index = p5Index;
		this->p6Index = p6Index;
		this->p7Index = p7Index;
		this->p8Index = p8Index;
	}
	C3D8(InterMesh& p_interMesh,index_t p_Index)
	{

	}
	void Print() const
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
private:
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

// 实现结构化映射网格生成函数