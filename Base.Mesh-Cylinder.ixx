export module Base.Mesh:Cylinder;

import <vector>;
import Base.Point;
import Base.Type;
// 圆柱网格参数
export struct CylinderMesh
{
    double r;//圆柱半径
    double originCor; //原点坐标
    double terminusCor; //终点坐标
    index_t rNumber; //圆柱半径划分数量
    index_t axisNumber; //轴向划分数量
};
export
inline index_t GenerateCylinderMesh(std::vector<Point3D>& p_cylinderMeshVertixs,
    CylinderMesh& p_cylinderMesh, index_t p_beginIndex = 1);

export
inline index_t GenerateCylinderMesh(std::vector<Vertixs3D>& p_cylinderMeshVertixs,
    CylinderMesh& p_cylinderMesh, index_t p_beginIndex = 1);