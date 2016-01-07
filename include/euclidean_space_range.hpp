/**
@defgroup euclidean_space_ranges Euclidean Space perations on Ranges

An Euclidean vector space defines the following:
- the length or Euclidean norm of a vector.
- the dot product of two vectors. This is also known as the scalar product or
Euclidean inner product.
- the distance between two vectors.

We represent mathematical vectors as ranges of iterators.

@{
*/

#pragma once

#include <numeric>

#include "traits.hpp"

template<typename IteratorLeft, typename IteratorRight>
value_type_i<IteratorLeft> dot(IteratorLeft left_begin, IteratorLeft left_end, IteratorRight right_begin)
{
	using value_type_left  = const value_type_i<IteratorLeft>;
	using value_type_right = const value_type_i<IteratorRight>;
	static_assert(std::is_same<value_type_left, value_type_right>::value, "Different value types");

	const auto zero = value_type_left();
	return std::inner_product(left_begin, left_end, right_begin, zero);
}

template<typename Iterator>
value_type_i<Iterator> squared_norm(Iterator begin, Iterator end)
{
	return dot(begin, end, begin);
}

template<typename Iterator>
sqrt_value_type_i<Iterator> norm(Iterator begin, Iterator end)
{
	return sqrt(squared_norm(begin, end));
}

template<typename IteratorLeft, typename IteratorRight>
sqrt_value_type_i<IteratorLeft>
distance(IteratorLeft left_begin, IteratorLeft left_end, IteratorRight right_begin)
{
	using value_type_left = const value_type_i<IteratorLeft>;
	using value_type_right = const value_type_i<IteratorRight>;
	using value_type = value_type_left;
	static_assert(std::is_same<value_type_left, value_type_right>::value,
        "Different value types");

	const auto zero = value_type();
	auto op1 = [](const auto& left, const auto& right)
	{
		return left + right;
	};
	auto op2 = [](const auto& left, const auto& right)
	{
		return (left - right) * (left - right);
	};
	return sqrt(std::inner_product(left_begin, left_end, right_begin, zero, op1, op2));
}

/** @} */
