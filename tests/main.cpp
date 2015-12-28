#include <iostream>
#include <vector>
#include <array>
#include <valarray>

#include "aaa.hpp"

void test_algorithms();
void test_vector_space_operations();
void test_euclidean_space_operations();

int main()
{
	test_algorithms();
	test_vector_space_operations();
	test_euclidean_space_operations();

	using namespace std;
	cout << "Press enter to quit." << endl;
	cin.get();

	return 0;
}

void test_algorithms()
{
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
	std::vector<int>   c1 = { 1, 2, 3, 4, 5 };
	std::array<int, 5> c2 = { 1, 2, 3, 4, 5 };
	std::valarray<int> c3 = { 1, 2, 3, 4, 5 };
	int e = 10;

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

	using std::begin;
	using std::end;

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
	std::vector<int>   c1 = { 1, 2, 3, 4, 5 };
	std::array<int, 5> c2 = { 1, 2, 3, 4, 5 };
	std::valarray<int> c3 = { 1, 2, 3, 4, 5 };

	dot(c1, c2);
	squared_norm(c1);
	norm(c1);
	distance(c1, c2);

	using std::begin;
	using std::end;

	dot(begin(c1), end(c1), begin(c2));
	squared_norm(begin(c1), end(c1));
	norm(begin(c1), end(c1));
	distance(begin(c1), end(c1), begin(c2));
}
