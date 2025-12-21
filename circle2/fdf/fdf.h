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

# include "./minilibx/mlx/mlx.h"
# include "./minilibx/mlx_linux/mlx.h"
# include <stdlib.h>
# include "./ft_printf/ft_printf.h"
# include <fcntl.h>
# include <math.h>
#include <stdio.h>

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_coord
{
	int	x;
	int	y;
	int	z;
}	t_coord;

typedef struct s_map
{
	int		**array;
	int		height;
	int		width;
	int		array_size;
	int		scale;
	int		offset_x;
	int		offset_y;
	int		scale_offset;
	float	rotate_x;
	float	rotate_y;
	float	rotate_z;
	int		translate_x;
	int		translate_y;
}	t_map;

typedef struct s_mlx_data
{
	void    *mlx_ptr;
	void    *win_ptr;
	t_map	*fdf_map;
	char	*filename;
}   t_mlx_data;


char	*get_next_line(int fd);
t_map	*get_fdf_map(char *map_name);
void	draw_grid(t_mlx_data *mlx_data);
int		create_color(int r, int g, int b);
void	print_map(t_map *fdf_map);

# define HEIGHT 1920
# define WIDTH 1080

#endif
