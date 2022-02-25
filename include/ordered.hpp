#pragma once

#include <algorithm>

namespace aaa {

template<typename RandomAccessIterator>
RandomAccessIterator mid_element(RandomAccessIterator first, RandomAccessIterator last)
{
    const auto num_elements = std::distance(first, last);
    const auto mid = first + num_elements / 2;
    std::nth_element(first, mid, last);
    return mid;
}

template<typename RandomAccessIterator, typename Compare>
RandomAccessIterator mid_element(RandomAccessIterator first, RandomAccessIterator last, Compare comp)
{
    const auto num_elements = std::distance(first, last);
    const auto mid = first + num_elements / 2;
    std::nth_element(first, mid, last, comp);
    return mid;
}

template<typename Container>
typename Container::iterator mid_element(Container& container)
{
    using std::begin;
    using std::end;
    return mid_element(begin(container), end(container));
}

template<typename Container, typename Compare>
typename Container::iterator mid_element(Container& container, Compare comp)
{
    using std::begin;
    using std::end;
    return mid_element(begin(container), end(container), comp);
}

}
