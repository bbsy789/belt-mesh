export module Base.Mesh:ScrewThread;

import Base.Point;
import Base.Type;
import <vector>;

// �����������
export struct ScrewThreadMesh
{
    double r;//Բ���뾶
    double originCor; //ԭ������
    double terminusCor; //�յ�����
    index_t rNumber; //Բ���뾶��������
    index_t axisNumber; //���򻮷�����
    double p; //���Ƶ���
};

// ����90�������ƽڵ�����
export
inline index_t Generate90DegreeScrewThreadMesh(std::vector<Point3D>& p_screwThreadMeshVertixs,
    ScrewThreadMesh& p_screwThreadMesh, index_t p_beginIndex = 1);

export
inline index_t Generate90DegreeScrewThreadMesh(std::vector<Vertixs3D>& p_screwThreadMeshVertixs,
    ScrewThreadMesh& p_screwThreadMesh, index_t p_beginIndex = 1);

// ����GB��ͨ���ƽڵ�����
export
inline index_t GenerateGBScrewThreadMesh(std::vector<Point3D>& p_screwThreadMeshVertixs,
    ScrewThreadMesh& p_screwThreadMesh, index_t p_beginIndex = 1);

export
inline index_t GenerateGBScrewThreadMesh(std::vector<Vertixs3D>& p_screwThreadMeshVertixs,
    ScrewThreadMesh& p_screwThreadMesh, index_t p_beginIndex = 1);