/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 17:42:00 by fbaras            #+#    #+#             */
/*   Updated: 2026/09/23 17:42:00 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template<typename T>
class Array
{
	private:
		T				*arr;
		unsigned int	cnt;
	public:
		Array();
		~Array();
		Array(unsigned int n);
		Array(const Array& array);
		T&				operator=(const Array& array);
		T&				operator[] (unsigned int i);
		const T&		operator[] (unsigned int i) const;
		unsigned int	size() const;
};

#include "Array.tpp"
