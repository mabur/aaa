#pragma once

#include <cassert>
#include <cmath>
#include <numeric>

#include "traits.hpp"

namespace aaa {
namespace manhattan {

/**
@addtogroup manhattan_space Manhattan Space

Manhattan space is also known as taxicab geometry or L-1 space.
Manhattan space defines the following functions:
- The Manhattan norm or length of a vector is defined as:
  \f$ \| a \|_1 = \sum_i |a_i| \f$
- The Manhattan distance between the vectors a and b is defined as:
  \f$ d_1(a, b) = \|a-b\|_1 = \sum_i |a_i-b_i| \f$

We represent mathematical vectors as either containers, or ranges of iterators.
The functions in this module take one or two vectors as input and output a
single scalar. This is sometimes refered to as a reduction or fold operation.

@{
*/

/** The manhattan norm of a vector.
The vector is represented a range of iterators.
*/
template<typename InputIterator, typename T = value_type_i<InputIterator>>
T norm(InputIterator first, InputIterator last, T init = T{})
{
    const auto add_abs = [](const auto left, const auto right) -> T
    {
        return left + std::abs(right);
    };
    return std::accumulate(first, last, init, add_abs);
}

/** The manhattan norm of a vector.
The vector is represented by a container.
*/
template<typename Container, typename T = value_type<Container>>
T norm(const Container& a, T init = T{})
{
    using std::begin;
    using std::end;
    return norm(begin(a), end(a), init);
}

/** The squared manhattan norm of a vector.
The vector is represented by a range of iterators.
*/
template<typename InputIterator, typename T = value_type_i<InputIterator>>
T squared_norm(InputIterator first, InputIterator last, T init = T{})
{
    const auto n = norm(first, last, init);
    return n * n;
}

/** The squared manhattan norm of a vector.
The vector is represented by a container.
*/
template<typename Container, typename T = value_type<Container>>
T squared_norm(const Container& a, T init = T{})
{
    using std::begin;
    using std::end;
    return squared_norm(begin(a), end(a), init);
}

/** The manhattan distance of two vectors.
Each vector is represented by a range of iterators.
The two containers should have the same size.
*/
template<typename InputIterator1, typename InputIterator2, typename T = value_type_i<InputIterator1>>
T distance(InputIterator1 first_left, InputIterator1 last_left, InputIterator2 first_right, T init = T{})
{
    auto op1 = [](const T left, const T right) -> T
    {
        return left + right;
    };
    auto op2 = [](const auto left, const auto right) -> T
    {
        return std::abs(left - right);
    };
    return std::inner_product(first_left, last_left, first_right, init, op1, op2);
}

/** The manhattan distance of two vectors.
Each vector is represented by a container.
The two containers should have the same size.
*/
template<typename Container1, typename Container2, typename T = value_type<Container1>>
T distance(const Container1& left, const Container2& right, T init = T{})
{
    assert(left.size() == right.size());
    using std::begin;
    using std::end;
    return distance(begin(left), end(left), begin(right), init);
}

/** The squared manhattan distance of two vectors.
Each vector is represented by a range of iterators.
*/
template<typename InputIterator1, typename InputIterator2, typename T = value_type_i<InputIterator1>>
T squared_distance(InputIterator1 first_left, InputIterator1 last_left, InputIterator2 first_right, T init = T{})
{
    const auto d = distance(first_left, last_left, first_right, init);
    return d * d;
}

/** The squared manhattan distance of two vectors.
Each vector is represented by a container.
The two containers should have the same size and value type.
*/
template<typename Container1, typename Container2, typename T = value_type<Container1>>
T squared_distance(const Container1& left, const Container2& right, T init = T{})
{
    assert(left.size() == right.size());
    using std::begin;
    using std::end;
    return squared_distance(begin(left), end(left), begin(right), init);
}

/** @} */

} // namespace manhattan
} // namespace aaa
