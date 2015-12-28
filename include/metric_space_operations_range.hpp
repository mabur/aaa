#pragma once

#include <numeric>

template<typename IteratorLeft, typename IteratorRight>
value_type_i<IteratorLeft> distance(
	IteratorLeft left_begin, IteratorLeft left_end, IteratorRight right_begin)
{
	using value_type_left  = const value_type_i<IteratorLeft>;
	using value_type_right = const value_type_i<IteratorRight>;
	using value_type = value_type_left;
	static_assert(std::is_same<value_type_left, value_type_right>::value, "Different value types");

	const auto zero = value_type();
	auto op1 = [](const auto& left, const auto& right)
	{
		return left + right;
	};
	auto op2 = [](const auto& left, const auto& right)
	{
		return (left - right) * (left - right);
	};
	const auto distance_double = sqrt(std::inner_product(left_begin, left_end, right_begin, zero, op1, op2));
	return static_cast<value_type>(distance_double);
}