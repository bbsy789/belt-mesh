export module Base.Mesh:Inter;

import <vector>;
import Base.Point;

export struct InterMesh
{
    double r_exter;//公称半径
    double r_inter;//内部圆柱半径

    double originCor; //原点坐标
    double terminusCor; //终点坐标
    double p; //螺纹导程

    int radiusDirectionNumber; //端面划分数量
    int axisDirectionNumber; //轴向划分数量
    int radialDirectionNumber; // 径向划分数量
};

// 径向分层次数决定内部节点到中心的径向距离，剩下的就只需要知道
export int GenerateInterMeshVertixs(std::vector<Point3D>& p_interMeshVertixs, InterMesh& p_interMesh, int p_beginIndex = 1);

