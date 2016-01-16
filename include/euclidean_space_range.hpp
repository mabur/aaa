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

template<typename InIterator1, typename InIterator2>
value_type_i<InIterator1> dot(InIterator1 first_left, InIterator1 last_left, InIterator2 first_right)
{
	using value_type1 = const value_type_i<InIterator1>;
	using value_type2 = const value_type_i<InIterator2>;
	static_assert(std::is_same<value_type1, value_type2>::value, "Different value types");

	const auto zero = value_type1();
	return std::inner_product(first_left, last_left, first_right, zero);
}

template<typename InIterator>
value_type_i<InIterator> squared_norm(InIterator first, InIterator last)
{
	return dot(first, last, first);
}

template<typename InIterator>
sqrt_value_type_i<InIterator> norm(InIterator first, InIterator last)
{
	return sqrt(squared_norm(first, last));
}

template<typename InIterator1, typename InIterator2>
sqrt_value_type_i<InIterator1>
distance(InIterator1 first_left, InIterator1 last_left, InIterator2 first_right)
{
	using value_type1 = const value_type_i<InIterator1>;
	using value_type2 = const value_type_i<InIterator2>;
	static_assert(std::is_same<value_type1, value_type2>::value, "Different value types");

	const auto zero = value_type1();
	auto op1 = [](const auto& left, const auto& right)
	{
		return left + right;
	};
	auto op2 = [](const auto& left, const auto& right)
	{
		return (left - right) * (left - right);
	};
	return sqrt(std::inner_product(first_left, last_left, first_right, zero, op1, op2));
}

/** @} */
