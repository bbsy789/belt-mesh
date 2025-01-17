export module Base.Mesh:Cylinder;

import <vector>;
import Base.Point;

// 圆柱网格参数
export struct CylinderMesh
{
    double r;//圆柱半径
    int rNumber; //圆柱半径划分数量
    double originCor; //原点坐标
    double terminusCor; //终点坐标
    int axisNumber; //轴向划分数量
};


export int GenerateCylinderMesh(std::vector<Point3D>& p_cylinderMeshVertixs,
    CylinderMesh& p_cylinderMesh, int p_beginIndex = 1);