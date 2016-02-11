#pragma once

#include <cassert>

#include "vector_space_range.hpp"
#include "traits.hpp"

namespace aaa {

/**
@defgroup vector_space_container Vector Space Operations on Containers

This module defines the functions:
- `add`
- `subtract`
- `negate`
- `multiply`
- `divide`

They do elementwise arithmetic operations on containers. This module supports
expressions on the general form `binary_operation(input_left, input_right, output)`
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

template<typename Container1, typename Container2>
void negate(const Container1& in, Container2& out)
{
    assert(in.size() == out.size());
    using std::begin;
    using std::end;
    negate(begin(in), end(in), begin(out));
}

////////////////////////////////////////////////////////////////////////////////
// add

template<typename Container1, typename Container2, typename Container3,
    check_sum<value_type<Container1>, value_type<Container2>, value_type<Container3>> = 0>
void add(const Container1& left, const Container2& right, Container3& out)
{
    assert(left.size() == out.size());
    assert(right.size() == out.size());
    using std::begin;
    using std::end;
    add(begin(left), end(left), begin(right), begin(out));
}

template<typename Element, typename Container1, typename Container2,
    check_sum<Element, value_type<Container1>, value_type<Container2>> = 0>
void add(const Element& left, const Container1& right, Container2& out)
{
    assert(right.size() == out.size());
    using std::begin;
    using std::end;
    add(left, begin(right), end(right), begin(out));
}

template<typename Container1, typename Element, typename Container2,
    check_sum<value_type<Container1>, Element, value_type<Container2>> = 0>
void add(const Container1& left, const Element& right, Container2& out)
{
    assert(left.size() == out.size());
    using std::begin;
    using std::end;
    add(begin(left), end(left), right, begin(out));
}

////////////////////////////////////////////////////////////////////////////////
// subtract

template<typename Container1, typename Container2, typename Container3,
    check_difference<value_type<Container1>, value_type<Container2>, value_type<Container3>> = 0>
void subtract(const Container1& left, const Container2& right, Container3& out)
{
    assert(left.size() == out.size());
    assert(right.size() == out.size());
    using std::begin;
    using std::end;
    subtract(begin(left), end(left), begin(right), begin(out));
}

template<typename Element, typename Container1, typename Container2,
    check_difference<Element, value_type<Container1>, value_type<Container2>> = 0>
void subtract(const Element& left, const Container1& right, Container2& out)
{
    assert(right.size() == out.size());
    using std::begin;
    using std::end;
    subtract(left, begin(right), end(right), begin(out));
}

template<typename Container1, typename Element, typename Container2,
    check_difference<value_type<Container1>, Element, value_type<Container2>> = 0>
void subtract(const Container1& left, const Element& right, Container2& out)
{
    assert(left.size() == out.size());
    using std::begin;
    using std::end;
    subtract(begin(left), end(left), right, begin(out));
}

////////////////////////////////////////////////////////////////////////////////
// multiply

template<typename Container1, typename Container2, typename Container3,
    check_product<value_type<Container1>, value_type<Container2>, value_type<Container3>> = 0>
void multiply(const Container1& left, const Container2& right, Container3& out)
{
    assert(left.size() == out.size());
    assert(right.size() == out.size());
    using std::begin;
    using std::end;
    multiply(begin(left), end(left), begin(right), begin(out));
}

template<typename Element, typename Container1, typename Container2,
    check_product<Element, value_type<Container1>, value_type<Container2>> = 0>
void multiply(const Element& left, const Container1& right, Container2& out)
{
    assert(right.size() == out.size());
    using std::begin;
    using std::end;
    multiply(left, begin(right), end(right), begin(out));
}

template<typename Container1, typename Element, typename Container2,
    check_product<value_type<Container1>, Element, value_type<Container2>> = 0>
void multiply(const Container1& left, const Element& right, Container2& out)
{
    assert(left.size() == out.size());
    using std::begin;
    using std::end;
    multiply(begin(left), end(left), right, begin(out));
}

////////////////////////////////////////////////////////////////////////////////
// divide

template<typename Container1, typename Container2, typename Container3,
    check_ratio<value_type<Container1>, value_type<Container2>, value_type<Container3>> = 0>
void divide(const Container1& left, const Container2& right, Container3& out)
{
    assert(left.size() == out.size());
    assert(right.size() == out.size());
    using std::begin;
    using std::end;
    multiply(begin(left), end(left), begin(right), begin(out));
}

template<typename Element, typename Container1, typename Container2,
    check_ratio<Element, value_type<Container1>, value_type<Container2>> = 0>
void divide(const Element& left, const Container1& right, Container2& out)
{
    assert(right.size() == out.size());
    using std::begin;
    using std::end;
    multiply(left, begin(right), end(right), begin(out));
}

template<typename Container1, typename Element, typename Container2,
    check_ratio<value_type<Container1>, Element, value_type<Container2>> = 0>
void divide(const Container1& left, const Element& right, Container2& out)
{
    assert(left.size() == out.size());
    using std::begin;
    using std::end;
    multiply(begin(left), end(left), right, begin(out));
}

/** @} */

} // namespace aaa
