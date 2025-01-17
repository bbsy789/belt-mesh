export module Base.Mesh:ScrewThread;

import Base.Point;
import <vector>;

// �����������
export struct ScrewThreadMesh
{
    double r;//Բ���뾶
    int rNumber; //Բ���뾶��������
    double originCor; //ԭ������
    double terminusCor; //�յ�����
    int axisNumber; //���򻮷�����
    double p; //���Ƶ���
};

// ����90�������ƽڵ�����
export
int Generate90DegreeScrewThreadMesh(std::vector<Point3D>& p_screwThreadMeshVertixs,
    ScrewThreadMesh& p_screwThreadMesh,int p_beginIndex = 1);

// ����GB��ͨ���ƽڵ�����
export
int GenerateGBScrewThreadMesh(std::vector<Point3D>& p_screwThreadMeshVertixs,
    ScrewThreadMesh& p_screwThreadMesh,int p_beginIndex = 1);