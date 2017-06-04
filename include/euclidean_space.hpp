#pragma once

#include <numeric>

#include "traits.hpp"

namespace aaa {
namespace euclidean {

/**
@addtogroup euclidean_space Euclidean Space

Euclidean space is also known as L-2 space. It defines the the following functions:
- The dot product is also known as the scalar product or Euclidean inner product.
  The dot product of the vectors a and b is defined as:
  \f$ a \cdot b = \sum_i a_i b_i \f$
- The Euclidean norm or length of a vector is defined as:
  \f$ \| a \|_2 = \sqrt{a \cdot a} = \sqrt{\sum_i a_i^2} \f$
- The Euclidean distance between the vectors a and b is defined as:
  \f$ d_2(a, b) = \|a-b\|_2 = \sqrt{\sum_i (a_i-b_i)^2} \f$

We represent mathematical vectors as either containers, or ranges of iterators.
The functions in this module take one or two vectors as input and output a
single scalar. This is sometimes refered to as a reduction or fold operation.

@{
*/

/** The dot product of two vectors.
Each vector is represented by a range of iterators.
*/
template<typename InputIterator1, typename InputIterator2, typename T = value_type_i<InputIterator1>>
T dot(InputIterator1 first_left, InputIterator1 last_left, InputIterator2 first_right, T init = T{})
{
    return std::inner_product(first_left, last_left, first_right, init);
}

/** The dot product of two vectors.
Each vector is represented by a container.
The two containers should have the same size.
*/
template<typename Container1, typename Container2, typename T = value_type<Container1>>
T dot(const Container1& a, Container2& b, T init = T{})
{
    assert(a.size() == b.size());
    using std::begin;
    using std::end;
    return dot(begin(a), end(a), begin(b), init);
}

/** The squared Euclidean norm of a vector.
The vector is represented by a range of iterators.
*/
template<typename InputIterator, typename T = value_type_i<InputIterator>>
T squared_norm(InputIterator first, InputIterator last, T init = T{})
{
    return dot(first, last, first, init);
}

/** The squared Euclidean norm of a vector.
The vector is represented by a container.
*/
template<typename Container, typename T = value_type<Container>>
T squared_norm(const Container& a, T init = T{})
{
    using std::begin;
    using std::end;
    return squared_norm(begin(a), end(a), init);
}

/** The Euclidean norm of a vector.
The vector is represented by a range of iterators.
Returns a value of floating point type following the same convention as `std::sqrt`.
*/
template<typename InputIterator, typename T = value_type_i<InputIterator>>
sqrt_type_t<T> norm(InputIterator first, InputIterator last, T init = T{})
{
    return sqrt(squared_norm(first, last, init));
}

/** The Euclidean norm of a vector.
The vector is represented by a container.
Returns a value of floating point type following the same convention as `std::sqrt`.
*/
template<typename Container, typename T = value_type<Container>>
sqrt_type_t<T> norm(const Container& a, T init = T{})
{
    using std::begin;
    using std::end;
    return norm(begin(a), end(a), init);
}

/** The squared Euclidean distance of two vectors.
Each vector is represented by a range of iterators.
*/
template<typename InputIterator1, typename InputIterator2, typename T = value_type_i<InputIterator1>>
T squared_distance(InputIterator1 first_left, InputIterator1 last_left, InputIterator2 first_right, T init = T{})
{
    auto op1 = [](const T left, const T right) -> T
    {
        return left + right;
    };
    auto op2 = [](const auto left, const auto right) -> T
    {
        return (left - right) * (left - right);
    };
    return std::inner_product(first_left, last_left, first_right, init, op1, op2);
}

/** The squared Euclidean distance of two vectors.
Each vector is represented by a container.
The two containers should have the same size.
*/
template<typename Container1, typename Container2, typename T = value_type<Container1>>
T squared_distance(const Container1& left, const Container2& right, T init = T{})
{
    assert(left.size() == right.size());
    using std::begin;
    using std::end;
    return squared_distance(begin(left), end(left), begin(right), init);
}

/** The Euclidean distance of two vectors.
Each vector is represented by a range of iterators.
Returns a value of a floating point type following the same convention as `std::sqrt`.
*/
template<typename InputIterator1, typename InputIterator2, typename T = value_type_i<InputIterator1>>
sqrt_type_t<T> distance(InputIterator1 first_left, InputIterator1 last_left, InputIterator2 first_right, T init = T{})
{
    return sqrt(squared_distance(first_left, last_left, first_right, init));
}

/** The Euclidean distance of two vectors.
Each vector is represented by a container.
The two containers should have the same size.
Returns a value of a floating point type following the same convention as `std::sqrt`.
*/
template<typename Container1, typename Container2, typename T = value_type<Container1>>
sqrt_type_t<T> distance(const Container1& left, const Container2& right, T init = T{})
{
    assert(left.size() == right.size());
    using std::begin;
    using std::end;
    return distance(begin(left), end(left), begin(right), init);
}

/** @} */

} // namespace euclidean
} // namespace aaa
