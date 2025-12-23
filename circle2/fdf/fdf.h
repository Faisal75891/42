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
	int	color;
}	t_coord;

typedef struct s_map
{
	t_coord	**array;
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

	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}   t_mlx_data;


char	*get_next_line(int fd);
t_map	*get_fdf_map(char *map_name);
void	draw_grid(t_mlx_data *mlx_data);
int		create_color(int r, int g, int b);
void	my_pixel_put(t_mlx_data *data, int x, int y, int color);
t_point	isometric_projection(t_coord p3d, int scale, int offset_x, int offset_y);
void	DDA_line(t_mlx_data *mlx_data, t_point line1, t_point line2, int color);
t_coord	rotate_point(t_coord p, float angle_x, float angle_y, float angle_z);
void	print_map(t_map *fdf_map);
int		parse_hex_color(char *hex);
void	clear_image(t_mlx_data *data);
t_coord	project_point(t_mlx_data *mlx_data, int x, int y);

// event handling
void	handle_panning(int keysym, t_mlx_data *mlx_data);
void	handle_rotate(int keysym, t_mlx_data *mlx_data);
void	handle_scaling(int keysym, t_mlx_data *mlx_data);
int		do_nothing (t_mlx_data *mlx_data);
int		handle_exit(int keysym, t_mlx_data *mlx_data)



// event handling helpers
int is_rotate(int keysym);
int is_scale(int keysym);
int is_pan(int keysym);

# define HEIGHT 1920
# define WIDTH 1080

#endif
