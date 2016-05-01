#pragma once

#include <cassert>

#include "vector_space_container.hpp"
#include "traits.hpp"

namespace aaa {

template<typename Container>
Container negate(const Container& in)
{
    auto out = in;
    negate(in, out);
    return out;
}

////////////////////////////////////////////////////////////////////////////////
// add

template<typename Container>
Container add(const Container& left, const Container& right)
{
    auto out = left;
    add(left, right, out);
    return out;
}

template<typename Container>
Container add(const Container& left, const value_type<Container>& right)
{
    auto out = left;
    add(left, right, out);
    return out;
}

template<typename Container>
Container add(const value_type<Container>& left, const Container& right)
{
    auto out = right;
    add(left, right, out);
    return out;
}

////////////////////////////////////////////////////////////////////////////////
// subtract

template<typename Container>
Container subtract(const Container& left, const Container& right)
{
    auto out = left;
    subtract(left, right, out);
    return out;
}

template<typename Container>
Container subtract(const Container& left, const value_type<Container>& right)
{
    auto out = left;
    subtract(left, right, out);
    return out;
}

template<typename Container>
Container subtract(const value_type<Container>& left, const Container& right)
{
    auto out = right;
    subtract(left, right, out);
    return out;
}

////////////////////////////////////////////////////////////////////////////////
// multiply

template<typename Container>
Container multiply(const Container& left, const Container& right)
{
    auto out = left;
    multiply(left, right, out);
    return out;
}

template<typename Container>
Container multiply(const Container& left, const value_type<Container>& right)
{
    auto out = left;
    multiply(left, right, out);
    return out;
}

template<typename Container>
Container multiply(const value_type<Container>& left, const Container& right)
{
    auto out = right;
    multiply(left, right, out);
    return out;
}

////////////////////////////////////////////////////////////////////////////////
// divide

template<typename Container>
Container divide(const Container& left, const Container& right)
{
    auto out = left;
    divide(left, right, out);
    return out;
}

template<typename Container>
Container divide(const Container& left, const value_type<Container>& right)
{
    auto out = left;
    divide(left, right, out);
    return out;
}

template<typename Container>
Container divide(const value_type<Container>& left, const Container& right)
{
    auto out = right;
    divide(left, right, out);
    return out;
}

} // namespace aaa
