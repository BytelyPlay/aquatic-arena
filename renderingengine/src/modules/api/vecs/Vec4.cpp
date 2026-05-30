module;
#include <type_traits>

module Vec4;

template <typename T>
Vec4<T>::Vec4()
{
    this(Vec4(0, 0, 0, 0));
}

template <typename T>
Vec4<T> Vec4<T>::operator+(Vec4 other) const
{
    return { other.x + x, other.y + y, other.z + z, other.w + w };
}

template <typename T>
Vec4<T> Vec4<T>::operator-(Vec4 other) const
{
    return { other.x - x, other.y - y, other.z - z, other.w - w };
}

template <typename T>
Vec4<T> Vec4<T>::operator*(Vec4 other) const
{
    return { other.x * x, other.y * y, other.z * z, other.w * w };
}

template <typename T>
Vec4<T> Vec4<T>::operator/(Vec4 other) const
{
    return { other.x / x, other.y / y, other.z / z, other.w / w };
}
