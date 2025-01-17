export module Base.Mesh:Cylinder;

import <vector>;
import Base.Point;

// Բ���������
export struct CylinderMesh
{
    double r;//Բ���뾶
    int rNumber; //Բ���뾶��������
    double originCor; //ԭ������
    double terminusCor; //�յ�����
    int axisNumber; //���򻮷�����
};


export int GenerateCylinderMesh(std::vector<Point3D>& p_cylinderMeshVertixs,
    CylinderMesh& p_cylinderMesh, int p_beginIndex = 1);