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

template<typename InIteratorLeft, typename InIteratorRight, typename OutIterator,
	check_sum<value_type_i<InIteratorLeft>, value_type_i<InIteratorRight>, value_type_i<OutIterator>> = 0>
void add(InIteratorLeft first_left, InIteratorLeft last_left, InIteratorRight first_right, OutIterator first_out)
{
	auto f = [](const value_type_i<InIteratorLeft>& left, const value_type_i<InIteratorRight>& right)
    {
        return left + right;
    };
	std::transform(first_left, last_left, first_right, first_out, f);
}

template<typename Element, typename InIterator, typename OutIterator,
	check_sum<Element, value_type_i<InIterator>, value_type_i<OutIterator>> = 0>
void add(const Element& left, InIterator first_right, InIterator last_right, OutIterator first_out)
{
	auto f = [&](const value_type_i<InIterator>& right) { return left + right; };
	std::transform(first_right, last_right, first_out, f);
}

template<typename InIterator, typename Element, typename OutIterator,
	check_sum<value_type_i<InIterator>, Element, value_type_i<OutIterator>> = 0>
void add(InIterator first_left, InIterator last_left, const Element& right, OutIterator first_out)
{
	auto f = [&](const value_type_i<InIterator>& left) { return left + right; };
	std::transform(first_left, last_left, first_out, f);
}

////////////////////////////////////////////////////////////////////////////////
// subtract

template<typename InIteratorLeft, typename InIteratorRight, typename OutIterator,
	check_difference<value_type_i<InIteratorLeft>, value_type_i<InIteratorRight>, value_type_i<OutIterator>> = 0>
void subtract(InIteratorLeft first_left, InIteratorLeft last_left, InIteratorRight first_right, OutIterator first_out)
{
    auto f = [](const value_type_i<InIteratorLeft>& left, const value_type_i<InIteratorRight>& right)
    {
        return left - right;
    };
	std::transform(first_left, last_left, first_right, first_out, f);
}

template<typename Element, typename InIterator, typename OutIterator,
	check_difference<Element, value_type_i<InIterator>, value_type_i<OutIterator>> = 0>
void subtract(const Element& left, InIterator first_right, InIterator last_right, OutIterator first_out)
{
	auto f = [&](const value_type_i<InIterator>& right) { return left - right; };
	std::transform(first_right, last_right, first_out, f);
}

template<typename InIterator, typename Element, typename OutIterator,
	check_difference<value_type_i<InIterator>, Element, value_type_i<OutIterator>> = 0>
void subtract(InIterator first_left, InIterator last_left, const Element& right, OutIterator first_out)
{
	auto f = [&](const value_type_i<InIterator>& left) { return left - right; };
	std::transform(first_left, last_left, first_out, f);
}

////////////////////////////////////////////////////////////////////////////////
// multiply

template<typename InIteratorLeft, typename InIteratorRight, typename OutIterator,
	check_product<value_type_i<InIteratorLeft>, value_type_i<InIteratorRight>, value_type_i<OutIterator>> = 0>
void multiply(InIteratorLeft first_left, InIteratorLeft last_left, InIteratorRight first_right, OutIterator first_out)
{
    auto f = [](const value_type_i<InIteratorLeft>& left, const value_type_i<InIteratorRight>& right)
    {
        return left * right;
    };
	std::transform(first_left, last_left, first_right, first_out, f);
}

template<typename Element, typename InIterator, typename OutIterator,
	check_product<Element, value_type_i<InIterator>, value_type_i<OutIterator>> = 0>
void multiply(const Element& left, InIterator first_right, InIterator last_right, OutIterator first_out)
{
	auto f = [&](const value_type_i<InIterator>& right) { return left * right; };
	std::transform(first_right, last_right, first_out, f);
}

template<typename InIterator, typename Element, typename OutIterator,
	check_product<value_type_i<InIterator>, Element, value_type_i<OutIterator>> = 0>
void multiply(InIterator first_left, InIterator last_left, const Element& right, OutIterator first_out)
{
	auto f = [&](const value_type_i<InIterator>& left) { return left * right; };
	std::transform(first_left, last_left, first_out, f);
}

////////////////////////////////////////////////////////////////////////////////
// divide

template<typename InIteratorLeft, typename InIteratorRight, typename OutIterator,
	check_ratio<value_type_i<InIteratorLeft>, value_type_i<InIteratorRight>, value_type_i<OutIterator>> = 0>
void divide(InIteratorLeft first_left, InIteratorLeft last_left, InIteratorRight first_right, OutIterator first_out)
{
    auto f = [](const value_type_i<InIteratorLeft>& left, const value_type_i<InIteratorRight>& right)
    {
        return left / right;
    };
	std::transform(first_left, last_left, first_right, first_out, f);
}

template<typename Element, typename InIterator, typename OutIterator,
	check_ratio<Element, value_type_i<InIterator>, value_type_i<OutIterator>> = 0>
void divide(const Element& left, InIterator first_right, InIterator last_right, OutIterator first_out)
{
	auto f = [&](const value_type_i<InIterator>& right) { return left / right; };
	std::transform(first_right, last_right, first_out, f);
}

template<typename InIterator, typename Element, typename OutIterator,
	check_ratio<value_type_i<InIterator>, Element, value_type_i<OutIterator>> = 0>
void divide(InIterator first_left, InIterator last_left, const Element& right, OutIterator first_out)
{
	auto f = [&](const value_type_i<InIterator>& left) { return left / right; };
	std::transform(first_left, last_left, first_out, f);
}
