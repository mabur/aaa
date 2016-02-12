#pragma once

#include <numeric>

#include "traits.hpp"

namespace aaa {

/**
@defgroup euclidean_space_ranges Euclidean Space perations on Ranges

An Euclidean vector space defines the following:
- the length or Euclidean norm of a vector.
- the dot product of two vectors. This is also known as the scalar product or
  Euclidean inner product.
- the distance between two vectors.

We represent mathematical vectors as ranges of iterators.

@{
*/

template<typename InputIterator1, typename InputIterator2>
value_type_i<InputIterator1>
dot(InputIterator1 first_left, InputIterator1 last_left, InputIterator2 first_right)
{
    using value_type1 = const value_type_i<InputIterator1>;
    using value_type2 = const value_type_i<InputIterator2>;
    static_assert(std::is_same<value_type1, value_type2>::value, "Different value types");

    const auto zero = value_type1();
    return std::inner_product(first_left, last_left, first_right, zero);
}

template<typename InputIterator>
value_type_i<InputIterator> squared_norm(InputIterator first, InputIterator last)
{
    return dot(first, last, first);
}

template<typename InputIterator>
sqrt_value_type_i<InputIterator> norm(InputIterator first, InputIterator last)
{
    return sqrt(squared_norm(first, last));
}

template<typename InputIterator1, typename InputIterator2>
value_type_i<InputIterator1>
squared_distance(InputIterator1 first_left, InputIterator1 last_left, InputIterator2 first_right)
{
    using value_type_left = const value_type_i<InputIterator1>;
    using value_type_right = const value_type_i<InputIterator2>;
    using value_type = value_type_left;
    static_assert(std::is_same<value_type_left, value_type_right>::value, "Different value types");

    const auto zero = value_type();
    auto op1 = [](const value_type& left, const value_type& right)
    {
        return left + right;
    };
    auto op2 = [](const value_type& left, const value_type& right)
    {
        return (left - right) * (left - right);
    };
    return std::inner_product(first_left, last_left, first_right, zero, op1, op2);
}

template<typename InputIterator1, typename InputIterator2>
sqrt_value_type_i<InputIterator1>
distance(InputIterator1 first_left, InputIterator1 last_left, InputIterator2 first_right)
{
    return sqrt(squared_distance(first_left, last_left, first_right));
}

/** @} */

} // namespace aaa
