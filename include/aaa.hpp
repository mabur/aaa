/** \mainpage

# Contents
- Overview
- Requirements
- Building
- Design and Rationale
- Examples

# Overview

This library consists of a set of templated functions for doing basic arithmetic
operations on containers and ranges of iterators. The elements of the
ranges/containers can be any built in aritmetic type, e.g.
`float`, `double`, `int`, or any other type that supports the arithmetic
operations: +, -, *, /. We refer to a range/container of arithmetic elements as
a mathematical vector. This library defines vector operations for arbitrary
finite vector spaces. This library does not define any specific data structure
for the vectors, but operates on general vectors/ranges/containers.

The library consists of different modules:
- **General operations for vector spaces**.
  This includes various versions of the functions: `add`, `subtract`, `negate`, `multiply`, `divide`.
- **Norms and metrics for vector spaces**.
  This includes various versions of the functions: `norm`, `distance`, `squared_norm`, `squared_distance`.
  The norms and distances are defined for the following vectors spaces:
  `eclidean` (L2), `tacixab` (L1), `maximum` (L-infinity).
- **Misc algorithms**. `sum`, `convert`.
- **Logical operations**. `logical_and`, `logical_or`, `logical_not`.
- **STD algorithms**. `fill`, `copy`, `min_element`, `max_element`, `minmax_element`.

## General Operations for Vector Spaces

This module defines elementwise arithmetic operations on vectors.
The input is two vectors/ranges/containers and the output is one vector/range/container.

- **add**. Does elementwise addition of either two vectors/ranges/containers,
    or a scalar and a vector/range/container.
- **subtract**. Does elementwise subtraction of either two vector/ranges/containers,
    or a scalar and a vector/range/container.
- **negate**. Does elementwise negation of a single vector/range/container.
- **multiply**. Does elementwise multiplication of either two vector/ranges/containers,
    or a scalar and a vector/range/container.
- **divide**. Does elementwise division of either two vectors/ranges/containers,
    or a scalar and a vector/range/container.

## Norms and Metrics for Vector Spaces

This module defines norms/lengths and metrics/distances for vectors.
These functions take one or two vectors/ranges/containers and returns a
single scalar:
 - **norm**. Computes the norm/magnitude/length of a vecor/range/container.
 - **distance**. Computes the distance of two vectors/ranges/containers.
 - **squared_norm**. Computes the squared norm of a vector/range/container.
 - **squared_distance**. Computes the squared distance of two
 vectors/ranges/containers.
 - **dot**. Computes the the dot-product of two vecors/ranges/containers.

 We consider three different kinds of vector spaces: `euclidean` (L2),
 `manhattan` (L1), `maximum` (L-infinity). Each kind of vector spaces has its
 own namespace, with its own versions of the functions above in it. 
 However, the `dot` product is only defined for `euclidean` vector spaces.
 All the functions in this module assume that the default construction of a
 scalar gives zero, which is true for the built-in arithmetic types.

## Misc algorithms

This module defines the aglorithms:
- **sum**. Computes the sum of the elements of a range/container.
  It assume that the default construction of a scalar gives zero,
  which is true for the built-in arithmetic types.
- **convert**. Does elementwise `static_cast` on the elements from one
    range/container to another range/container.

##Logical operations

This module works on ranges/containers with elements of type `bool`, 
or any other type that supports the the boolean operations &&, ||, !.
The input is one or two ranges/containers and the output is a single
range/container.
- **logical_and**. Does elementwise boolean `and` on two ranges/containers.
- **logical_or**. Does elementwise boolean `or` on two ranges/containers.
- **logical_not**. Does elementwise boolean `not` on a single range/container.

##STD algorithms

This module defines container versions of some range
algorithms from the standard library header `<algorithm>`. It only does it for
the algorithms that are used a lot for arithmetic types:
- **copy**.
- **fill**.
- **min_element**.
- **max_element**.
- **minmax_element**.

Go to the **Modules** pages to learn more about each module.

# Requirements

All the functions of this library assume that the input and output is:
- Either ranges of iterators, or standard like containers, i.e. they have begin
  and end functions that give iterators.
- The elements of the ranges/containers should support arithmetic operations:
  +, -, *, /. The functions in the module *Logical Operations* is the only
  exception to this. It assumes that the elements support the boolean operations
  &&, ||, !.
- The functions in the norms and metrics module assume that the default
  construction of a scalar gives zero, which is true for the built-in arithmetic
  types. The function `sum` also assumes this.

# Building

The library is header only, which makes it easy to use and build. Download it
and add it to the include directory of your project and `#include <aaa.hpp>`.

# Design and Rationale

This library deals with arithmetic operations on mathematical vectors,
represented as ranges or containers.
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
    add(in1, in2, out); // Add the images together elementwise.
    divide(out, 2, out);// Divide the result elementwise with 2 to get the mean image.
}

// Returns the projection of a on b.
std::vector<float> project(const std::vector<float>& a, const std::vector<float>& b)
{
    using namespace aaa::euclidean;
    // First we compute the scaling factor of the projection by taking the dot
    // product of the vectors. We normalize with the squared_norm of the vector
    // that we are projecting on.
    const auto scaling = dot(a, b) / squared_norm(b);
    // The projection of a on b is like b,
    // but multiplied elementwise with the scaling factor.
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
#include "vector_space_functional.hpp"

#include "euclidean_space_range.hpp"
#include "euclidean_space_container.hpp"

#include "manhattan_space_range.hpp"
#include "manhattan_space_container.hpp"

#include "maximum_space_range.hpp"
#include "maximum_space_container.hpp"

#include "logical_range.hpp"
#include "logical_container.hpp"
#include "logical_functional.hpp"
