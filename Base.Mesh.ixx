// 定义主模块名Base.Mesh，这里的.对于编译器没有意义，模块名称中的句点对编译器没有特殊含义。 
// 句点可用于传达模块的组织方式。 如果你有多个模块文件一起工作，可以使用句点来指示分离关注点。
// 在本教程中，我们将使用句点来指示 API 的不同功能区域。
export module Base.Mesh;

// 声明模块分区
export import :Circle;
export import :Cylinder;
export import :ScrewThread;
export import :Print;