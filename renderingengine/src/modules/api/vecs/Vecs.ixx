module;

export module Vecs;
import Vec;

export namespace Vecs
{
    template<typename T>
    using Vec3 = Vec<T, 3>;

    template<typename T>
    using Vec4 = Vec<T, 4>;
}