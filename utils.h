#pragma once

/**
 * @file
 * @brief Модуль с вспомогательными функциями
 */

#include <type_traits>
#include <tuple>
#include <iostream>

/**
 * @brief Функция определения контейнера
 */
template<typename T, typename _ = void>
struct is_container : std::false_type {};

/**
 * @private
 */
template<typename... Ts>
struct is_container_helper {};

template<typename T>
struct is_container<
        T,
        std::conditional_t<
            false,
            is_container_helper<
                typename T::value_type,
                typename T::size_type,
                typename T::allocator_type,
                typename T::iterator,
                typename T::const_iterator,
                decltype(std::declval<T>().size()),
                decltype(std::declval<T>().begin()),
                decltype(std::declval<T>().end()),
                decltype(std::declval<T>().cbegin()),
                decltype(std::declval<T>().cend())
                >,
            void
            >
        > : public std::true_type {};

/**
 * @brief Вспомогательная функция печати ip-адреса из std::tuple
 */
template <typename Tuple, std::size_t First, std::size_t Count>
struct print_tuple {
    static void print(const Tuple &ip) {
        std::cout << (First ? "." : "") << int(std::get<First>(ip));
        print_tuple<Tuple, First + 1, Count>::print(ip);
    }
};

/**
 * @private
 */
template <typename Tuple, std::size_t Count>
struct print_tuple<Tuple, Count, Count> {
    static void print(const Tuple &) {
        std::cout << std::endl;
    }
};

/**
 * @brief Вспомогательная функция по определению различающихся типов
 */
template<typename T, typename...Args>
struct is_all_of;

/**
 * @private
 */
template<typename T>
struct is_all_of<T> : std::true_type {};

/**
 * @private
 */
template<typename T, typename...Args>
struct is_all_of<T, T, Args...> : is_all_of<T, Args...> {};

/**
 * @private
 */
template <typename T, typename U, typename...Args>
struct is_all_of<T, U, Args...> : std::false_type {};
