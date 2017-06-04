#pragma once

#include <cmath>
#include <numeric>

#include "traits.hpp"

namespace aaa {
namespace maximum {

/**
@addtogroup maximum_space Maximum Space

Maximum space is also known as Chebyshev space or L-infinity space.
Maximum space defines the following functions:
- The maximum norm or length of a vector is defined as:
  \f$ \| a \|_\infty = \max_i |a_i| \f$
- The maximum distance between the vectors a and b is defined as:
  \f$ d_\infty(a, b) = \|a-b\|_\infty = \max_i |a_i-b_i| \f$

We represent mathematical vectors as either containers, or ranges of iterators.
The functions in this module take one or two vectors as input and output a
single scalar. This is sometimes refered to as a reduction or fold operation.

@{
*/

template<typename InputIterator, typename T = value_type_i<InputIterator>>
T norm(InputIterator first, InputIterator last, T init = T{})
{
    using value_type = const value_type_i<InputIterator>;
    const auto max_abs = [](const value_type& left, const value_type& right)
    {
        return std::max(left, std::abs(right));
    };
    return std::accumulate(first, last, init, max_abs);
}

/** The maximum norm of a vector.
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

/** The squared maximum norm of a vector.
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
        return std::max(left, right);
    };
    auto op2 = [](const value_type& left, const value_type& right)
    {
        return std::abs(left - right);
    };
    return std::inner_product(first_left, last_left, first_right, init, op1, op2);
}

/** The maximum distance of two vectors.
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

/** The squared maximum distance of two vectors.
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

} // namespace maximum
} // namespace aaa
