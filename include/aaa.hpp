/** \mainpage

# Overview

This library consists of the modules:
- **Vector space operations**. This module defines the algorithms:
    - add
    - subtract
    - negate
    - multiply
    - divide
- **Euclidean space operations**. This module defines the algorithms:
    - norm
    - squared_norm
    - dot
    - distance
    - squared_distance

Go to the **Modules** pages to learn more about each module.

# Design and Rationale

This library deals with arithmetic operations on mathematical vectors.
It is designed for vectors in arbitrary dimensions. It is NOT optimized for small
vectors, which you typically use to represent geometry in 2D and 3D. For that
use case it might be more optimal to use other libraries like:
[GLM](http://glm.g-truc.net/) and [Eigen](http://eigen.tuxfamily.org/). 

C++ libraries that deals with mathematical vectors in arbitrary dimensions
can usually be divided into two categories:
-# Those that implement a vector class and overload its arithmetic operators.
   Examples of this are:
   [std::valarray](http://www.cplusplus.com/reference/valarray/),
   [Eigen](http://eigen.tuxfamily.org/),
   [Blitz++](https://sourceforge.net/projects/blitz/),
   [OpenCV](http://opencv.org/).
-# Those that implement general algorithms that work on any container or
   range of iterators. An example of this is the standard library and the headers
   [algorithm](http://www.cplusplus.com/reference/algorithm/)
   and [numeric](http://www.cplusplus.com/reference/numeric/).

This library follows the second approach. It implements some common arithmetic
algorithms that are missing in the standard library.

The two approaches have different advantages and disadvantages:
-# The advantage of the first approach is that the syntax can be very concise,
   when you overload the arithmetic operators to act directly on the vector class.
   This approach can also have performance advantages, since it couples the
   algorithm to the data structure. It is then possible to use techniques
   like *expression templates* or *aligned memory* and *vectorization*.
-# The advantage of the second approach is that it allows *generic programming*.
   Code that uses such libraries is more general since it is less coupled to a
   specific data structure. This is good for readability and reuse of the code.

# Examples

The algorithms can be used on arbitrary containers like this:
```
// Blend two images.
void blend(const Image& in1, const Image& in2, Image& out)
{
    using namespace aaa;
    add(in1, in2, out);
    divide(out, 2, out);
}

// Returns the projection of a on b.
std::vector<float> project(const std::vector<float>& a, const std::vector<float>& b)
{
    using namespace aaa;
    const auto scaling = dot(a, b) / dot(b, b);
    auto projection = b;
    multiply(scaling, b, projection);
    return projection;
}
```
*/

// TODO: should the elements be passed by value or const reference?

#pragma once

#include "std_algorithms_container.hpp"

#include "algorithms_range.hpp"
#include "algorithms_container.hpp"

#include "vector_space_range.hpp"
#include "vector_space_container.hpp"

#include "euclidean_space_range.hpp"
#include "euclidean_space_container.hpp"
