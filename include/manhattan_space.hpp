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
The functions in this module assume that the default construction of a scalar
gives zero, which is true for the built-in arithmetic types.

@{
*/

template<typename InputIterator, typename T = value_type_i<InputIterator>>
T norm(InputIterator first, InputIterator last, T init = T{})
{
    using value_type = const value_type_i<InputIterator>;
    const auto add_abs = [](const value_type& left, const value_type& right)
    {
        return left + std::abs(right);
    };
    return std::accumulate(first, last, init, add_abs);
}

/** The manhattan norm of a vector.
The vector is represented by an arbitrary container.
*/
template<typename Container, typename T = value_type<Container>>
T norm(const Container& a, T init = T{})
{
    using std::begin;
    using std::end;
    return norm(begin(a), end(a), init);
}

template<typename InputIterator, typename T = value_type_i<InputIterator>>
T squared_norm(InputIterator first, InputIterator last, T init = T{})
{
    const auto n = norm(first, last, init);
    return n * n;
}

/** The squared manhattan norm of a vector.
The vector is represented by an arbitrary container.
*/
template<typename Container, typename T = value_type<Container>>
T squared_norm(const Container& a, T init = T{})
{
    using std::begin;
    using std::end;
    return squared_norm(begin(a), end(a), init);
}

template<typename InputIterator1, typename InputIterator2, typename T = value_type_i<InputIterator1>>
T distance(InputIterator1 first_left, InputIterator1 last_left, InputIterator2 first_right, T init = T{})
{
    using value_type_left = const value_type_i<InputIterator1>;
    using value_type_right = const value_type_i<InputIterator2>;
    using value_type = value_type_left;
    static_assert(std::is_same<value_type_left, value_type_right>::value, "Different value types");
    auto op1 = [](const value_type& left, const value_type& right)
    {
        return left + right;
    };
    auto op2 = [](const value_type& left, const value_type& right)
    {
        return std::abs(left - right);
    };
    return std::inner_product(first_left, last_left, first_right, init, op1, op2);
}

/** The manhattan distance of two vectors.
Each vector is represented by a container.
The two containers should have the same size and value type.
*/
template<typename Container1, typename Container2, typename T = value_type<Container1>>
T distance(const Container1& left, const Container2& right, T init = T{})
{
    assert(left.size() == right.size());
    using std::begin;
    using std::end;
    return distance(begin(left), end(left), begin(right), init);
}

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
