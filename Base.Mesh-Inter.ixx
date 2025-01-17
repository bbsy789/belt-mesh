export module Base.Mesh:Inter;

import <vector>;
import Base.Point;

export struct InterMesh
{
    double r_exter;//���ư뾶
    double r_inter;//�ڲ�Բ���뾶

    double originCor; //ԭ������
    double terminusCor; //�յ�����
    double p; //���Ƶ���

    int radiusDirectionNumber; //���滮������
    int axisDirectionNumber; //���򻮷�����
    int radialDirectionNumber; // ���򻮷�����
};

// ����ֲ���������ڲ��ڵ㵽���ĵľ�����룬ʣ�µľ�ֻ��Ҫ֪��
export int GenerateInterMeshVertixs(std::vector<Point3D>& p_interMeshVertixs, InterMesh& p_interMesh, int p_beginIndex = 1);

