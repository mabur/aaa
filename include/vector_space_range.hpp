/**
@defgroup vector_space_range Vector Space Operations on Ranges

This module defines the functions:
- `add`
- `subtract`
- `multiply`
- `divide`

They do elementwise arithmetic operations on ranges. This module supports
expressions on the general form `binary_operation(input_left, input_right, output)`
where:
- The `binary_operation` is one of `add`, `subtract`, `multiply`, `divide`.
- The `output` is a range represented by a single iterator to the first element.
- At least one of `input_left` and `input_right` is a range of two iterators.
The other is either a scalar or a range with a single iterator to the first element.

We call these **vector space operations** since a mathematical vector space has the
following elementwise operations defined:
- addition of two vectors.
- subtraction of two vectors.
- multiplication of a vector and a scalar.
- division of a vector and a scalar.

We represent mathematical vectors as ranges.

@{
*/

#pragma once

#include <algorithm>

#include "traits.hpp"

////////////////////////////////////////////////////////////////////////////////
// add

template<typename IteratorIn1, typename IteratorIn2, typename IteratorOut,
	check_sum<value_type_i<IteratorIn1>, value_type_i<IteratorIn2>, value_type_i<IteratorOut>> = 0>
void add(IteratorIn1 left_begin, IteratorIn1 left_end, IteratorIn2 right_begin, IteratorOut out_begin)
{
	auto f = [](const auto& left, const auto& right) { return left + right; };
	std::transform(left_begin, left_end, right_begin, out_begin, f);
}

template<typename ElementIn, typename IteratorIn, typename IteratorOut,
	check_sum<ElementIn, value_type_i<IteratorIn>, value_type_i<IteratorOut>> = 0>
void add(const ElementIn& left, IteratorIn right_begin, IteratorIn right_end, IteratorOut out_begin)
{
	auto f = [&](const auto& right) { return left + right; };
	std::transform(right_begin, right_end, out_begin, f);
}

template<typename IteratorIn, typename ElementIn, typename IteratorOut,
	check_sum<value_type_i<IteratorIn>, ElementIn, value_type_i<IteratorOut>> = 0>
void add(IteratorIn left_begin, IteratorIn left_end, const ElementIn& right, IteratorOut out_begin)
{
	auto f = [&](const auto& left) { return left + right; };
	std::transform(left_begin, left_end, out_begin, f);
}

////////////////////////////////////////////////////////////////////////////////
// subtract

template<typename IteratorIn1, typename IteratorIn2, typename IteratorOut,
	check_difference<value_type_i<IteratorIn1>, value_type_i<IteratorIn2>, value_type_i<IteratorOut>> = 0>
void subtract(IteratorIn1 left_begin, IteratorIn1 left_end, IteratorIn2 right_begin, IteratorOut out_begin)
{
	auto f = [](const auto& left, const auto& right) { return left - right; };
	std::transform(left_begin, left_end, right_begin, out_begin, f);
}

template<typename ElementIn, typename IteratorIn, typename IteratorOut,
	check_difference<ElementIn, value_type_i<IteratorIn>, value_type_i<IteratorOut>> = 0>
void subtract(const ElementIn& left, IteratorIn right_begin, IteratorIn right_end, IteratorOut out_begin)
{
	auto f = [&](const auto& right) { return left - right; };
	std::transform(right_begin, right_end, out_begin, f);
}

template<typename IteratorIn, typename ElementIn, typename IteratorOut,
	check_difference<value_type_i<IteratorIn>, ElementIn, value_type_i<IteratorOut>> = 0>
void subtract(IteratorIn left_begin, IteratorIn left_end, const ElementIn& right, IteratorOut out_begin)
{
	auto f = [&](const auto& left) { return left - right; };
	std::transform(left_begin, left_end, out_begin, f);
}

////////////////////////////////////////////////////////////////////////////////
// multiply

template<typename IteratorIn1, typename IteratorIn2, typename IteratorOut,
	check_product<value_type_i<IteratorIn1>, value_type_i<IteratorIn2>, value_type_i<IteratorOut>> = 0>
void multiply(IteratorIn1 left_begin, IteratorIn1 left_end, IteratorIn2 right_begin, IteratorOut out_begin)
{
	auto f = [](const auto& left, const auto& right) { return left * right; };
	std::transform(left_begin, left_end, right_begin, out_begin, f);
}

template<typename ElementIn, typename IteratorIn, typename IteratorOut,
	check_product<ElementIn, value_type_i<IteratorIn>, value_type_i<IteratorOut>> = 0>
void multiply(const ElementIn& left, IteratorIn right_begin, IteratorIn right_end, IteratorOut out_begin)
{
	auto f = [&](const auto& right) { return left * right; };
	std::transform(right_begin, right_end, out_begin, f);
}

template<typename IteratorIn, typename ElementIn, typename IteratorOut,
	check_product<value_type_i<IteratorIn>, ElementIn, value_type_i<IteratorOut>> = 0>
void multiply(IteratorIn left_begin, IteratorIn left_end, const ElementIn& right, IteratorOut out_begin)
{
	auto f = [&](const auto& left) { return left * right; };
	std::transform(left_begin, left_end, out_begin, f);
}

////////////////////////////////////////////////////////////////////////////////
// divide

template<typename IteratorIn1, typename IteratorIn2, typename IteratorOut,
	check_ratio<value_type_i<IteratorIn1>, value_type_i<IteratorIn2>, value_type_i<IteratorOut>> = 0>
void divide(IteratorIn1 left_begin, IteratorIn1 left_end, IteratorIn2 right_begin, IteratorOut out_begin)
{
	auto f = [](const auto& left, const auto& right) { return left / right; };
	std::transform(left_begin, left_end, right_begin, out_begin, f);
}

template<typename ElementIn, typename IteratorIn, typename IteratorOut,
	check_ratio<ElementIn, value_type_i<IteratorIn>, value_type_i<IteratorOut>> = 0>
void divide(const ElementIn& left, IteratorIn right_begin, IteratorIn right_end, IteratorOut out_begin)
{
	auto f = [&](const auto& right) { return left / right; };
	std::transform(right_begin, right_end, out_begin, f);
}

template<typename IteratorIn, typename ElementIn, typename IteratorOut,
	check_ratio<value_type_i<IteratorIn>, ElementIn, value_type_i<IteratorOut>> = 0>
void divide(IteratorIn left_begin, IteratorIn left_end, const ElementIn& right, IteratorOut out_begin)
{
	auto f = [&](const auto& left) { return left / right; };
	std::transform(left_begin, left_end, out_begin, f);
}
