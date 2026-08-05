/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 21:37:20 by fbaras            #+#    #+#             */
/*   Updated: 2026/08/05 21:37:20 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

int main( void )
{
    Fixed a;
    Fixed c;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );


    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    c++;
    c++;
    // TODO: create the member functions
    // TODO: test all the other operations. < > <= >= == != 
    std::cout << (b == c) << std::endl;
    std::cout << (b >= c) << std::endl;
    std::cout << (b <= c) << std::endl;
    std::cout << (b > c) << std::endl;
    std::cout << (b < c) << std::endl;
    std::cout << (a != c) << std::endl;

    return 0;
}