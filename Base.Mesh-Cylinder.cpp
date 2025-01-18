module;


#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>;
module Base.Mesh:Cylinder;

import Base.Point;
import Base.Type;

inline index_t GenerateCylinderMesh(std::vector<Point3D>& p_cylinderMeshVertixs,
                         CylinderMesh& p_cylinderMesh,
                         index_t p_beginIndex)
{
    index_t Index = p_beginIndex;
    double axisDirInc = (p_cylinderMesh.terminusCor-p_cylinderMesh.originCor) / p_cylinderMesh.axisNumber; // 轴向增量
    double thetaIncrement = 2 * M_PI / p_cylinderMesh.rNumber; // 极坐标角度增量
    //两层循环生成网格，第一层是轴向Z，第二层是每一个截面上的XY
    //计算结果直接就地构造Point3D对象，使用vector.emplace_back添加进vector
    //此处坐标号计算是有规律的，可能便于后续单元的生成
    for (index_t i = 0; i <= p_cylinderMesh.axisNumber; ++i)
    {
        for (index_t j = 0; j < p_cylinderMesh.rNumber; ++j)
        {
            p_cylinderMeshVertixs.emplace_back(Index,
                cos(j * thetaIncrement) * p_cylinderMesh.r,
                sin(j * thetaIncrement) * p_cylinderMesh.r,
                i * axisDirInc);
            ++Index;
        }
    }
    return Index;
};

inline index_t GenerateCylinderMesh(std::vector<Vertixs3D>& p_cylinderMeshVertixs,
    CylinderMesh& p_cylinderMesh,
    index_t p_beginIndex)
{
    index_t Index = p_beginIndex;
    double axisDirInc = (p_cylinderMesh.terminusCor - p_cylinderMesh.originCor) / p_cylinderMesh.axisNumber; // 轴向增量
    double thetaIncrement = 2 * M_PI / p_cylinderMesh.rNumber; // 极坐标角度增量
    //两层循环生成网格，第一层是轴向Z，第二层是每一个截面上的XY
    //计算结果直接就地构造Point3D对象，使用vector.emplace_back添加进vector
    //此处坐标号计算是有规律的，可能便于后续单元的生成
    for (index_t i = 0; i <= p_cylinderMesh.axisNumber; ++i)
    {
        for (index_t j = 0; j < p_cylinderMesh.rNumber; ++j)
        {
            p_cylinderMeshVertixs.emplace_back(Index,
                cos(j * thetaIncrement) * p_cylinderMesh.r,
                sin(j * thetaIncrement) * p_cylinderMesh.r,
                i * axisDirInc,
                i,
                j,
                NULL);
            ++Index;
        }
    }
    return Index;
};