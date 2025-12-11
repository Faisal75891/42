/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 18:36:21 by fbaras            #+#    #+#             */
/*   Updated: 2025/12/11 21:35:07 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx/mlx.h"
# include <stdlib.h>
# include "./ft_printf/ft_printf.h"
# include "./ft_printf/libft/libft.h"

typedef struct s_mlx_data
{
    void    *mlx_ptr;
    void    *win_ptr;
}   t_mlx_data;

# define HEIGHT 500
# define WIDTH 500

#endif
