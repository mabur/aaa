#pragma once

#include <numeric>

#include "traits.hpp"

template<typename IteratorIn, typename IteratorOut>
void convert(IteratorIn in_begin, IteratorIn in_end, IteratorOut out_begin)
{
	auto f = [](auto x) { return value_type_i<IteratorOut>(x); };
	std::transform(in_begin, in_end, out_begin, f);
}

template<typename Iterator>
value_type_i<Iterator> sum(Iterator begin, Iterator end)
{
	const auto zero = value_type_i<Iterator>();
	return std::accumulate(begin, end, zero);
}
