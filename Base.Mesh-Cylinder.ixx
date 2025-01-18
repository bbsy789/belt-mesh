export module Base.Mesh:Cylinder;

import <vector>;
import Base.Point;
import Base.Type;
// Բ���������
export struct CylinderMesh
{
    double r;//Բ���뾶
    double originCor; //ԭ������
    double terminusCor; //�յ�����
    index_t rNumber; //Բ���뾶��������
    index_t axisNumber; //���򻮷�����
};
export
template <IsPoint3D T>
inline index_t GenerateCylinderMesh(std::vector<T>& p_cylinderMeshVertixs,
    CylinderMesh& p_cylinderMesh, index_t p_beginIndex = 1);

export
template <IsVertixs3D T>
inline index_t GenerateCylinderMesh(std::vector<T>& p_cylinderMeshVertixs,
    CylinderMesh& p_cylinderMesh, index_t p_beginIndex = 1);