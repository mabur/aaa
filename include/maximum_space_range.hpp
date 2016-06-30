#pragma once

#include <cmath>
#include <numeric>

#include "traits.hpp"

namespace aaa {
namespace maximum {

/**
@defgroup maximum_space_range maximum Space operations on Ranges

In maximum geometry we have:
- the maximum norm which is also known as the maximum norm or infinity norm.
- the maximum distance.

We represent mathematical vectors as ranges of iterators.

@{
*/

template<typename InputIterator>
value_type_i<InputIterator> norm(InputIterator first, InputIterator last)
{
    using value_type = const value_type_i<InputIterator>;

    const auto zero    = value_type();
    const auto max_abs = [](const value_type& left, const value_type& right)
    {
        return std::max(left, std::abs(right));
    };
    return std::accumulate(first, last, zero, max_abs);
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
        return std::max(left, right);
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

} // namespace maximum
} // namespace aaa
