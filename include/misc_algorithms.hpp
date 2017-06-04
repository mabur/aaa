#pragma once

#include <numeric>

#include "traits.hpp"

namespace aaa {

/**
@addtogroup misc_algorithms

@{
*/

/**
Does elementwise `static_cast` on the elements from one range to another range.
*/
template<typename InputIterator, typename OutputIterator>
void convert(InputIterator first_in, InputIterator last_in, OutputIterator first_out)
{
    auto f = [](value_type_i<InputIterator> x) { return value_type_i<OutputIterator>(x); };
    std::transform(first_in, last_in, first_out, f);
}

/**
Does elementwise `static_cast` on the elements from one container to another container.
*/
template<typename Container1, typename Container2>
void convert(const Container1& in, Container2& out)
{
    assert(in.size() == out.size());
    using std::begin;
    using std::end;
    return convert(begin(in), end(in), begin(out));
}

/**
Computes the sum of the elements of a range.
It assume that the default construction of a scalar gives zero,
which is true for the built-in arithmetic types.
*/
template<typename InputIterator, typename T = value_type_i<InputIterator>>
T sum(InputIterator first, InputIterator last, T init = T{})
{
    return std::accumulate(first, last, init);
}

/**
Computes the sum of the elements of a container.
It assume that the default construction of a scalar gives zero,
which is true for the built-in arithmetic types.
*/
template<typename Container, typename T = value_type<Container>>
T sum(const Container& container, T init = T{})
{
    using std::begin;
    using std::end;
    return sum(begin(container), end(container), init);
}

/** @} */

} // namespace aaa
