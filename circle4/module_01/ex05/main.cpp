/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 23:50:35 by fbaras            #+#    #+#             */
/*   Updated: 2026/08/04 23:50:35 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"

int	main(void)
{
	Harl h;

	h.complain("INFO");
	h.complain("WARNING");
	h.complain("DEBUG");
	h.complain("ERROR");
	h.complain("ffasjflkas");
	return (0);
}
