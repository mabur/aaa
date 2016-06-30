#pragma once

#include <cmath>
#include <numeric>

#include "traits.hpp"

namespace aaa {
namespace manhattan {

/**
@defgroup manhattan_space_range manhattan Space operations on Ranges

In manhattan geometry we have:
- the manhattan norm which is also known as the Manhattan norm or L1 norm.
- the manhattan distance which is also known as the Manhattan distance or L1 distance.

We represent mathematical vectors as ranges of iterators.

@{
*/

template<typename InputIterator>
value_type_i<InputIterator> norm(InputIterator first, InputIterator last)
{
    using value_type = const value_type_i<InputIterator>;

    const auto zero    = value_type();
    const auto add_abs = [](const value_type& left, const value_type& right)
    {
        return left + std::abs(right);
    };
    return std::accumulate(first, last, zero, add_abs);
}

template<typename InputIterator>
value_type_i<InputIterator> squared_norm(InputIterator first, InputIterator last)
{
    const auto n = norm(first, last);
    return n * n;
}

template<typename InputIterator1, typename InputIterator2>
value_type_i<InputIterator1>
distance(InputIterator1 first_left, InputIterator1 last_left, InputIterator2 first_right)
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
        return std::abs(left - right);
    };
    return std::inner_product(first_left, last_left, first_right, zero, op1, op2);
}

template<typename InputIterator1, typename InputIterator2>
value_type_i<InputIterator1>
squared_distance(InputIterator1 first_left, InputIterator1 last_left, InputIterator2 first_right)
{
    const auto d = distance(first_left, last_left, first_right);
    return d * d;
}

/** @} */

} // namespace manhattan
} // namespace aaa
