export module Base.Mesh:ScrewThread;

import Base.Point;
import <vector>;

// 螺纹网格参数
export struct ScrewThreadMesh
{
    double r;//圆柱半径
    int rNumber; //圆柱半径划分数量
    double originCor; //原点坐标
    double terminusCor; //终点坐标
    int axisNumber; //轴向划分数量
    double p; //螺纹导程
};

// 生成90度外螺纹节点网格
export
void Generate90DegreeScrewThreadMesh(std::vector<Point3D>& p_screwThreadMeshVertixs,
    ScrewThreadMesh& p_screwThreadMesh);

// 生成GB普通螺纹节点网格
export
void GenerateGBScrewThreadMesh(std::vector<Point3D>& p_screwThreadMeshVertixs,
    ScrewThreadMesh& p_screwThreadMesh);