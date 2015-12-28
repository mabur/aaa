#pragma once

#include <cassert>
#include <numeric>

#include "algorithms_range.hpp"
#include "traits.hpp"

template<typename ContainerIn, typename ContainerOut>
void convert(const ContainerIn& in, ContainerOut& out)
{
	using std::begin;
	using std::end;
	return convert(begin(in), end(in), begin(out));
}

template<typename Container>
value_type<Container> sum(const Container& container)
{
	using std::begin;
	using std::end;
	return sum(begin(container), end(container));
}
