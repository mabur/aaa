#pragma once

#include <cassert>

#include "euclidean_space_range.hpp"

template<typename Container1, typename Container2>
value_type<Container1> dot(const Container1& a, Container2& b)
{
	assert(size(a) == size(b));
	using std::begin;
	using std::end;
	return dot(begin(a), end(a), begin(b));
}

template<typename Container>
value_type<Container> squared_norm(const Container& a)
{
	using std::begin;
	using std::end;
	return squared_norm(begin(a), end(a));
}

template<typename Container>
sqrt_type_t<value_type<Container>> norm(const Container& a)
{
	using std::begin;
	using std::end;
	return norm(begin(a), end(a));
}

// TODO: assert that we pass in containers. Don't mix with std::distance that
// takes two iterators.
template<typename ContainerLeft, typename ContainerRight>
sqrt_type_t<value_type<ContainerLeft>>
distance(const ContainerLeft& left, const ContainerRight& right)
{
	assert(left.size() == right.size());
	using std::begin;
	using std::end;
	return distance(begin(left), end(left), begin(right));
}