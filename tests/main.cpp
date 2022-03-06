#include <functional>
#include <iostream>
#include <vector>
#include <array>
#include <valarray>

#include "aaa.hpp"

void test_std_algorithms();
void test_ordered();
void test_algorithms();
void test_sum();
void test_sum_double();
void test_vector_space_operations();
void test_add();
void test_subtract();
void test_multiply();
void test_divide();
void test_euclidean_space_operations();
void test_manhattan_space_operations();
void test_maximum_space_operations();
void test_logical_operations();

using vi = std::vector<int>;

template<typename T>
void assert_equal(const T& left, const T& right)
{
    assert(left == right);
}

void assert_equal(int left, int right)
{
    if (left != right) {
        using namespace std;
        cout << left << " != " << right << endl;
        assert(left == right);
    }
}

int main()
{
    using namespace std;
    cout << "test_std_algorithms" << endl;
    test_std_algorithms();
    cout << "test_ordered" << endl;
    test_ordered();
    cout << "test_algorithms" << endl;
	test_algorithms();
    cout << "test_sum" << endl;
    test_sum();
    cout << "test_sum_double" << endl;
    test_sum_double();
    cout << "test_vector_space_operations" << endl;
	test_vector_space_operations();
    cout << "test_add" << endl;
	test_add();
    cout << "test_subtract" << endl;
	test_subtract();
    cout << "test_multiply" << endl;
	test_multiply();
    cout << "test_divide" << endl;
	test_divide();
    cout << "test_euclidean_space_operations" << endl;
	test_euclidean_space_operations();
    cout << "test_manhattan_space_operations" << endl;
    test_manhattan_space_operations();
    cout << "test_maximum_space_operations" << endl;
    test_maximum_space_operations();
    cout << "test_logical_operations" << endl;
    test_logical_operations();
	return 0;
}

void test_std_algorithms()
{
    using aaa::min_element;
    using aaa::max_element;
    using aaa::minmax_element;

    assert_equal(*min_element(vi{1}), 1);
    assert_equal(*min_element(vi{1, 2}), 1);
    assert_equal(*min_element(vi{2, 1}), 1);

    assert_equal(*min_element(vi{2}, std::negate<int>{}), 2);
    assert_equal(*min_element(vi{1, 2}, std::negate<int>{}), 2);
    assert_equal(*min_element(vi{2, 1}, std::negate<int>{}), 2);

    assert_equal(*max_element(vi{2}), 2);
    assert_equal(*max_element(vi{1, 2}), 2);
    assert_equal(*max_element(vi{2, 1}), 2);

    assert_equal(*max_element(vi{1}, std::negate<int>{}), 1);
    assert_equal(*max_element(vi{1, 2}, std::negate<int>{}), 1);
    assert_equal(*max_element(vi{2, 1}, std::negate<int>{}), 1);

    assert_equal(*minmax_element(vi{1}).first, 1);
    assert_equal(*minmax_element(vi{1, 2}).first, 1);
    assert_equal(*minmax_element(vi{2, 1}).first, 1);

    assert_equal(*minmax_element(vi{2}).second, 2);
    assert_equal(*minmax_element(vi{1, 2}).second, 2);
    assert_equal(*minmax_element(vi{2, 1}).second, 2);
}

void test_ordered()
{
    using namespace aaa;

    auto c1 = vi{};
    auto mid1 = mid_element(c1.begin(), c1.end());
    assert_equal(mid1, c1.begin());
    assert_equal(mid1, c1.end());

    c1 = {};
    mid1 = mid_element(c1);
    assert_equal(mid1, c1.begin());
    assert_equal(mid1, c1.end());

    auto c2 = vi{1};
    auto mid2 = mid_element(c2.begin(), c2.end());
    assert_equal(mid2, c2.begin());
    assert_equal(*mid2, 1);

    c2 = {1};
    mid2 = mid_element(c2);
    assert_equal(mid2, c2.begin());
    assert_equal(*mid2, 1);

    auto c3 = vi{1, 2};
    auto mid3 = mid_element(c3.begin(), c3.end());
    assert_equal(mid3, c3.begin() + 1);
    assert_equal(*mid3, 2);

    c3 = {1, 2};
    mid3 = mid_element(c3);
    assert_equal(mid3, c3.begin() + 1);
    assert_equal(*mid3, 2);

    auto c4 = vi{2, 1};
    auto mid4 = mid_element(c4.begin(), c4.end());
    assert_equal(mid4, c4.begin() + 1);
    assert_equal(*mid4, 2);

    c4 = {2, 1};
    mid4 = mid_element(c4);
    assert_equal(mid4, c4.begin() + 1);
    assert_equal(*mid4, 2);

    auto c5 = vi{1, 2, 0};
    auto mid5 = mid_element(c5.begin(), c5.end());
    assert_equal(mid5, c5.begin() + 1);
    assert_equal(*mid5, 1);

    c5 = {1, 2, 0};
    mid5 = mid_element(c5);
    assert_equal(mid5, c5.begin() + 1);
    assert_equal(*mid5, 1);

    auto c6 = vi{1, 2, 0, 5};
    auto mid6 = mid_element(c6.begin(), c6.end());
    assert_equal(mid6, c6.begin() + 2);
    assert_equal(*mid6, 2);

    c6 = {1, 2, 0, 5};
    mid6 = mid_element(c6);
    assert_equal(mid6, c6.begin() + 2);
    assert_equal(*mid6, 2);
}

void test_algorithms()
{
    using namespace aaa;

	std::vector<int>   c1 = { 1, 2, 3, 4, 5 };
	std::array<float, 5> c2 = { 1, 2, 3, 4, 5 };
	std::valarray<double> c3 = { 1, 2, 3, 4, 5 };

	convert(c1, c2);
	convert(c3, c1);
	sum(c1);

	using std::begin;
	using std::end;

	convert(begin(c1), end(c1), begin(c2));
	convert(begin(c3), end(c3), begin(c1));
	sum(begin(c1), end(c1));
}

void test_sum()
{
    using aaa::sum;
    assert_equal(sum(vi{1, 2, 3, 4, 5}), 15);
    assert_equal(sum(vi{1, 2, 3, 4, 5}, -2), 13);
    assert_equal(sum(vi{1, 2, 3, 4, 5}, 0.0), 15.0);
}

void test_sum_double()
{
    const auto N = size_t{ 10000 };

    auto data_float = std::vector<float>(N);
    auto data_double = std::vector<double>(N);

    auto manual_sum_float = float{ 0 };
    auto manual_sum_double = double{ 0 };

    for (size_t i = 0; i < N; ++i)
    {
        const auto value = float{ i * 0.1f };
        
        data_float[i] = value;
        data_double[i] = value;

        manual_sum_float += value;
        manual_sum_double += value;
    }
    
    assert_equal(manual_sum_float, aaa::sum(data_float));
    assert_equal(manual_sum_float, aaa::sum(data_float, 0.f));
    assert_equal(manual_sum_float, aaa::sum(data_double, 0.f));

    assert_equal(manual_sum_double, aaa::sum(data_double));
    assert_equal(manual_sum_double, aaa::sum(data_double, 0.0));
    assert_equal(manual_sum_double, aaa::sum(data_float, 0.0));
}

void test_vector_space_operations()
{
    using namespace aaa;

	std::vector<int>   c1 = { 1, 2, 3, 4, 5 };
	std::array<int, 5> c2 = { 1, 2, 3, 4, 5 };
	std::valarray<int> c3 = { 1, 2, 3, 4, 5 };
	int e = 10;

    negate(c1, c2);

	add(c1, c2, c3);
	add(e, c2, c3);
	add(c2, e, c3);

	subtract(c1, c2, c3);
	subtract(e, c2, c3);
	subtract(c2, e, c3);

	multiply(c1, c2, c3);
	multiply(e, c2, c3);
	multiply(c1, e, c3);

	divide(c1, c2, c3);
	divide(e, c2, c3);
	divide(c1, e, c3);

#if !_MSC_VER || __clang__

    std::vector<float>   c1f = { 1.f, 2.f, 3.f, 4.f, 5.f };
    std::array<float, 5> c2f = { 1.f, 2.f, 3.f, 4.f, 5.f };
    std::valarray<float> c3f = { 1.f, 2.f, 3.f, 4.f, 5.f };
    const auto ef = 10.f;

    add(c1, c2f, c3f);
    add(e, c2f, c3f);
    add(c2, ef, c3f);

    subtract(c1, c2f, c3f);
    subtract(e, c2f, c3f);
    subtract(c2, ef, c3f);

    multiply(c1, c2f, c3f);
    multiply(e, c2f, c3f);
    multiply(c1, ef, c3f);

    divide(c1, c2f, c3f);
    divide(e, c2f, c3f);
    divide(c1, ef, c3f);
#endif

	using std::begin;
	using std::end;

    negate(begin(c1), end(c1), begin(c2));

	add(begin(c1), end(c1), begin(c2), begin(c3));
	add(e, begin(c1), end(c1), begin(c3));
	add(begin(c1), end(c1), e, begin(c3));

	subtract(begin(c1), end(c1), begin(c2), begin(c3));
	subtract(e, begin(c1), end(c1), begin(c3));
	subtract(begin(c1), end(c1), e, begin(c3));

	multiply(begin(c1), end(c1), begin(c2), begin(c3));
	multiply(e, begin(c1), end(c1), begin(c3));
	multiply(begin(c1), end(c1), e, begin(c3));

	divide(begin(c1), end(c1), begin(c2), begin(c3));
	divide(e, begin(c1), end(c1), begin(c3));
	divide(begin(c1), end(c1), e, begin(c3));

    c1 = negate(c1);
    c2 = negate(c2);
    c3 = negate(c3);

    c1 = add(c1, c1);
    c1 = add(c1, e);
    c1 = add(e, c1);

    c2 = add(c2, c2);
    c2 = add(c2, e);
    c2 = add(e, c2);

    c3 = add(c3, c3);
    c3 = add(c3, e);
    c3 = add(e, c3);

    c1 = subtract(c1, c1);
    c1 = subtract(c1, e);
    c1 = subtract(e, c1);

    c2 = subtract(c2, c2);
    c2 = subtract(c2, e);
    c2 = subtract(e, c2);

    c3 = subtract(c3, c3);
    c3 = subtract(c3, e);
    c3 = subtract(e, c3);

    c1 = multiply(c1, c1);
    c1 = multiply(c1, e);
    c1 = multiply(e, c1);

    c2 = multiply(c2, c2);
    c2 = multiply(c2, e);
    c2 = multiply(e, c2);

    c3 = multiply(c3, c3);
    c3 = multiply(c3, e);
    c3 = multiply(e, c3);

	e = 1;

    c1 = divide(c1, c1);
    c1 = divide(c1, e);
    c1 = divide(e, c1);

    c2 = divide(c2, c2);
    c2 = divide(c2, e);
    c2 = divide(e, c2);

    c3 = divide(c3, c3);
    c3 = divide(c3, e);
    c3 = divide(e, c3);

    // Examples:

    std::vector<double>   in1 = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::vector<double>   in2 = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    std::valarray<double> in3 = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    std::array<double, 5> in4 = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    std::array<double, 9> in5 = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9 };
    std::vector<double>   out = { 1.1, 2.2, 3.3, 4.4, 5.5 };

    using namespace aaa;

    // In these three examples we want the same type of container
    // for both the input and output. We can then return the output by value.
    out = add(in1, in2); // Elementwise addition of two vector.
    out = add(2.5, in2); // Elementwise addition of a scalar and a vector.
    out = add(in1, 3.3); // Elementwise addition of a vector and a scalar.

    // In these three examples we mix arbitrary type of containers
    // for the input and output. We then use a reference for output.
    add(in3, in4, out); // Elementwise addition of two vector.
    add(4.9, in4, out); // Elementwise addition of a scalar and a vector.
    add(in3, 2.1, out); // Elementwise addition of a vector and a scalar.

    // In these three examples we use iterators for the input and output.
    add(begin(in5) + 1, begin(in5) + 6, begin(in4), begin(out)); // Elementwise addition of two vectors.
    add(4.9, begin(in5) + 1, begin(in5) + 6, begin(out)); // Elementwise addition of a scalar and a vector.
    add(begin(in5) + 1, begin(in5) + 6, 2.1, begin(out)); // Elementwise addition of a vector and a scalar.


    // In these three examples we want the same type of container
    // for both the input and output. We can then return the output by value.
    out = subtract(in1, in2); // Elementwise subtraction of two vector.
    out = subtract(2.5, in2); // Elementwise subtraction of a scalar and a vector.
    out = subtract(in1, 3.3); // Elementwise subtraction of a vector and a scalar.

    // In these three examples we mix arbitrary type of containers
    // for the input and output. We then use a reference for output.
    subtract(in3, in4, out); // Elementwise subtraction of two vector.
    subtract(4.9, in4, out); // Elementwise subtraction of a scalar and a vector.
    subtract(in3, 2.1, out); // Elementwise subtraction of a vector and a scalar.

    // In these three examples we use iterators for the input and output.
    subtract(begin(in5) + 1, begin(in5) + 6, begin(in4), begin(out)); // Elementwise subtraction of two vectors.
    subtract(4.9, begin(in5) + 1, begin(in5) + 6, begin(out)); // Elementwise subtraction of a scalar and a vector.
    subtract(begin(in5) + 1, begin(in5) + 6, 2.1, begin(out)); // Elementwise subtraction of a vector and a scalar.


    // In these three examples we want the same type of container
    // for both the input and output. We can then return the output by value.
    out = multiply(in1, in2); // Elementwise multiplication of two vector.
    out = multiply(2.5, in2); // Elementwise multiplication of a scalar and a vector.
    out = multiply(in1, 3.3); // Elementwise multiplication of a vector and a scalar.

    // In these three examples we mix arbitrary type of containers
    // for the input and output. We then use a reference for output.
    multiply(in3, in4, out); // Elementwise multiplication of two vector.
    multiply(4.9, in4, out); // Elementwise multiplication of a scalar and a vector.
    multiply(in3, 2.1, out); // Elementwise multiplication of a vector and a scalar.

    // In these three examples we use iterators for the input and output.
    multiply(begin(in5) + 1, begin(in5) + 6, begin(in4), begin(out)); // Elementwise multiplication of two vectors.
    multiply(4.9, begin(in5) + 1, begin(in5) + 6, begin(out)); // Elementwise multiplication of a scalar and a vector.
    multiply(begin(in5) + 1, begin(in5) + 6, 2.1, begin(out)); // Elementwise multiplication of a vector and a scalar.


    // In these three examples we want the same type of container
    // for both the input and output. We can then return the output by value.
    out = divide(in1, in2); // Elementwise division of two vector.
    out = divide(2.5, in2); // Elementwise division of a scalar and a vector.
    out = divide(in1, 3.3); // Elementwise division of a vector and a scalar.

    // In these three examples we mix arbitrary type of containers
    // for the input and output. We then use a reference for output.
    divide(in3, in4, out); // Elementwise division of two vector.
    divide(4.9, in4, out); // Elementwise division of a scalar and a vector.
    divide(in3, 2.1, out); // Elementwise division of a vector and a scalar.

    // In these three examples we use iterators for the input and output.
    divide(begin(in5) + 1, begin(in5) + 6, begin(in4), begin(out)); // Elementwise division of two vectors.
    divide(4.9, begin(in5) + 1, begin(in5) + 6, begin(out)); // Elementwise division of a scalar and a vector.
    divide(begin(in5) + 1, begin(in5) + 6, 2.1, begin(out)); // Elementwise division of a vector and a scalar.


    // In this example we want the same type of container
    // for both the input and output. We can then return the output by value.
    out = negate(in1);

    // In this example we mix arbitrary type of containers
    // for the input and output. We then use a reference for output.
    negate(in3, out);

    // In this example we use iterators for the input and output.
    negate(begin(in5) + 1, begin(in5) + 6, begin(out));
}

void test_add()
{
	assert_equal(aaa::add(vi{1, 2}, vi{3, 4}), vi{4, 6});
}

void test_subtract()
{
	assert_equal(aaa::subtract(vi{1, 2}, vi{3, 4}), vi{-2, -2});
}

void test_multiply()
{
	assert_equal(aaa::multiply(vi{1, 2}, vi{3, 4}), vi{3, 8});
}

void test_divide()
{
	assert_equal(aaa::divide(vi{8, 9}, vi{2, 3}), vi{4, 3});
}

void test_euclidean_space_operations()
{
	std::vector<int>   c1 = { 1, 2};
	std::array<int, 2> c2 = { 3, 4};

    using namespace aaa::euclidean;

	assert_equal(dot(c1, c2), 11);
    assert_equal(dot(c1, c2, 1.0), 12.0);
    assert_equal(squared_norm(c1), 5);
    assert_equal(squared_norm(c1, 1.0), 6.0);
    assert_equal(norm(c2), 5.0);
    assert_equal(norm(c2, 0.0), 5.0);
    assert_equal(squared_distance(c1, c2), 8);
    assert_equal(squared_distance(c1, c2, 1.0), 9.0);
    distance(c1, c2);
    assert_equal(distance(c1, c2, 1.0), 3.0);

	using std::begin;
	using std::end;

    dot(begin(c1), end(c1), begin(c2));
    squared_norm(begin(c1), end(c1));
    norm(begin(c1), end(c1));
    squared_distance(begin(c1), end(c1), begin(c2));
    distance(begin(c1), end(c1), begin(c2));
}

void test_manhattan_space_operations()
{
    std::vector<int>   c1 = { 1, 2, 3, 4, 5 };
    std::array<int, 5> c2 = { -1, 3, 3, -4, 0 };
    std::valarray<int> c3 = { 1, 2, 3, 4, 5 };

    using namespace aaa::manhattan;

    assert_equal(squared_norm(c1), 15 * 15);
    assert_equal(squared_norm(c1, 1.0), 16.0 * 16.0);
    assert_equal(norm(c1), 15);
    assert_equal(norm(c1, 1.0), 16.0);
    assert_equal(squared_distance(c1, c2), 16 * 16);
    assert_equal(squared_distance(c1, c2, 1.0), 17.0 * 17.0);
    assert_equal(distance(c1, c2), 2 + 1 + 0 + 8 + 5);
    assert_equal(distance(c1, c2, 1.0), 2 + 1 + 0 + 8 + 5 + 1.0);

    using std::begin;
    using std::end;

    squared_norm(begin(c1), end(c1));
    norm(begin(c1), end(c1));
    squared_distance(begin(c1), end(c1), begin(c2));
    distance(begin(c1), end(c1), begin(c2));
}

void test_maximum_space_operations()
{
    std::vector<int>   c1 = { 1, 2, 3, 4, 5 };
    std::array<int, 5> c2 = { -1, 3, 3, -4, 0 };
    std::valarray<int> c3 = { 1, 2, 3, 4, 5 };

    using namespace aaa::maximum;

    assert_equal(squared_norm(c1), 5 * 5);
    assert_equal(squared_norm(c1, 1.0), 5.0 * 5.0);
    assert_equal(squared_norm(c1, 50.0), 50.0 * 50.0);
    assert_equal(norm(c1), 5);
    assert_equal(norm(c1, 1.0), 5.0);
    assert_equal(norm(c1, 6.0), 6.0);
    assert_equal(squared_distance(c1, c2), 8 * 8);
    assert_equal(squared_distance(c1, c2, 1.0), 8.0 * 8.0);
    assert_equal(squared_distance(c1, c2, 10.0), 10.0 * 10.0);
    assert_equal(distance(c1, c2), 8);
    assert_equal(distance(c1, c2, 1.0), 8.0);
    assert_equal(distance(c1, c2, 10.0), 10.0);

    using std::begin;
    using std::end;

    squared_norm(begin(c1), end(c1));
    norm(begin(c1), end(c1));
    squared_distance(begin(c1), end(c1), begin(c2));
    distance(begin(c1), end(c1), begin(c2));
}

void test_logical_operations()
{
    using namespace aaa;

    std::vector<bool>   c1 = { true, true, false };
    std::array<bool, 3> c2 = { true, false, true };
    std::valarray<bool> c3 = { true, false, false };

    logical_and(c1, c2, c3);

    assert_equal(c3[0], true);
    assert_equal(c3[1], false);
    assert_equal(c3[2], false);

    logical_or(c1, c2, c3);

    assert_equal(c3[0], true);
    assert_equal(c3[1], true);
    assert_equal(c3[2], true);

    logical_not(c1, c2);

    assert_equal(c2[0], false);
    assert_equal(c2[1], false);
    assert_equal(c2[2], true);

    using std::begin;
    using std::end;

    logical_and(begin(c1), end(c1), begin(c2), begin(c3));
    logical_or(begin(c1), end(c1), begin(c2), begin(c3));
    logical_not(begin(c1), end(c1), begin(c2));

    c1 = logical_and(c1, c1);
    c2 = logical_or(c2, c2);
    c3 = logical_not(c3);

    // Examples:

    std::vector<bool>   in1 = { true, false, true, false };
    std::vector<bool>   in2 = { true, false, true, false };
    std::valarray<bool> in3 = { true, false, true, false };
    std::array<bool, 4> in4 = { true, false, true, false };
    std::array<bool, 6> in5 = { true, false, true, false, true, false };
    std::vector<bool>   out = { true, false, true, false };

    using namespace aaa;

    out = logical_and(in1, in2); // Same type of containers.
    logical_and(in3, in4, out); // Mixed type of containers.
    logical_and(begin(in5) + 1, begin(in5) + 5, begin(in4), begin(out)); // Ranges of iterators.

    out = logical_or(in1, in2); // Same type of containers.
    logical_or(in3, in4, out); // Mixed type of containers.
    logical_or(begin(in5) + 1, begin(in5) + 5, begin(in4), begin(out)); // Ranges of iterators.

    out = logical_not(in1); // Same type of containers.
    logical_not(in3, out); // Mixed type of containers.
    logical_not(begin(in5) + 1, begin(in5) + 5, begin(out)); // Ranges of iterators.
}

using Image = std::vector<double>;

Image blend(const Image& in1, const Image& in2)
{
    using namespace aaa;
    auto a = add(in1, in2); // Add the images together elementwise.
    return divide(a, 2); // Divide the result elementwise with 2 to get the mean image.
}

// Returns the projection of a on b.
std::vector<float> project(const std::vector<float>& a, const std::vector<float>& b)
{
    using namespace aaa;
    using namespace aaa::euclidean;
    // First we compute the scaling factor of the projection by taking the dot
    // product of the vectors. We normalize with the squared_norm of the vector
    // that we are projecting on.
    const auto scaling = dot(a, b) / squared_norm(b);
    // The projection of a on b is like b,
    // but multiplied elementwise with the scaling factor.
    return multiply(scaling, b);
}
