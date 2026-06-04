module;
#include <array>

export module Vec;

import Concepts;

using size_t = std::size_t;

// This isn't... bad code, it is a bit messy, but it seems fine.
export template<typename T, size_t size>
struct Vec
{
    // FIELDS

    // I really don't like this being private, but to be honest,
    // I really don't want a Vec that's a class.
private:
    std::array<T, size> data;
public:
    // CONSTRUCTORS
    Vec();

    template<typename... Args>
    requires(sizeof...(Args) == size)
    Vec(Args... args);

    template<typename A>
    requires Concepts::hasSubscriptOperator<A, T>
    Vec(const A& other);

    // METHODS
    // OPERATORS
    T& operator[](int index);

    Vec operator+(Vec other) const;
    Vec operator-(Vec other) const;
    Vec operator*(Vec other) const;
    Vec operator/(Vec other) const;
};
// Specializations
export template<typename T>
struct Vec<T, 3>
{
    union
    {
        struct { T x, y, z; };
    };
};
export template<typename T>
struct Vec<T, 4>
{
    union
    {
        struct { T x, y, z, w; };
    };
};