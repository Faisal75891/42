/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 17:11:45 by fbaras            #+#    #+#             */
/*   Updated: 2026/09/23 17:11:45 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(void)
{
	const int	c_arr[3] = {1, 2, 3};
	int	arr[3] = {1, 2, 3};

	iter(arr, 3, increment<int>);
	iter(arr, 3, print<int>);
	std::cout << '\n';
	iter(c_arr, 3, print<int>);
}
