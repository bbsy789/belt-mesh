module;


#define _USE_MATH_DEFINES
#include <cmath>;
#include <vector>;
#include <iostream>;
#include <iomanip>;
#include <string_view>;
module Base.Mesh:Print;

import Base.Point;

inline void PrintPoints3D(std::vector<Point3D>& p_points, std::string_view format)
{
    if (format == "table")
    {
        //std::cout << "this file generated by wwj's r.\n";
        for (auto& i : p_points)
        {
            //如果x,y小于很小的数，则用0代替
            std::cout << std::setw(8) << i.index
                << std::setw(12) << (std::abs(i.x) <= 1e-15 ? 0 : i.x)
                << std::setw(12) << (std::abs(i.y) <= 1e-15 ? 0 : i.y)
                << std::setw(12) << i.z
                << "\n";
        }

    }
    
}

inline void PrintVertixs3D(std::vector<Vertixs3D>& p_vertixs, std::string_view format)
{
    if (format == "table")
    {
        //std::cout << "this file generated by wwj's r.\n";
        for (auto& i : p_vertixs)
        {
            //如果x,y小于很小的数，则用0代替
            std::cout << std::setw(8) << i.index
                << std::setw(12) << (std::abs(i.x) <= 1e-15 ? 0 : i.x)
                << std::setw(12) << (std::abs(i.y) <= 1e-15 ? 0 : i.y)
                << std::setw(12) << i.z
                << std::setw(12) << i.i
                << std::setw(12) << i.j
                << std::setw(12) << i.k
                << "\n";
        }
    }
    if (format == "apdl")
    {
        // 进入前处理
        std::cout << "/prep7\n";
        // 创建节点
        for (auto& i : p_vertixs)
        {
            std::cout << "N," << i.index << "," << i.x << "," << i.y << "," << i.z << "\n";
        }
        std::cout << "finish\n";
    }
}

inline void PrintElements(std::vector<C3D8>& p_elements, std::string_view format)
{
    if (format == "table")
    {
        //std::cout << "this file generated by wwj's r.\n";
        for (auto& i : p_elements)
        {
            i.PrintElement();
        }
    }
    if (format == "apdl")
    {
        std::cout << "/prep7\n" 
                  << "ET, 1, SOLID185 \n"
            << "TYPE, 1\n"
            << "MAT,\n"
            << "REAL,\n"
            << "ESYS, 0\n"
            << "SECNUM,\n"
            << "TSHAPE, LINE\n";
        for (auto& i : p_elements)
        {
            std::cout        << "EN," 
                << i.Index   << "," 
                << i.p1Index << "," 
                << i.p2Index << "," 
                << i.p3Index << "," 
                << i.p4Index << ","
                << i.p5Index << "," 
                << i.p6Index << "," 
                << i.p7Index << "," 
                << i.p8Index << "\n";
        }
    }
}