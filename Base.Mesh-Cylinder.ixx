export module Base.Mesh:Cylinder;

import <vector>;
import Base.Point;

// Բ���������
export struct CylinderMesh
{
    CylinderMesh(double p_r, int p_rNumber, double p_originCor, double p_terminusCor, int p_axisNumber)
        :r{ p_r }, rNumber{ p_rNumber }, originCor{ p_originCor }, terminusCor{ p_terminusCor }, axisNumber{ p_axisNumber }
    {}
    double r;//Բ���뾶
    int rNumber; //Բ���뾶��������
    double originCor; //ԭ������
    double terminusCor; //�յ�����
    int axisNumber; //���򻮷�����
};


export void GenerateCylinderMesh(std::vector<Point3D>& p_cylinderMeshVertixs,
    CylinderMesh& p_cylinderMesh,
    double p_p);

// ��ԭʼ����ڵ���������޸�
// ������std::vector<Point3D>& vertixs �������Բ���ڵ����꼯
export void ModifyForCylinderMesh(std::vector<Point3D>& p_cylinderMeshVertixs,
    CylinderMesh& m,
    double p_p);