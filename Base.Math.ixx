export module Base.Math;
// Transform angle From Radius to Degree unit 
export double Rad2Deg(double rad_value);

// Transform angle From Degree to Radius unit
export double Deg2Rad(double deg_value);

import Base.Point;

// Distance between two Point2Ds
export double distance(const Point2D& p1, const Point2D& p2);

// Distance between two Point3Ds
export double distance(const Point3D& p1, const Point3D& p2);