/**
@defgroup vector_space_container Vector Space Operations on Containers

This module defines the functions:
- `add`
- `subtract`
- `multiply`
- `divide`

They do elementwise arithmetic operations on containers. This module supports
expressions on the general form `binary_operation(input_left, input_right, output)`
where:
- The `binary_operation` is one of `add`, `subtract`, `multiply`, `divide`.
- The `output` is a container.
- At least one of `input_left` and `input_right` is a container.
  The other could be a scalar.

We call these **vector space operations** since a mathematical vector space has the
following elementwise operations defined:
- addition of two vectors.
- subtraction of two vectors.
- multiplication of a vector and a scalar.
- division of a vector and a scalar.

We represent mathematical vectors as containers.

@{
*/

#pragma once

#include <cassert>

#include "vector_space_range.hpp"
#include "traits.hpp"

////////////////////////////////////////////////////////////////////////////////
// add

template<typename ContainerIn1, typename ContainerIn2, typename ContainerOut,
	typename check_sum<value_type<ContainerIn1>, value_type<ContainerIn2>, value_type<ContainerOut>> = 0>
void add(const ContainerIn1& left, const ContainerIn2& right, ContainerOut& out)
{
	assert(left.size() == out.size());
	assert(right.size() == out.size());
	using std::begin;
	using std::end;
	add(begin(left), end(left), begin(right), begin(out));
}

template<typename ElementIn, typename ContainerIn, typename ContainerOut,
	typename check_sum<ElementIn, value_type<ContainerIn>, value_type<ContainerOut>> = 0>
void add(const ElementIn& left, const ContainerIn& right, ContainerOut& out)
{
	assert(right.size() == out.size());
	using std::begin;
	using std::end;
	add(left, begin(right), end(right), begin(out));
}

template<typename ContainerIn, typename ElementIn, typename ContainerOut,
	typename check_sum<value_type<ContainerIn>, ElementIn, value_type<ContainerOut>> = 0>
void add(const ContainerIn& left, const ElementIn& right, ContainerOut& out)
{
	assert(left.size() == out.size());
	using std::begin;
	using std::end;
	add(begin(left), end(left), right, begin(out));
}

////////////////////////////////////////////////////////////////////////////////
// subtract

template<typename ContainerIn1, typename ContainerIn2, typename ContainerOut,
	typename check_difference<value_type<ContainerIn1>, value_type<ContainerIn2>, value_type<ContainerOut>> = 0>
void subtract(const ContainerIn1& left, const ContainerIn2& right, ContainerOut& out)
{
	assert(left.size() == out.size());
	assert(right.size() == out.size());
	using std::begin;
	using std::end;
	subtract(begin(left), end(left), begin(right), begin(out));
}

template<typename ElementIn, typename ContainerIn, typename ContainerOut,
	typename check_difference<ElementIn, value_type<ContainerIn>, value_type<ContainerOut>> = 0>
void subtract(const ElementIn& left, const ContainerIn& right, ContainerOut& out)
{
	assert(right.size() == out.size());
	using std::begin;
	using std::end;
	subtract(left, begin(right), end(right), begin(out));
}

template<typename ContainerIn, typename ElementIn, typename ContainerOut,
	typename check_difference<value_type<ContainerIn>, ElementIn, value_type<ContainerOut>> = 0>
void subtract(const ContainerIn& left, const ElementIn& right, ContainerOut& out)
{
	assert(left.size() == out.size());
	using std::begin;
	using std::end;
	subtract(begin(left), end(left), right, begin(out));
}

////////////////////////////////////////////////////////////////////////////////
// multiply

template<typename ContainerIn1, typename ContainerIn2, typename ContainerOut,
	typename check_product<value_type<ContainerIn1>, value_type<ContainerIn2>, value_type<ContainerOut>> = 0>
void multiply(const ContainerIn1& left, const ContainerIn2& right, ContainerOut& out)
{
	assert(left.size() == out.size());
	assert(right.size() == out.size());
	using std::begin;
	using std::end;
	multiply(begin(left), end(left), begin(right), begin(out));
}

template<typename ElementIn, typename ContainerIn, typename ContainerOut,
	typename check_product<ElementIn, value_type<ContainerIn>, value_type<ContainerOut>> = 0>
void multiply(const ElementIn& left, const ContainerIn& right, ContainerOut& out)
{
	assert(right.size() == out.size());
	using std::begin;
	using std::end;
	multiply(left, begin(right), end(right), begin(out));
}

template<typename ContainerIn, typename ElementIn, typename ContainerOut,
	typename check_product<value_type<ContainerIn>, ElementIn, value_type<ContainerOut>> = 0>
void multiply(const ContainerIn& left, const ElementIn& right, ContainerOut& out)
{
	assert(left.size() == out.size());
	using std::begin;
	using std::end;
	multiply(begin(left), end(left), right, begin(out));
}

////////////////////////////////////////////////////////////////////////////////
// divide

template<typename ContainerIn1, typename ContainerIn2, typename ContainerOut,
	typename check_ratio<value_type<ContainerIn1>, value_type<ContainerIn2>, value_type<ContainerOut>> = 0>
void divide(const ContainerIn1& left, const ContainerIn2& right, ContainerOut& out)
{
	assert(left.size() == out.size());
	assert(right.size() == out.size());
	using std::begin;
	using std::end;
	multiply(begin(left), end(left), begin(right), begin(out));
}

template<typename ElementIn, typename ContainerIn, typename ContainerOut,
	typename check_ratio<ElementIn, value_type<ContainerIn>, value_type<ContainerOut>> = 0>
void divide(const ElementIn& left, const ContainerIn& right, ContainerOut& out)
{
	assert(right.size() == out.size());
	using std::begin;
	using std::end;
	multiply(left, begin(right), end(right), begin(out));
}

template<typename ContainerIn, typename ElementIn, typename ContainerOut,
	typename check_ratio<value_type<ContainerIn>, ElementIn, value_type<ContainerOut>> = 0>
void divide(const ContainerIn& left, const ElementIn& right, ContainerOut& out)
{
	assert(left.size() == out.size());
	using std::begin;
	using std::end;
	multiply(begin(left), end(left), right, begin(out));
}

/** @} */
