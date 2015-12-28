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
value_type_i<Iterator> norm(Iterator begin, Iterator end)
{
	const auto norm_double = sqrt(squared_norm(begin, end));
	return static_cast<value_type_i<Iterator>>(norm_double);
}
