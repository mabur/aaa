#pragma once

#include <type_traits>

template<typename Container>
using value_type = typename Container::value_type;

template<typename Iterator>
using value_type_i = typename std::iterator_traits<Iterator>::value_type;


template<typename A, typename B, typename C = B>
using enable_if_same = typename std::enable_if_t<
	std::is_same<A, B>::value && std::is_same<B, C>::value, int>;


template<typename A, typename B, typename C>
using check_sum = typename enable_if_same<A, B, C>;

template<typename A, typename B, typename C>
using check_difference = typename enable_if_same<A, B, C>;

template<typename A, typename B, typename C>
using check_product = typename enable_if_same<A, B, C>;

template<typename A, typename B, typename C>
using check_ratio = typename enable_if_same<A, B, C>;

/*
template<typename A, typename B> using my_sum_type        = decltype(A() + B());
template<typename A, typename B> using my_difference_type = decltype(A() - B());
template<typename A, typename B> using my_product_type    = decltype(A() * B());
template<typename A, typename B> using my_ratio_type      = decltype(A() / B());

template<typename A, typename B, typename C>
using check_sum = typename enable_if_same<my_sum_type<A, B>, C>*;

template<typename A, typename B, typename C>
using check_difference = typename enable_if_same<my_difference_type<A, B>, C>*;

template<typename A, typename B, typename C>
using check_product = typename enable_if_same<my_product_type<A, B>, C>*;

template<typename A, typename B, typename C>
using check_ratio = typename enable_if_same<my_ratio_type<A, B>, C>*;
*/
