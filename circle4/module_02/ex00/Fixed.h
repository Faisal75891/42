/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 21:36:33 by fbaras            #+#    #+#             */
/*   Updated: 2026/08/05 21:36:33 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <string>

class Fixed
{
	private:
		int					raw_bits;
		const static	int	f_bits = 8;
	public:
		// default constructor
		Fixed();

		// my constructor
		Fixed(int n);

		// copy constructor
		Fixed(const Fixed &src);

		// copy assignment operarot
		Fixed& operator=(const Fixed &src);

		int		getRawBits(void) const;
		void	setRawBits( int const raw_bits);
		~Fixed();
};


#endif