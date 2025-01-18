
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
    std::vector<Vertixs3D> screwThreadMeshVertixs;
    ScrewThreadMesh screwThreadMesh{r_exter,origin,origin + P,rNumber,axisNumber,P};
    //Generate90DegreeScrewThreadMesh(screwThreadMeshVertixs,screwThreadMesh);
    index_t GBScrewEndIndex = GenerateGBScrewThreadMesh(screwThreadMeshVertixs, screwThreadMesh);
    //std::cout << "ScrewThread:\n";
    // for(auto &i:vertixs3D)
    // {
    //     std::cout << "index:" << i.index << "\nx = " << i.x << ",y = " << i.y << ",z = " << i.z << "\n";
    // }
    PrintVertixs3D(screwThreadMeshVertixs,"table");

    std::vector<Vertixs3D> interMeshVertixs;
    InterMesh interMesh{ r_exter,r_inter,origin,origin + P,P,rNumber,axisNumber,radialNumber};
    index_t InterEndIndex = GenerateInterMeshVertixs(interMeshVertixs, interMesh, GBScrewEndIndex);
    PrintVertixs3D(interMeshVertixs,"table");
    //创建内圈节点
    //constexpr double r_dist = r_exter;
    //std::vector<Point3D> interCylinerVertixs;
    //CylinderMesh interCylinderMesh{ r_inter,origin,origin + P,rNumber,axisNumber};
    //GenerateCylinderMesh(interCylinerVertixs, interCylinderMesh, InterEndIndex);
    //Print3D(interCylinerVertixs,"table");
    return 0;
}