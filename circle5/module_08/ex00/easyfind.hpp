/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 13:46:27 by fbaras            #+#    #+#             */
/*   Updated: 2026/09/24 13:46:27 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <iterator>
#include <exception>

template<typename T>
int	easyFind(T &container, int value)
{
	typename T::iterator found = std::find(container.begin(), container.end(), value);

	if (found == container.end())
		throw std::out_of_range("Not found");
	return std::distance(container.begin(), found);
}
