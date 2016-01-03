# Auxiliary Arithmetic Algorithms

This library provides algorithms for doing arithmetic operations on general ranges and containers:
* `add`
* `subtract`
* `multiply`
* `divide`
* `norm`
* `squared_norm`
* `dot`
* `distance`
* `sum`
* `convert`

From a C++ perspective it implements algorithms for doing arithmetic operations on general ranges and containers. The requirement is that the elements of the containers have defined the arithmetic operators `+`, `-`, `*`, `/`. The algorithms complement those that are in the standard template library header file [numeric](http://www.cplusplus.com/reference/numeric/).

From a mathematical perspective it implements: some algorithms for general finite [vector spaces](https://en.wikipedia.org/wiki/Vector_space), and some algorithms specifically for [Euclidean spaces](https://en.wikipedia.org/wiki/Euclidean_space). A mathematical finite vector can be represented by any C++ container or range. This library does not care about what container is used to represent vectors. It only cares about the operations on the vectors.

## Vector space algorithms
A mathematical vector space has the following operations defined:
* `add(vector_in_1, vector_in_2, vector_out)` does elementwise addition of two vectors.
* `subtract(v_in_1, v_in_2, v_out)` does elementwise subtraction of two vectors.
* `multiply(vector_in, scalar_in, vector_out)` multiplies each element of a vector with a scalar.
* `divide(vector_in, scalar_in, vector_out)` divides each element of a vector with a scalar.

The library supports expressions on the general form ``binary_operation(in_left, in_right, out)`` where:
* The operation `binary_operation` is one of `add`, `subtract`, `multiply`, `divide`.
* The output `out` is a container.
* At least one of the inputs `in_left` and `in_right` is a container. The other could be a scalar.

## Euclidean space algorithms
An Euclidean space also has operations for computing lengths, angles and distances of vectors:
* `n = norm(v)` computes the Euclidean norm of a vector. We often call this the length of the vector.
* `n2 = squared_norm(v)` computes the squared Euclidean norm of a vector.
* `d = dot(v1, v2)` computes the dot product of two vectors. This is also called the Euclidean inner product. Angles between vectors can be defined using this.
* `d = distance(v1, v2)` computes the Euclidean distance between two vectors.

All of these algorithms output a scalar. They take one or two containers / ranges as input.

## Additional algorithms

The library also provides these additional algorithms that do not fit in any of the categories above:
* `s = sum(c)` computes the sum of all elements of a container.
* `convert(a, b)` can be used to convert a container of e.g. `int` to a container of `float`.

## Examples

The algorithms can be used on arbitrary containers like this:
```cpp
// Returns the projection of a on b.
std::vector<float> project(const std::vector<float>& a, const std::vector<float>& b)
{
	const auto scaling = dot(a, b) / dot(b, b);
	auto projection = b;
	multiply(scaling, b, projection);
	return projection;
}

// Take an image of bytes as input and output to an image of doubles.
// Normalize the output to be between 0 and 1.
void byte_image_to_float(const MyImage<char>& gray_image_in, MyImage<double>& gray_image_out)
{
	divide(gray_image_in, 1.0 / 255.0, gray_image_out);
	return result;
}

```