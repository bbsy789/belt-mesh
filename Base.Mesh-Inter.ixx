export module Base.Mesh:Inter;

import <vector>;
import Base.Point;
import Base.Type;
export struct InterMesh
{
    double r_exter;//���ư뾶
    double r_inter;//�ڲ�Բ���뾶

    double originCor; //ԭ������
    double terminusCor; //�յ�����
    double p; //���Ƶ���

    index_t radiusDirectionNumber; //���滮������
    index_t axisDirectionNumber; //���򻮷�����
    index_t radialDirectionNumber; // ���򻮷�����
};

// �����м�ڵ�
export
inline index_t GenerateInterMeshVertixs(std::vector<Point3D>& p_interMeshVertixs, InterMesh& p_interMesh, index_t p_beginIndex = 1);

// �����м�ڵ�
export
inline index_t GenerateInterMeshVertixs(std::vector<Vertixs3D>& p_interMeshVertixs, InterMesh& p_interMesh, index_t p_beginIndex = 1);

