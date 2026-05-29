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
}