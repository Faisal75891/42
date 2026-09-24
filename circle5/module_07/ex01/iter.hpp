/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 17:04:16 by fbaras            #+#    #+#             */
/*   Updated: 2026/09/23 17:04:16 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template<class T>
void    print(T& value)
{
    std::cout << value << '\n';
}

template<class T>
void    print(const T& value)
{
    std::cout << value << '\n';
}

template<class T>
void    increment(T &value)
{
    ++value;
}

template<typename T>
void iter(T* array, size_t length, void (*func)(T&))
{
    for (size_t i = 0; i < length; ++i)
        func(array[i]);
}

template<typename T>
void iter(const T* array, size_t length, void (*func)(const T&))
{
    for (size_t i = 0; i < length; ++i)
        func(array[i]);
}
