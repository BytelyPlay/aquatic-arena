module;

module Vec;

// FIELDS
// CONSTRUCTORS
template <typename T, size_t size>
Vec<T, size>::Vec()
{
    data = {};
}

template <typename T, size_t size>
template <typename... Args>
requires(sizeof...(Args) == size)
Vec<T, size>::Vec(Args... args) : data { static_cast<T>(args)... }
{}

template <typename T, size_t size>
template <typename A> requires Concepts::hasSubscriptOperator<A, T>
Vec<T, size>::Vec(const A& other)
{
    for (int i = 0; i < size; i++)
        data[i] = other[i];
}

// METHODS
// OPERATORS
template <typename T, size_t size>
T& Vec<T, size>::operator[](int index)
{
    return data[index];
}

template <typename T, size_t size>
Vec<T, size> Vec<T, size>::operator+(Vec other) const
{
    Vec<T, size> result;

    for (int i = 0; i < size; i++)
        result[i] = (*this)[i] + other[i];
    return result;
}
template <typename T, size_t size>
Vec<T, size> Vec<T, size>::operator-(Vec other) const
{
    Vec<T, size> result;

    for (int i = 0; i < size; i++)
        result[i] = (*this)[i] - other[i];
    return result;
}
template <typename T, size_t size>
Vec<T, size> Vec<T, size>::operator*(Vec other) const
{
    Vec<T, size> result;

    for (int i = 0; i < size; i++)
        result[i] = (*this)[i] * other[i];
    return result;
}
template <typename T, size_t size>
Vec<T, size> Vec<T, size>::operator/(Vec other) const
{
    Vec<T, size> result;

    for (int i = 0; i < size; i++)
        result[i] = (*this)[i] / other[i];
    return result;
}