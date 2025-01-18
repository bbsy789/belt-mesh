export module Base.Mesh:Inter;

import <vector>;
import Base.Point;
import Base.Type;
export struct InterMesh
{
    double r_exter;//公称半径
    double r_inter;//内部圆柱半径

    double originCor; //原点坐标
    double terminusCor; //终点坐标
    double p; //螺纹导程

    index_t radiusDirectionNumber; //端面划分数量
    index_t axisDirectionNumber; //轴向划分数量
    index_t radialDirectionNumber; // 径向划分数量
};

// 生成中间节点
export
inline index_t GenerateInterMeshVertixs(std::vector<Point3D>& p_interMeshVertixs, InterMesh& p_interMesh, index_t p_beginIndex = 1);

// 生成中间节点
export
inline index_t GenerateInterMeshVertixs(std::vector<Vertixs3D>& p_interMeshVertixs, InterMesh& p_interMesh, index_t p_beginIndex = 1);

