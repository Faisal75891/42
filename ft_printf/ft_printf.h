/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:34:12 by fbaras            #+#    #+#             */
/*   Updated: 2025/08/05 19:45:42 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct s_flags
{
	int has_minus;
	int has_dot;
	int has_zero;
	int has_hash;
	int has_plus;
	int has_space;
    int width;
	int precision;
}	t_flags;


#include <stdarg.h>

int	ft_printf(const char *, ...);

#endif