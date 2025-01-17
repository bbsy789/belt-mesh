module;


#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>;
module Base.Mesh:Cylinder;


import Base.Point;

int GenerateCylinderMesh(std::vector<Point3D>& p_cylinderMeshVertixs,
                         CylinderMesh& p_cylinderMesh,
                         int p_beginIndex)

{
    int Index = p_beginIndex;
    double axisDirInc = (p_cylinderMesh.terminusCor-p_cylinderMesh.originCor) / p_cylinderMesh.axisNumber; // ��������
    double thetaIncrement = 2 * M_PI / p_cylinderMesh.rNumber; // ������Ƕ�����
    //����ѭ���������񣬵�һ��������Z���ڶ�����ÿһ�������ϵ�XY
    //������ֱ�Ӿ͵ع���Point3D����ʹ��vector.emplace_back��ӽ�vector
    //�˴�����ż������й��ɵģ����ܱ��ں�����Ԫ������
    for (int i = 0; i <= p_cylinderMesh.axisNumber; ++i)
    {
        for (int j = 0; j < p_cylinderMesh.rNumber; ++j)
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
