/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 23:50:33 by fbaras            #+#    #+#             */
/*   Updated: 2026/08/04 23:50:33 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HARL_H
#define HARL_H

#include <iostream>
#include <string>

class Harl
{
private:
	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );
public:
	Harl(/* args */);
	~Harl();
	void	complain(std::string level);
};

#endif