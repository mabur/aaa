#pragma once

#include <cassert>

#include "inner_product_space_operations_range.hpp"

template<typename Container1, typename Container2, typename Value>
Value inner_product(const Container1& a, Container2& b, const Value& start_value)
{
	assert(size(a) == size(b));
	using std::begin;
	using std::end;
	return std::inner_product(begin(a), end(a), begin(b), start_value);
}

template<typename Container1, typename Container2>
typename Container1::value_type dot(const Container1& a, Container2& b)
{
	assert(size(a) == size(b));
	using std::begin;
	using std::end;
	return dot(begin(a), end(a), begin(b));
}

template<typename Container>
typename Container::value_type squared_norm(const Container& a)
{
	using std::begin;
	using std::end;
	return squared_norm(begin(a), end(a));
}

template<typename Container>
typename Container::value_type norm(const Container& a)
{
	using std::begin;
	using std::end;
	return norm(begin(a), end(a));
}
