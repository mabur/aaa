#pragma once

#include <algorithm>
#include <cassert>

#include "traits.hpp"

namespace aaa {

template<typename Container1, typename Container2>
void copy(const Container1& in, Container2& out)
{
    assert(in.size() == out.size());
    using std::begin;
    using std::end;
    std::copy(begin(in), end(in), begin(out));
}

template<typename Container, typename Value>
void fill(Container& container, const Value& value)
{
    using std::begin;
    using std::end;
    std::fill(begin(container), end(container), value);
}

template<typename Container>
typename Container::iterator min_element(Container& container)
{
    using std::begin;
    using std::end;
    return std::min_element(begin(container), end(container));
}

template<typename Container>
typename Container::const_iterator min_element(const Container& container)
{
    using std::begin;
    using std::end;
    return std::min_element(begin(container), end(container));
}

template<typename Container>
typename Container::iterator max_element(Container& container)
{
    using std::begin;
    using std::end;
    return std::max_element(begin(container), end(container));
}

template<typename Container>
typename Container::const_iterator max_element(const Container& container)
{
    using std::begin;
    using std::end;
    return std::max_element(begin(container), end(container));
}

template<typename Container>
std::pair<const_iterator<Container>, const_iterator<Container>>
minmax_element(const Container& container)
{
    using std::begin;
    using std::end;
    return std::minmax_element(begin(container), end(container));
}

template<typename Container>
std::pair<iterator<Container>, iterator<Container>>
minmax_element(Container& container)
{
    using std::begin;
    using std::end;
    return std::minmax_element(begin(container), end(container));
}

} // namespace aaa
