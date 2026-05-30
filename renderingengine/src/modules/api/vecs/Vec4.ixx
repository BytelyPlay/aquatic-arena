module;
#include <type_traits>

export module Vec4;
import Concepts;

export template<typename T>
struct Vec4
{
    // FIELDS
    T x, y, z, w;

    // CONSTRUCTORS
    Vec4(T x, T y, T z, T w);
    Vec4();

    template<Concepts::hasXYZW A>
    Vec4(const A& other);

    // METHODS
    // OPERATORS
    Vec4 operator+(Vec4 other) const;
    Vec4 operator-(Vec4 other) const;
    Vec4 operator*(Vec4 other) const;
    Vec4 operator/(Vec4 other) const;
};

template <typename T>
Vec4<T>::Vec4(T x, T y, T z, T w) : x(x), y(y), z(z), w(w)
{
    static_assert(
        std::is_floating_point_v<T> ||
        std::is_integral_v<T>
    );
}
template <typename T>
template<Concepts::hasXYZW A>
Vec4<T>::Vec4(const A& other)
{
    this(other.x, other.y, other.z, other.w);
}