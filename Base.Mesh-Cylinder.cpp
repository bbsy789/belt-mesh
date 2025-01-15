module;


#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>;
module Base.Mesh:Cylinder;


import Base.Point;

void GenerateCylinderMesh(std::vector<Point3D>& p_cylinderMeshVertixs,
    CylinderMesh& p_cylinderMesh,
    double p_p)

{
    double axisDirInc = p_p / p_cylinderMesh.axisNumber; // ��������
    double thetaIncrement = 2 * M_PI / p_cylinderMesh.rNumber; // ������Ƕ�����
    //����ѭ���������񣬵�һ��������Z���ڶ�����ÿһ�������ϵ�XY
    //������ֱ�Ӿ͵ع���Point3D����ʹ��vector.emplace_back��ӽ�vector
    //�˴�����ż������й��ɵģ����ܱ��ں�����Ԫ������
    for (int i = 0; i < p_cylinderMesh.axisNumber; ++i)
    {
        for (int j = 0; j < p_cylinderMesh.rNumber; ++j)
        {
            p_cylinderMeshVertixs.emplace_back(i * p_cylinderMesh.rNumber + j + 1,
                cos(j * thetaIncrement) * p_cylinderMesh.r,
                sin(j * thetaIncrement) * p_cylinderMesh.r,
                i * axisDirInc);
        }
    }
};
