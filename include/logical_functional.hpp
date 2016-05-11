#pragma once

#include "logical_range.hpp"

namespace aaa {

/**
@defgroup logical_functional Logical Operations returning Containers

@{
*/

template<typename Container>
Container logical_and(const Container& left, const Container& right)
{
    auto out = left;
    logical_and(left, right, out);
    return out;
}

template<typename Container>
Container logical_or(const Container& left, const Container& right)
{
    auto out = left;
    logical_or(left, right, out);
    return out;
}

template<typename Container>
Container logical_not(const Container& in)
{
    auto out = in;
    logical_not(in, out);
    return out;
}

/** @} */

} // namespace aaa
