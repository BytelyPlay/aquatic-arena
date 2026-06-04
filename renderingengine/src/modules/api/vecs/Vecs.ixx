module;

export module Vecs;
import Vec;

export namespace Vecs
{
    using Vec3f = Vec<float, 3>;
    using Vec4f = Vec<float, 4>;

    using Vec3d = Vec<double, 3>;
    using Vec4d = Vec<double, 4>;
}