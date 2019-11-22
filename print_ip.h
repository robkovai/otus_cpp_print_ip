#pragma once

/**
 * @file
 * @brief Модуль для печати в консоль ip-адресов
 *
 * print_ip может работать с разными типами:
 * - любой целочисленный тип
 * - std::string
 * - любой контейнер
 * - std::tuple
 */

#include <vector>
#include <list>

#include "utils.h"

/**
 * @brief Печать в консоль ip-адреса из любого целочисленного типа
 * @param ip - ip-адрес в виде целочисленного значения
 */
template <typename T>
std::enable_if_t<std::is_integral<T>::value> print_ip(T ip) {
    auto bytes = reinterpret_cast<unsigned char*>(&ip) + sizeof(T) - 1;
    std::cout << int(*bytes);
    for (auto i = sizeof(T); i > 1; --i)
        std::cout << "." << int(*--bytes);
    std::cout << std::endl;
}

/**
 * @brief Печать в консоль ip-адреса из std::string
 * @param ip - ip-адрес
 */
void print_ip(const std::string &ip) {
    std::cout << ip << std::endl;
}

/**
 * @brief Печать в консоль ip-адреса из любого контейнера
 * @param container - ip-адрес в виде контейнера
 */
template <typename T>
std::enable_if_t<is_container<T>::value> print_ip(const T &container) {
    auto it = container.cbegin();
    while (it != container.cend())
        std::cout << int(*it++) << (it != container.cend() ? "." : "");
    std::cout << std::endl;
}

/**
 * @brief Печать в консоль ip-адреса из std::tuple
 * @warning Типы в std::tuple не должны различаться!
 * @param ip - ip-адрес в виде std::tuple
 */
template <typename ... T>
void print_ip(const std::tuple<T...> &ip) {
    static_assert(is_all_of<T...>::value, "tuple detect different types");
    print_tuple<std::tuple<T...>, 0, sizeof...(T)>::print(ip);
}
