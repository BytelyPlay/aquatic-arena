module;

export module Concepts;

export namespace Concepts
{
    template<typename T>
    concept hasXYZW = requires(T t)
    {
        t.x;
        t.y;
        t.z;
        t.w;
    };
    // T = Type to check, CoordType = type of coordinates
    template<typename T, typename CoordType>
    concept hasXYZWConstructor = requires(
        CoordType x, CoordType y,
        CoordType z, CoordType w
    )
    {
        T(x, y, z, w);
    };
    template<typename T, typename IndexType>
    concept hasSubscriptOperator = requires(
        T t, IndexType i
    )
    {
        t[i];
    };
}