module;
#include <type_traits>

module Vec4;

template <typename T>
template<Concepts::hasXYZW A>
Vec4<T>::Vec4(const A& other)
{
    this(other.x, other.y, other.z, other.w);
}

template <typename T>
Vec4<T>::Vec4(T x, T y, T z, T w) : x(x), y(y), z(z), w(w)
{
    static_assert(
        std::is_floating_point_v<T>() ||
        std::is_integral_v<T>()
    );
}

template <typename T>
Vec4<T>::Vec4()
{
    this(Vec4(0, 0, 0, 0));
}

template <typename T>
template <typename A>
Vec4<T>::operator A() const
{
    return A(x, y, z, w);
}
