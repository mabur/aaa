#pragma once

#include "logical_range.hpp"

namespace aaa {

/**
@defgroup logical_container Logical Operations on Containers

@{
*/

template<typename Container1, typename Container2, typename Container3>
void logical_and(const Container1& left, const Container2& right, Container3& out)
{
    using namespace std;
    aaa::logical_and(begin(left), end(left), begin(right), begin(out));
}

template<typename Container1, typename Container2, typename Container3>
void logical_or(const Container1& left, const Container2& right, Container3& out)
{
    using namespace std;
    aaa::logical_or(begin(left), end(left), begin(right), begin(out));
}

template<typename Container1, typename Container2>
void logical_not(const Container1& in, Container2& out)
{
    using namespace std;
    aaa::logical_not(begin(in), end(in), begin(out));
}

/** @} */

} // namespace aaa
