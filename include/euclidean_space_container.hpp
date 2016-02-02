#pragma once

#include <cassert>

#include "euclidean_space_range.hpp"

namespace aaa {

/**
@defgroup euclidean_space_container Euclidean Space Operations on Containers

An Euclidean vector space defines the following:
- the Euclidean norm of a vector, which also known as its length.
- the dot product of two vectors. This is also known as the scalar product or
  Euclidean inner product.
- the Euclidean distance between two vectors.

We represent mathematical vectors as arbitrary containers.

@{
*/

/** The dot product of two vectors.
Each vector is represented by a container.
The two containers should have the same size and value type.
*/
template<typename Container1, typename Container2>
value_type<Container1> dot(const Container1& a, Container2& b)
{
	assert(a.size() == b.size());
	using std::begin;
	using std::end;
	return dot(begin(a), end(a), begin(b));
}

/** The squared Euclidean norm of a vector.
The vector is represented by an arbitrary container.
*/
template<typename Container>
value_type<Container> squared_norm(const Container& a)
{
	using std::begin;
	using std::end;
	return squared_norm(begin(a), end(a));
}

/** The Euclidean norm of a vector.
The vector is represented by an arbitrary container.
Returns a floating point type, i.e. it follows the same convention as `std::sqrt`.
*/
template<typename Container>
sqrt_value_type<Container> norm(const Container& a)
{
	using std::begin;
	using std::end;
	return norm(begin(a), end(a));
}

// TODO: assert that we pass in containers. Don't mix with std::distance that
// takes two iterators.

/** The Euclidean distance of two vectors.
Each vector is represented by a container.
The two containers should have the same size and value type.
Returns a floating point type, i.e. it follows the same convention as `std::sqrt`.
*/
template<typename Container1, typename Container2>
sqrt_value_type<Container1> distance(const Container1& left, const Container2& right)
{
	assert(left.size() == right.size());
	using std::begin;
	using std::end;
	return distance(begin(left), end(left), begin(right));
}

/** @} */

} // namespace aaa
