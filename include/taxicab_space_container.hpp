#pragma once

#include <cassert>

#include "taxicab_space_range.hpp"

namespace aaa {
namespace taxicab {

/**
@defgroup taxicab_space_container Taxicab Space operations on Containers

In Taxicab geometry we have:
- the Taxicab norm which is also known as the Manhattan norm or L1 norm.
- the Taxicab distance which is also known as the Manhattan distance or L1 distance.

We represent mathematical vectors as containers.

@{
*/

/** The squared Taxicab norm of a vector.
The vector is represented by an arbitrary container.
*/
template<typename Container>
value_type<Container> squared_norm(const Container& a)
{
    using std::begin;
    using std::end;
    return squared_norm(begin(a), end(a));
}

/** The Taxicab norm of a vector.
The vector is represented by an arbitrary container.
*/
template<typename Container>
value_type<Container> norm(const Container& a)
{
    using std::begin;
    using std::end;
    return norm(begin(a), end(a));
}

/** The squared Taxicab distance of two vectors.
Each vector is represented by a container.
The two containers should have the same size and value type.
*/
template<typename Container1, typename Container2>
value_type<Container1> squared_distance(const Container1& left, const Container2& right)
{
    assert(left.size() == right.size());
    using std::begin;
    using std::end;
    return squared_distance(begin(left), end(left), begin(right));
}

/** The Taxicab distance of two vectors.
Each vector is represented by a container.
The two containers should have the same size and value type.
*/
template<typename Container1, typename Container2>
value_type<Container1> distance(const Container1& left, const Container2& right)
{
    assert(left.size() == right.size());
    using std::begin;
    using std::end;
    return distance(begin(left), end(left), begin(right));
}

/** @} */

} // namespace taxicab
} // namespace aaa
