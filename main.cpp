
#include <vector>

import Base.Point;
import Base.Mesh;
import Base.Type;

int main()
{
    // 螺纹参数设置
    constexpr double r_exter = 6;
    constexpr double r_inter = 4;
    constexpr double P = 1.75;
    constexpr double origin = 0; //暂时只支持Z向圆柱
    constexpr index_t axisNumber = 30;
    constexpr index_t rNumber = 80;
    constexpr index_t radialNumber = 5;
  
    // 根据给定螺纹参数生成螺纹节点
    std::vector<Vertixs3D> Vertixs;
    ScrewThreadMesh screwThreadMesh{r_exter,origin,origin + P,rNumber,axisNumber,P};
    index_t GBScrewEndIndex = GenerateGBScrewThreadMesh(Vertixs, screwThreadMesh);

    InterMesh interMesh{ r_exter,r_inter,origin,origin + P,P,rNumber,axisNumber,radialNumber};
    index_t InterEndIndex = GenerateInterMeshVertixs(Vertixs, interMesh, GBScrewEndIndex);
    PrintVertixs3D(Vertixs,"apdl");
    std::vector<C3D8> elements;
    GenerateElements(Vertixs, interMesh,elements);
    PrintElements(elements,"apdl");
    return 0;
}