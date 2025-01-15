export module Base.Mesh:Print;

import <vector>;
import <string_view>;
import Base.Point;

export void Print3D(std::vector<Point3D>& p_vertixs, std::string_view format);