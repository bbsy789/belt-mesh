module;
#define _USE_MATH_DEFINES
#include <cmath>

module Base.Math;

// Transform angle From Radius to Degree unit 
double Rad2Deg(double rad_value)
{
    return rad_value * (180.0 / M_PI);
}

// Transform angle From Degree to Radius unit
double Deg2Rad(double deg_value)
{
    return deg_value * (M_PI / 180.0);
}


import Base.Point;

// Distance between two points
double distance(const Point2D& p1, const Point2D& p2)
{
    return std::sqrt(std::pow(p1.x - p2.x, 2) + std::pow(p1.y - p2.y, 2));
}

double distance(const Point3D& p1, const Point3D& p2)
{
    return std::sqrt(std::pow(p1.x - p2.x, 2) + std::pow(p1.y - p2.y, 2) + std::pow(p1.z - p2.z, 2));
}