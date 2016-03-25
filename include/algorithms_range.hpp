#pragma once

#include <numeric>

#include "traits.hpp"

namespace aaa {

/**
@defgroup algorithms_range Misc Operations on Ranges

@{
*/

template<typename InputIterator, typename OutputIterator>
void convert(InputIterator first_in, InputIterator last_in, OutputIterator first_out)
{
    auto f = [](value_type_i<InputIterator> x) { return value_type_i<OutputIterator>(x); };
    std::transform(first_in, last_in, first_out, f);
}

template<typename InputIterator>
value_type_i<InputIterator> sum(InputIterator first, InputIterator last)
{
    const auto zero = value_type_i<InputIterator>();
    return std::accumulate(first, last, zero);
}

/** @} */

} // namespace aaa
