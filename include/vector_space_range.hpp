#pragma once

#include <algorithm>

#include "traits.hpp"

namespace aaa {

/**
@defgroup vector_space_range Vector Space Operations on Ranges

This module defines the functions:
- `add`
- `subtract`
- `negate`
- `multiply`
- `divide`

They do elementwise arithmetic operations on ranges. This module supports
expressions on the general form `binary_operation(input_left, input_right, output)`
where:
- The `binary_operation` is one of `add`, `subtract`, `multiply`, `divide`.
- The `output` is a range represented by a single iterator to the first element.
- At least one of `input_left` and `input_right` is a range of two iterators.
  The other is either a scalar or a range with a single iterator to the first element.

We call these **vector space operations** since a mathematical vector space has the
following elementwise operations defined:
- addition of two vectors.
- subtraction of two vectors.
- negation of a vector.
- multiplication of a vector and a scalar.
- division of a vector and a scalar.

We represent mathematical vectors as ranges.

@{
*/

template<typename InputIterator, typename OutputIterator>
void negate(InputIterator first_in, InputIterator last_in, OutputIterator first_out)
{
    auto f = [](const value_type_i<InputIterator>& in) { return -in; };
    std::transform(first_in, last_in, first_out, f);
}

////////////////////////////////////////////////////////////////////////////////
// add

template<typename InputIterator1, typename InputIterator2, typename OutputIterator,
    check_sum<value_type_i<InputIterator1>, value_type_i<InputIterator2>, value_type_i<OutputIterator>> = nullptr>
void add(InputIterator1 first_left, InputIterator1 last_left, InputIterator2 first_right, OutputIterator first_out)
{
    auto f = [](const value_type_i<InputIterator1>& left, const value_type_i<InputIterator2>& right)
    {
        return left + right;
    };
    std::transform(first_left, last_left, first_right, first_out, f);
}

template<typename Element, typename InputIterator, typename OutputIterator,
    check_sum<Element, value_type_i<InputIterator>, value_type_i<OutputIterator>> = nullptr>
void add(const Element& left, InputIterator first_right, InputIterator last_right, OutputIterator first_out)
{
    auto f = [&](const value_type_i<InputIterator>& right) { return left + right; };
    std::transform(first_right, last_right, first_out, f);
}

template<typename InputIterator, typename Element, typename OutputIterator,
    check_sum<value_type_i<InputIterator>, Element, value_type_i<OutputIterator>> = nullptr>
void add(InputIterator first_left, InputIterator last_left, const Element& right, OutputIterator first_out)
{
    auto f = [&](const value_type_i<InputIterator>& left) { return left + right; };
    std::transform(first_left, last_left, first_out, f);
}

////////////////////////////////////////////////////////////////////////////////
// subtract

template<typename InputIterator1, typename InputIterator2, typename OutputIterator,
    check_difference<value_type_i<InputIterator1>, value_type_i<InputIterator2>, value_type_i<OutputIterator>> = nullptr>
void subtract(InputIterator1 first_left, InputIterator1 last_left, InputIterator2 first_right, OutputIterator first_out)
{
    auto f = [](const value_type_i<InputIterator1>& left, const value_type_i<InputIterator2>& right)
    {
        return left - right;
    };
    std::transform(first_left, last_left, first_right, first_out, f);
}

template<typename Element, typename InputIterator, typename OutputIterator,
    check_difference<Element, value_type_i<InputIterator>, value_type_i<OutputIterator>> = nullptr>
void subtract(const Element& left, InputIterator first_right, InputIterator last_right, OutputIterator first_out)
{
    auto f = [&](const value_type_i<InputIterator>& right) { return left - right; };
    std::transform(first_right, last_right, first_out, f);
}

template<typename InputIterator, typename Element, typename OutputIterator,
    check_difference<value_type_i<InputIterator>, Element, value_type_i<OutputIterator>> = nullptr>
void subtract(InputIterator first_left, InputIterator last_left, const Element& right, OutputIterator first_out)
{
    auto f = [&](const value_type_i<InputIterator>& left) { return left - right; };
    std::transform(first_left, last_left, first_out, f);
}

////////////////////////////////////////////////////////////////////////////////
// multiply

template<typename InputIterator1, typename InputIterator2, typename OutputIterator,
    check_product<value_type_i<InputIterator1>, value_type_i<InputIterator2>, value_type_i<OutputIterator>> = nullptr>
void multiply(InputIterator1 first_left, InputIterator1 last_left, InputIterator2 first_right, OutputIterator first_out)
{
    auto f = [](const value_type_i<InputIterator1>& left, const value_type_i<InputIterator2>& right)
    {
        return left * right;
    };
    std::transform(first_left, last_left, first_right, first_out, f);
}

template<typename Element, typename InputIterator, typename OutputIterator,
    check_product<Element, value_type_i<InputIterator>, value_type_i<OutputIterator>> = nullptr>
void multiply(const Element& left, InputIterator first_right, InputIterator last_right, OutputIterator first_out)
{
    auto f = [&](const value_type_i<InputIterator>& right) { return left * right; };
    std::transform(first_right, last_right, first_out, f);
}

template<typename InputIterator, typename Element, typename OutputIterator,
    check_product<value_type_i<InputIterator>, Element, value_type_i<OutputIterator>> = nullptr>
void multiply(InputIterator first_left, InputIterator last_left, const Element& right, OutputIterator first_out)
{
    auto f = [&](const value_type_i<InputIterator>& left) { return left * right; };
    std::transform(first_left, last_left, first_out, f);
}

////////////////////////////////////////////////////////////////////////////////
// divide

template<typename InputIterator1, typename InputIterator2, typename OutputIterator,
    check_ratio<value_type_i<InputIterator1>, value_type_i<InputIterator2>, value_type_i<OutputIterator>> = nullptr>
void divide(InputIterator1 first_left, InputIterator1 last_left, InputIterator2 first_right, OutputIterator first_out)
{
    auto f = [](const value_type_i<InputIterator1>& left, const value_type_i<InputIterator2>& right)
    {
        return left / right;
    };
    std::transform(first_left, last_left, first_right, first_out, f);
}

template<typename Element, typename InputIterator, typename OutputIterator,
    check_ratio<Element, value_type_i<InputIterator>, value_type_i<OutputIterator>> = nullptr>
void divide(const Element& left, InputIterator first_right, InputIterator last_right, OutputIterator first_out)
{
    auto f = [&](const value_type_i<InputIterator>& right) { return left / right; };
    std::transform(first_right, last_right, first_out, f);
}

template<typename InputIterator, typename Element, typename OutputIterator,
    check_ratio<value_type_i<InputIterator>, Element, value_type_i<OutputIterator>> = nullptr>
void divide(InputIterator first_left, InputIterator last_left, const Element& right, OutputIterator first_out)
{
    auto f = [&](const value_type_i<InputIterator>& left) { return left / right; };
    std::transform(first_left, last_left, first_out, f);
}

/** @} */

} // namespace aaa
