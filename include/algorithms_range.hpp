#pragma once

#include <numeric>

#include "traits.hpp"

namespace aaa {

template<typename InIterator, typename OutIterator>
void convert(InIterator first_in, InIterator last_in, OutIterator first_out)
{
	auto f = [](value_type_i<InIterator> x) { return value_type_i<OutIterator>(x); };
	std::transform(first_in, last_in, first_out, f);
}

template<typename InIterator>
value_type_i<InIterator> sum(InIterator first, InIterator last)
{
	const auto zero = value_type_i<InIterator>();
	return std::accumulate(first, last, zero);
}

} // namespace aaa
