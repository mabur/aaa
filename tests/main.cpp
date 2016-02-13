#include <iostream>
#include <vector>
#include <array>
#include <valarray>

#include "aaa.hpp"

void test_std_algorithms();
void test_algorithms();
void test_vector_space_operations();
void test_euclidean_space_operations();

int main()
{
    test_std_algorithms();
	test_algorithms();
	test_vector_space_operations();
	test_euclidean_space_operations();

	using namespace std;
	cout << "Press enter to quit." << endl;
	cin.get();

	return 0;
}

void test_std_algorithms()
{
    using namespace aaa;

    const std::vector<int> c1 = { 1, 2, 3, 4, 5 };
    std::array<float, 5> c2 = { 1, 2, 3, 4, 5 };
    std::valarray<double> c3 = { 1, 2, 3, 4, 5 };
    double x = 3.14;

    copy(c1, c2);
    fill(c3, x);

    auto min1 = min_element(c1);
    auto min2 = min_element(c2);

    auto max1 = max_element(c1);
    auto max2 = max_element(c2);

    auto minmax1 = minmax_element(c1);
    auto minmax2 = minmax_element(c2);

    //*min1 = 3;
    *min2 = 3;
    //*max1 = 3;
    *max2 = 3;

    //*minmax1.first = 3;
    *minmax2.first = 3;
    //*minmax1.second = 3;
    *minmax2.second = 3;
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
    int ef = 10.f;

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
}

void test_euclidean_space_operations()
{
    using namespace aaa;

	std::vector<int>   c1 = { 1, 2, 3, 4, 5 };
	std::array<int, 5> c2 = { 1, 2, 3, 4, 5 };
	std::valarray<int> c3 = { 1, 2, 3, 4, 5 };

	dot(c1, c2);
	squared_norm(c1);
	norm(c1);
    squared_distance(c1, c2);
	distance(c1, c2);

	using std::begin;
	using std::end;

	dot(begin(c1), end(c1), begin(c2));
	squared_norm(begin(c1), end(c1));
	norm(begin(c1), end(c1));
    squared_distance(begin(c1), end(c1), begin(c2));
	distance(begin(c1), end(c1), begin(c2));
}
