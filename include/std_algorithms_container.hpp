#pragma once

#include <algorithm>
#include <cassert>

#include "traits.hpp"

namespace aaa {

/**
@addtogroup std_algorithms_container

This module defines container versions of some range
algorithms from the standard library header
[algorithm](http://www.cplusplus.com/reference/algorithm/).
It only does it for the algorithms that are used a lot for arithmetic types.

@{
*/

// TODO: add all_of, any_of, none_of.

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

template<typename Container, typename Compare, check_compare<Compare, value_type<Container>> = nullptr>
typename Container::iterator min_element(Container& container, Compare comp)
{
    using std::begin;
    using std::end;
    return std::min_element(begin(container), end(container), comp);
}

template<typename Container, typename Compare, check_compare<Compare, value_type<Container>> = nullptr>
typename Container::const_iterator min_element(const Container& container, Compare comp)
{
    using std::begin;
    using std::end;
    return std::min_element(begin(container), end(container), comp);
}

template<typename Iterator, typename Key, check_key<Key, value_type_i<Iterator>> = nullptr>
Iterator min_element(Iterator first, Iterator last, Key key)
{
    if (first == last) {
        return first;
    }
    auto result = first;
    auto value = key(*first);
    while (++first != last) {
        auto new_value = key(*first);
        if (new_value < value) {
            result = first;
            value = new_value;
        }
    }
    return result;
}

template<typename Container, typename Key, check_key<Key, value_type<Container>> = nullptr>
typename Container::iterator min_element(Container& container, Key key)
{
    using std::begin;
    using std::end;
    return min_element(begin(container), end(container), key);
}

template<typename Container, typename Key, check_key<Key, value_type<Container>> = nullptr>
typename Container::const_iterator min_element(const Container& container, Key key)
{
    using std::begin;
    using std::end;
    return aaa::min_element(begin(container), end(container), key);
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


template<typename Container, typename Compare>
typename Container::iterator max_element(Container& container, Compare comp)
{
    using std::begin;
    using std::end;
    return std::max_element(begin(container), end(container), comp);
}

template<typename Container, typename Compare>
typename Container::const_iterator max_element(const Container& container, Compare comp)
{
    using std::begin;
    using std::end;
    return std::max_element(begin(container), end(container), comp);
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

template<typename Container, typename Compare>
std::pair<const_iterator<Container>, const_iterator<Container>>
minmax_element(const Container& container, Compare comp)
{
    using std::begin;
    using std::end;
    return std::minmax_element(begin(container), end(container), comp);
}

template<typename Container, typename Compare>
std::pair<iterator<Container>, iterator<Container>>
minmax_element(Container& container, Compare comp)
{
    using std::begin;
    using std::end;
    return std::minmax_element(begin(container), end(container), comp);
}

/** @} */

} // namespace aaa
