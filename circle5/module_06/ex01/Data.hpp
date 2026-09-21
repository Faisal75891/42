/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 10:33:38 by fbaras            #+#    #+#             */
/*   Updated: 2026/09/20 10:33:38 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

struct Data
{
	int	a;
	int	b;
	char c;
	Data();
	~Data();
    Data(const Data& e);
    Data&   operator=(const Data& e);
};
