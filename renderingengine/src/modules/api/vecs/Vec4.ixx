module;

export module Vec4;
import Concepts;

export template<typename T>
struct Vec4
{
    // FIELDS
    T x, y, z, w;

    // CONSTRUCTORS
    template<Concepts::hasXYZW A>
    Vec4(const A& other);

    Vec4(T x, T y, T z, T w);
    Vec4();

    // METHODS
    // OPERATORS
    template<typename A>
    operator A() const;
};