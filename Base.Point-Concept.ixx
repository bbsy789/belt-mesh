export module Base.Point:Concept;

export
template <typename T>
concept IsPoint3D = requires(T a)
{
    a.index;
    a.x;
    a.y;
    a.z;
};
export 
template <typename T>
concept HasIJK = requires(T a)
{
    a.i;
    a.j;
    a.k;
};
export 
template <typename T>
concept IsVertixs3D = IsPoint3D<T> && HasIJK<T>;
