export module Base.Mesh:Cylinder;

import <vector>;
import Base.Point;

// 圆柱网格参数
export struct CylinderMesh
{
    CylinderMesh(double p_r, int p_rNumber, double p_originCor, double p_terminusCor, int p_axisNumber)
        :r{ p_r }, rNumber{ p_rNumber }, originCor{ p_originCor }, terminusCor{ p_terminusCor }, axisNumber{ p_axisNumber }
    {}
    double r;//圆柱半径
    int rNumber; //圆柱半径划分数量
    double originCor; //原点坐标
    double terminusCor; //终点坐标
    int axisNumber; //轴向划分数量
};


export void GenerateCylinderMesh(std::vector<Point3D>& p_cylinderMeshVertixs,
    CylinderMesh& p_cylinderMesh,
    double p_p);

// 对原始网格节点进行坐标修改
// 参数：std::vector<Point3D>& vertixs 是最外层圆柱节点坐标集
export void ModifyForCylinderMesh(std::vector<Point3D>& p_cylinderMeshVertixs,
    CylinderMesh& m,
    double p_p);