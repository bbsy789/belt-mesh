module;

#define _USE_MATH_DEFINES
#include <cmath>

import <vector>;
import Base.Point;
import Base.Type;
module Base.Mesh:Inter;

inline index_t GenerateInterMeshVertixs(std::vector<Point3D>& p_interMeshVertixs,
    InterMesh& p_interMesh,
    index_t p_beginIndex)
{
    index_t Index = p_beginIndex;
    constexpr double pi = M_PI;
    double thetaIni = 0;
    double thetaAdd = 0;
    double theta = 0;
    double r = 0;
    double P = p_interMesh.p;
    double radialIncrement = (p_interMesh.r_exter - p_interMesh.r_inter) / p_interMesh.radialDirectionNumber;
    double r_dist = 0;
    index_t axisNumber = p_interMesh.axisDirectionNumber;
    index_t radiusDirectionNumber = p_interMesh.radiusDirectionNumber;
    double dDivTwo = p_interMesh.r_exter;
    double axisDirInc = P / axisNumber; // 轴向增量
    double thetaIncrement = 2 * pi / radiusDirectionNumber; // 极坐标角度增量

    double rho = 0.13 * P;// 牙型半径
    //std::cout << "rho: " << rho << "\n";
    double h = std::sqrt(3.0) / 2.0 * P;
    //std::cout << "h: " << h << "\n";
    double theta1 = pi / 8.0;
    //std::cout << "theta1: " << Rad2Deg(theta1) << "\n";
    double theta2 = (1.0 - std::sqrt(3.0) / P * rho) * pi;
    //std::cout << "theta2: " << Rad2Deg(theta2) << "\n";
    double theta3 = (1.0 + std::sqrt(3.0) / P * rho) * pi;
    //std::cout << "theta3: " << Rad2Deg(theta3) << "\n";
    double theta4 = 15.0 / 8.0 * pi;
    //std::cout << "theta4: " << Rad2Deg(theta4) << "\n";
    //三层循环生成中间网格，从外往内生成
    for (index_t k = 1; k <= p_interMesh.radialDirectionNumber; ++k)
    {
        for (index_t i = 0; i <= p_interMesh.axisDirectionNumber; ++i)
        {
            for (index_t j = 0; j < p_interMesh.radiusDirectionNumber; ++j)
            {
                //当前生成点与全局坐标系X轴的夹角theta_{ini}
                thetaIni = thetaIncrement * j;
                //外轮廓线螺旋上升引起的夹角变化量theta_{add}
                //theta_{add} = 2*pi*z/P z是坐标，P是导程
                //0<=theta_{add}<=2pi
                thetaAdd = std::fmod(2.0 * pi * i * axisDirInc / P, 2.0 * pi);

                theta = std::fmod(thetaIni + thetaAdd, 2.0 * pi);

                if (theta >= 0 && theta < theta1)
                {
                    r = dDivTwo;
                }
                else if (theta >= theta1 && theta <= theta2)
                {
                    r = dDivTwo + h / 8.0 - h / pi * theta;
                }
                else if (theta >= theta2 && theta <= pi)
                {
                    r = dDivTwo - 7.0 / 8.0 * h + 2.0 * rho - std::sqrt(rho * rho - (pi - theta) * (pi - theta) / (4.0 * pi * pi) * P * P);
                }
                else if (theta >= pi && theta <= theta3)
                {
                    r = dDivTwo - 7.0 / 8.0 * h + 2.0 * rho - std::sqrt(rho * rho - (theta - pi) * (theta - pi) / (4.0 * pi * pi) * P * P);
                }
                else if (theta >= theta3 && theta <= theta4)
                {
                    r = dDivTwo - 15.0 / 8.0 * h + theta / pi * h;
                }
                else
                {
                    r = dDivTwo;
                }
                r_dist = p_interMesh.r_exter - radialIncrement * k;
                // 插值
                r = (r_dist - p_interMesh.r_inter) / (p_interMesh.r_exter - p_interMesh.r_inter) * (r - p_interMesh.r_inter) + p_interMesh.r_inter;
                    //std::cout << "节点序号：" << (i * p_interMesh.radiusDirectionNumber + j + p_beginIndex + 1) << "\n"
                    //    << "thetaIni: " << Rad2Deg(thetaIni) << "\n"
                    //    << "thetaAdd: " << Rad2Deg(thetaAdd) << "\n"
                    //    << "theta: " << Rad2Deg(theta) << "\n"
                    //    << "r: " << r << "\n";
                p_interMeshVertixs.emplace_back(Index,
                    r * std::cos(thetaIni),
                    r * std::sin(thetaIni),
                    i * axisDirInc);
                ++Index;
            }
        }
    }
    return Index;
}

inline index_t GenerateInterMeshVertixs(std::vector<Vertixs3D>& p_interMeshVertixs,
    InterMesh& p_interMesh,
    index_t p_beginIndex)
{
    index_t Index = p_beginIndex;
    constexpr double pi = M_PI;
    double thetaIni = 0;
    double thetaAdd = 0;
    double theta = 0;
    double r = 0;
    double P = p_interMesh.p;
    double radialIncrement = (p_interMesh.r_exter - p_interMesh.r_inter) / p_interMesh.radialDirectionNumber;
    double r_dist = 0;
    index_t axisNumber = p_interMesh.axisDirectionNumber;
    index_t radiusDirectionNumber = p_interMesh.radiusDirectionNumber;
    double dDivTwo = p_interMesh.r_exter;
    double axisDirInc = P / axisNumber; // 轴向增量
    double thetaIncrement = 2 * pi / radiusDirectionNumber; // 极坐标角度增量

    double rho = 0.13 * P;// 牙型半径
    //std::cout << "rho: " << rho << "\n";
    double h = std::sqrt(3.0) / 2.0 * P;
    //std::cout << "h: " << h << "\n";
    double theta1 = pi / 8.0;
    //std::cout << "theta1: " << Rad2Deg(theta1) << "\n";
    double theta2 = (1.0 - std::sqrt(3.0) / P * rho) * pi;
    //std::cout << "theta2: " << Rad2Deg(theta2) << "\n";
    double theta3 = (1.0 + std::sqrt(3.0) / P * rho) * pi;
    //std::cout << "theta3: " << Rad2Deg(theta3) << "\n";
    double theta4 = 15.0 / 8.0 * pi;
    //std::cout << "theta4: " << Rad2Deg(theta4) << "\n";
    //三层循环生成中间网格，从外往内生成
    for (index_t k = 1; k <= p_interMesh.radialDirectionNumber; ++k)
    {
        for (index_t i = 0; i <= p_interMesh.axisDirectionNumber; ++i)
        {
            for (index_t j = 0; j < p_interMesh.radiusDirectionNumber; ++j)
            {
                //当前生成点与全局坐标系X轴的夹角theta_{ini}
                thetaIni = thetaIncrement * j;
                //外轮廓线螺旋上升引起的夹角变化量theta_{add}
                //theta_{add} = 2*pi*z/P z是坐标，P是导程
                //0<=theta_{add}<=2pi
                thetaAdd = std::fmod(2.0 * pi * i * axisDirInc / P, 2.0 * pi);

                theta = std::fmod(thetaIni + thetaAdd, 2.0 * pi);

                if (theta >= 0 && theta < theta1)
                {
                    r = dDivTwo;
                }
                else if (theta >= theta1 && theta <= theta2)
                {
                    r = dDivTwo + h / 8.0 - h / pi * theta;
                }
                else if (theta >= theta2 && theta <= pi)
                {
                    r = dDivTwo - 7.0 / 8.0 * h + 2.0 * rho - std::sqrt(rho * rho - (pi - theta) * (pi - theta) / (4.0 * pi * pi) * P * P);
                }
                else if (theta >= pi && theta <= theta3)
                {
                    r = dDivTwo - 7.0 / 8.0 * h + 2.0 * rho - std::sqrt(rho * rho - (theta - pi) * (theta - pi) / (4.0 * pi * pi) * P * P);
                }
                else if (theta >= theta3 && theta <= theta4)
                {
                    r = dDivTwo - 15.0 / 8.0 * h + theta / pi * h;
                }
                else
                {
                    r = dDivTwo;
                }
                r_dist = p_interMesh.r_exter - radialIncrement * k;
                // 插值
                r = (r_dist - p_interMesh.r_inter) / (p_interMesh.r_exter - p_interMesh.r_inter) * (r - p_interMesh.r_inter) + p_interMesh.r_inter;
                //std::cout << "节点序号：" << (i * p_interMesh.radiusDirectionNumber + j + p_beginIndex + 1) << "\n"
                //    << "thetaIni: " << Rad2Deg(thetaIni) << "\n"
                //    << "thetaAdd: " << Rad2Deg(thetaAdd) << "\n"
                //    << "theta: " << Rad2Deg(theta) << "\n"
                //    << "r: " << r << "\n";
                p_interMeshVertixs.emplace_back(Index,
                    r * std::cos(thetaIni),
                    r * std::sin(thetaIni),
                    i * axisDirInc,
                    i,
                    j,
                    k);
                ++Index;
            }
        }
    }
    return Index;
}
