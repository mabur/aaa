#pragma once

#include <cassert>

#include "vector_space_container.hpp"
#include "traits.hpp"

namespace aaa {

/**
@defgroup vector_space_functional Vector Space Operations returning Containers

This module defines the functions:
- `add`
- `subtract`
- `negate`
- `multiply`
- `divide`

They do elementwise arithmetic operations on containers. This module supports
expressions on the general form `output = binary_operation(input_left, input_right)`
where:
- The `binary_operation` is one of `add`, `subtract`, `multiply`, `divide`.
- The `output` is a container.
- At least one of `input_left` and `input_right` is a container.
The other could be a scalar.

We call these **vector space operations** since a mathematical vector space has the
following elementwise operations defined:
- addition of two vectors.
- subtraction of two vectors.
- negation of a vector.
- multiplication of a vector and a scalar.
- division of a vector and a scalar.

We represent mathematical vectors as containers.

@{
*/

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

/** @} */

} // namespace aaa
