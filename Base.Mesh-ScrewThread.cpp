module;


#define _USE_MATH_DEFINES
#include <cmath>;

#include <vector>;
module Base.Mesh:ScrewThread;

import Base.Point;

void Generate90DegreeScrewThreadMesh(std::vector<Point3D>& p_screwThreadMeshVertixs,
    ScrewThreadMesh& p_screwThreadMesh)
{
    double thetaIni = 0;
    double thetaAdd = 0;
    double theta = 0;
    double r = 0;
    double axisDirInc = p_screwThreadMesh.p / p_screwThreadMesh.axisNumber; // ��������
    double thetaIncrement = 2 * M_PI / p_screwThreadMesh.rNumber; // ������Ƕ�����
    //����ѭ��������������
    for (int i = 0; i < p_screwThreadMesh.axisNumber; ++i)
    {
        for (int j = 0; j < p_screwThreadMesh.rNumber; ++j)
        {
            //��ǰ���ɵ���ȫ������ϵX��ļн�theta_{ini}
            thetaIni = thetaIncrement * j;
            //std::cout << "��ǰ���ɵ���ȫ������ϵX��ļн�theta_{ini} = " << thetaIni << "\n";
            //��������������������ļнǱ仯��theta_{add}
            //theta_{add} = 2*pi*z/P z�����꣬P�ǵ���
            //0<=theta_{add}<=2pi
            thetaAdd = 2 * M_PI * i * axisDirInc / p_screwThreadMesh.p;
            //std::cout << "��������������������ļнǱ仯��theta_{add} = " << thetaAdd << "\n";
            //��theta = mod(theta_{ini}+theta_{add},2pi)
            theta = std::fmod(thetaIni + thetaAdd, 2 * M_PI);
            //std::cout << "��theta = theta_{ini}+theta_{add} = " << theta << "\n";
            //����r
            // r = -P*theta/(2*pi)+d/2 ,(0<=theta<pi)
            //   = P*theta/(2*pi)+d/2-P,(pi<=theta<=2*pi)
            if (theta >= 0 && theta < M_PI)
            {
                r = -p_screwThreadMesh.p * theta / (2 * M_PI) + p_screwThreadMesh.r;
                //std::cout << "theta>=0&&theta<M_PI, r = " << r << "\n";
            }
            else if (theta >= M_PI && theta <= 2 * M_PI)
            {
                r = p_screwThreadMesh.p * theta / (2 * M_PI) + p_screwThreadMesh.r - p_screwThreadMesh.p;
                //std::cout << "theta>=M_PI&&theta<=2*M_PI, r = " << r << "\n";
            }
            /*std::cout << "�ڵ���ţ�" << (i * p_screwThreadMesh.rNumber + j + 1)
                << "x:" << (r * cos(thetaIni))
                << "y:" << (r * sin(thetaIni))
                << "z:" << (i * axisDirInc)
                << "\n";*/
            p_screwThreadMeshVertixs.emplace_back(i * p_screwThreadMesh.rNumber + j + 1,
                r * cos(thetaIni),
                r * sin(thetaIni),
                i * axisDirInc);
        }
    }
}

void GenerateGBScrewThreadMesh(std::vector<Point3D>& p_screwThreadMeshVertixs, ScrewThreadMesh& p_screwThreadMesh)
{
    constexpr double pi = M_PI;
    double thetaIni = 0;
    double thetaAdd = 0;
    double theta = 0;
    double r = 0;
    double P = p_screwThreadMesh.p;
    int axisNumber = p_screwThreadMesh.axisNumber;
    int rNumber = p_screwThreadMesh.rNumber;
    double dDivTwo = p_screwThreadMesh.r;
    double axisDirInc = P / axisNumber; // ��������
    double thetaIncrement = 2 * pi / rNumber; // ������Ƕ�����

    double rho = 0.13 * P;// ���Ͱ뾶
    double h = std::sqrt(3) / 2 * P;
    double theta1 = pi / 8;
    double theta2 = (1 - std::sqrt(3) / P * rho) * pi;
    double theta3 = (1 + std::sqrt(3) / P * rho) * pi;
    double theta4 = 15 / 8 * pi;
    //����ѭ��������������
    for (int i = 0; i < p_screwThreadMesh.axisNumber; ++i)
    {
        for (int j = 0; j < p_screwThreadMesh.rNumber; ++j)
        {
            //��ǰ���ɵ���ȫ������ϵX��ļн�theta_{ini}
            thetaIni = thetaIncrement * j;
            //��������������������ļнǱ仯��theta_{add}
            //theta_{add} = 2*pi*z/P z�����꣬P�ǵ���
            //0<=theta_{add}<=2pi
            thetaAdd = 2 * pi * i * axisDirInc / P;

            theta = std::fmod(thetaIni + thetaAdd, 2 * pi);

            if (theta >= 0 && theta < theta1)
            {
                r = dDivTwo;
            }
            else if (theta >= theta1 && theta <= theta2)
            {
                r = dDivTwo + h / 8 - h / pi * theta;
            }
            else if (theta >= theta2 && theta <= pi)
            {
                r = dDivTwo - 7 / 8 * h + 2 * rho - std::sqrt(rho*rho - (pi - theta)* (pi - theta) / (4 * pi*pi) * P*P);
            }
            else if (theta >= pi && theta <= theta3)
            {
                r = dDivTwo - 7 / 8 * h + 2 * rho - std::sqrt(rho*rho - (theta - pi)* (theta - pi) / (4 * pi*pi) * P*P);
            }
            else if (theta >= theta3 && theta <= theta4)
            {
                r = dDivTwo - 15 / 8 * h + theta / pi * h;
            }
            else
            {
                r = dDivTwo;
            }
            /*std::cout << "�ڵ���ţ�" << (i * p_screwThreadMesh.rNumber + j + 1)
                << "x:" << (r * cos(thetaIni))
                << "y:" << (r * sin(thetaIni))
                << "z:" << (i * axisDirInc)
                << "\n";*/
            p_screwThreadMeshVertixs.emplace_back(i * p_screwThreadMesh.rNumber + j + 1,
                r * cos(thetaIni),
                r * sin(thetaIni),
                i * axisDirInc);
        }
    }
}
