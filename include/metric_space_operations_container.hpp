#pragma once

#include <cassert>
#include <numeric>

#include "metric_space_operations_range.hpp"
#include "traits.hpp"

// TODO: assert that we pass in containers. Don't mix with std::distance that
// takes two iterators.
template<typename ContainerLeft, typename ContainerRight>
value_type<ContainerLeft> distance(const ContainerLeft& left, const ContainerRight& right)
{
	assert(left.size() == right.size());
	using std::begin;
	using std::end;
	return distance(begin(left), end(left), begin(right));
}