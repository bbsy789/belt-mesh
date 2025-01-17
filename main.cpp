
#include <vector>

import Base.Point;
import Base.Mesh;

int main()
{
    // 螺纹参数设置
    constexpr double r = 6;
    constexpr int rNumber = 80;
    constexpr double P = 1.75;
    constexpr double origin = 0; //暂时只支持Z向圆柱
    constexpr int axisNumber = 30;

    

    // 根据给定螺纹参数生成螺纹节点
    std::vector<Point3D> screwThreadMeshVertixs;
    ScrewThreadMesh screwThreadMesh{ r,rNumber,origin,origin + P,axisNumber,P};
    //Generate90DegreeScrewThreadMesh(screwThreadMeshVertixs,screwThreadMesh);
    GenerateGBScrewThreadMesh(screwThreadMeshVertixs, screwThreadMesh);
    //std::cout << "ScrewThread:\n";
    // for(auto &i:vertixs3D)
    // {
    //     std::cout << "index:" << i.index << "\nx = " << i.x << ",y = " << i.y << ",z = " << i.z << "\n";
    // }
    Print3D(screwThreadMeshVertixs,"table");
    return 0;
}