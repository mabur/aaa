#pragma once

#include <cassert>

#include "chebyshev_space_range.hpp"

namespace aaa {

/**
@defgroup chebyshev_space_container Chebyshev Space operations on Containers


We represent mathematical vectors as containers.

@{
*/

The vector is represented by an arbitrary container.
*/
template<typename Container>
value_type<Container> squared_norm_max(const Container& a)
{
    using std::begin;
    using std::end;
    return squared_norm_max(begin(a), end(a));
}

The vector is represented by an arbitrary container.
*/
template<typename Container>
value_type<Container> norm_max(const Container& a)
{
    using std::begin;
    using std::end;
    return norm_max(begin(a), end(a));
}

Each vector is represented by a container.
The two containers should have the same size and value type.
*/
template<typename Container1, typename Container2>
value_type<Container1> squared_distance_max(const Container1& left, const Container2& right)
{
    assert(left.size() == right.size());
    using std::begin;
    using std::end;
    return squared_distance_max(begin(left), end(left), begin(right));
}

Each vector is represented by a container.
The two containers should have the same size and value type.
*/
template<typename Container1, typename Container2>
value_type<Container1> distance_max(const Container1& left, const Container2& right)
{
    assert(left.size() == right.size());
    using std::begin;
    using std::end;
    return distance_max(begin(left), end(left), begin(right));
}

/** @} */

} // namespace aaa
