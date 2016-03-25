#pragma once

#include <algorithm>
#include <functional>

namespace aaa {

/**
@defgroup logical_range Logical Operations on Ranges

@{
*/

template<typename InputIterator1, typename InputIterator2, typename OutputIterator>
void logical_and(InputIterator1 first_left, InputIterator1 last_left, InputIterator2 first_right, OutputIterator first_out)
{
    std::transform(first_left, last_left, first_right, first_out, std::logical_and<bool>());
}

template<typename InputIterator1, typename InputIterator2, typename OutputIterator>
void logical_or(InputIterator1 first_left, InputIterator1 last_left, InputIterator2 first_right, OutputIterator first_out)
{
    std::transform(first_left, last_left, first_right, first_out, std::logical_or<bool>());
}

template<typename InputIterator, typename OutputIterator>
void logical_not(InputIterator first_in, InputIterator last_in, OutputIterator first_out)
{
    std::transform(first_in, last_in, first_out, std::logical_not<bool>());
}

/** @} */

} // namespace aaa
