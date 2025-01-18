export module Base.Mesh:Print;

import <vector>;
import <string_view>;

import Base.Point;

import :Element;
export
inline void PrintPoints3D(std::vector<Point3D>& p_points, std::string_view format);

export
inline void PrintVertixs3D(std::vector<Vertixs3D>& p_vertixs, std::string_view format);

export
inline void PrintElements(std::vector<C3D8>& p_elements, std::string_view format);