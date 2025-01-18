export module Base.Mesh:ScrewThread;

import Base.Point;
import Base.Type;
import <vector>;

// 螺纹网格参数
export struct ScrewThreadMesh
{
    double r;//圆柱半径
    double originCor; //原点坐标
    double terminusCor; //终点坐标
    index_t rNumber; //圆柱半径划分数量
    index_t axisNumber; //轴向划分数量
    double p; //螺纹导程
};

// 生成90度外螺纹节点网格
export
inline index_t Generate90DegreeScrewThreadMesh(std::vector<Point3D>& p_screwThreadMeshVertixs,
    ScrewThreadMesh& p_screwThreadMesh, index_t p_beginIndex = 1);

export
inline index_t Generate90DegreeScrewThreadMesh(std::vector<Vertixs3D>& p_screwThreadMeshVertixs,
    ScrewThreadMesh& p_screwThreadMesh, index_t p_beginIndex = 1);

// 生成GB普通螺纹节点网格
export
inline index_t GenerateGBScrewThreadMesh(std::vector<Point3D>& p_screwThreadMeshVertixs,
    ScrewThreadMesh& p_screwThreadMesh, index_t p_beginIndex = 1);

export
inline index_t GenerateGBScrewThreadMesh(std::vector<Vertixs3D>& p_screwThreadMeshVertixs,
    ScrewThreadMesh& p_screwThreadMesh, index_t p_beginIndex = 1);