
#pragma once

#include <algorithm>
#include <cassert>

#include "traits.hpp"

namespace aaa {

template<typename Iterator, typename Key, check_key<Key, value_type_i<Iterator>> = nullptr>
Iterator min_element(Iterator first, Iterator last, Key key) {
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

template<typename Container>
typename Container::iterator min_element(Container& container) {
    using std::begin;
    using std::end;
    return std::min_element(begin(container), end(container));
}

template<typename Container>
typename Container::const_iterator min_element(const Container& container) {
    using std::begin;
    using std::end;
    return std::min_element(begin(container), end(container));
}

template<typename Container, typename Compare, check_compare<Compare, value_type<Container>> = nullptr>
typename Container::iterator min_element(Container& container, Compare comp) {
    using std::begin;
    using std::end;
    return std::min_element(begin(container), end(container), comp);
}

template<typename Container, typename Compare, check_compare<Compare, value_type<Container>> = nullptr>
typename Container::const_iterator min_element(const Container& container, Compare comp) {
    using std::begin;
    using std::end;
    return std::min_element(begin(container), end(container), comp);
}

template<typename Container, typename Key, check_key<Key, value_type<Container>> = nullptr>
typename Container::iterator min_element(Container& container, Key key) {
    using std::begin;
    using std::end;
    return aaa::min_element(begin(container), end(container), key);
}

template<typename Container, typename Key, check_key<Key, value_type<Container>> = nullptr>
typename Container::const_iterator min_element(const Container& container, Key key) {
    using std::begin;
    using std::end;
    return aaa::min_element(begin(container), end(container), key);
}

} // namespace aaa
