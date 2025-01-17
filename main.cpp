
#include <vector>

import Base.Point;
import Base.Mesh;

int main()
{
    // 螺纹参数设置
    constexpr double r_exter = 6;
    constexpr double r_inter = 4;
    constexpr int rNumber = 80;
    constexpr double P = 1.75;
    constexpr double origin = 0; //暂时只支持Z向圆柱
    constexpr int axisNumber = 30;
    constexpr int radialNumber = 2;
  
    // 根据给定螺纹参数生成螺纹节点
    std::vector<Point3D> screwThreadMeshVertixs;
    ScrewThreadMesh screwThreadMesh{ r_exter,rNumber,origin,origin + P,axisNumber,P};
    //Generate90DegreeScrewThreadMesh(screwThreadMeshVertixs,screwThreadMesh);
    int GBScrewEndIndex = GenerateGBScrewThreadMesh(screwThreadMeshVertixs, screwThreadMesh);
    //std::cout << "ScrewThread:\n";
    // for(auto &i:vertixs3D)
    // {
    //     std::cout << "index:" << i.index << "\nx = " << i.x << ",y = " << i.y << ",z = " << i.z << "\n";
    // }
    Print3D(screwThreadMeshVertixs,"table");

    std::vector<Point3D> interMeshVertixs;
    InterMesh interMesh{ r_exter,r_inter,origin,origin + P,P,rNumber,axisNumber,radialNumber};
    int InterEndIndex = GenerateInterMeshVertixs(interMeshVertixs, interMesh, GBScrewEndIndex);
    Print3D(interMeshVertixs,"table");
    //创建内圈节点
    constexpr double r_dist = r_exter;
    std::vector<Point3D> interCylinerVertixs;
    CylinderMesh interCylinderMesh{ r_inter,rNumber,origin,origin + P,axisNumber};
    GenerateCylinderMesh(interCylinerVertixs, interCylinderMesh, InterEndIndex);
    Print3D(interCylinerVertixs,"table");
    return 0;
}