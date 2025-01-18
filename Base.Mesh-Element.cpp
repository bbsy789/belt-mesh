module;

module Base.Mesh:Element;

import <vector>;
import Base.Point;
import Base.Type;
import :Inter;

inline index_t GetVertixIndex(std::vector<Vertixs3D>& p_Vertixs, index_t p_i, index_t p_j, index_t p_k)
{
	auto condition([](index_t i, index_t j, index_t k) {
		return [=](const Vertixs3D& vertix) {
			return vertix.index == i && vertix.index == j && vertix.index == k;
			};
		});
	auto found_vertix ( std::find_if(p_Vertixs.begin(), p_Vertixs.end(), condition(p_i, p_j, p_k)));
    return found_vertix != p_Vertixs.end() ? found_vertix->index : -1;
}

inline index_t GetVertixIndex(InterMesh p_interMesh,index_t p_i, index_t p_j, index_t p_k)
{
	return 1+p_j+p_i*p_interMesh.radiusDirectionNumber+p_k*(p_interMesh.axisDirectionNumber+1)*p_interMesh.radiusDirectionNumber;
}

inline index_t GenerateElements(std::vector<Vertixs3D>& p_Vertixs, InterMesh& p_interMesh,std::vector<C3D8>& p_Elements)
{
	index_t i = 0;
	index_t j = 0;
	index_t jPlus1 = 0;
	index_t k = 0;
	index_t elementsIndex = 1;
	p_Elements.reserve(p_Vertixs.size());
	while (k < p_interMesh.radialDirectionNumber)
	{
		i = 0; // 重置 i 在每次 k循环开始时
		while (i < p_interMesh.axisDirectionNumber)
		{
			j = 0; // 重置 j 在每次 i循环开始时
			while (j < p_interMesh.radiusDirectionNumber)
			{
				if (j == p_interMesh.radiusDirectionNumber - 1)
				{
					jPlus1 = 0;
				}
				else
				{
					jPlus1 = j + 1;
				}
				p_Elements.emplace_back(C3D8{
					elementsIndex,
					GetVertixIndex(p_interMesh, i, j, k),
					GetVertixIndex(p_interMesh, i, jPlus1, k),
					GetVertixIndex(p_interMesh, i + 1, jPlus1, k),
					GetVertixIndex(p_interMesh, i + 1, j, k),
					GetVertixIndex(p_interMesh, i, j, k + 1),
					GetVertixIndex(p_interMesh, i, jPlus1, k + 1),
					GetVertixIndex(p_interMesh, i + 1, jPlus1, k + 1),
					GetVertixIndex(p_interMesh, i + 1, j, k + 1)
				});
				++elementsIndex;
				++j;
			}
			++i;
		}
		++k;
	}
	return elementsIndex;
}
