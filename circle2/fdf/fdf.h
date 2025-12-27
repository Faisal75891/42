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
	int	color;
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
	int		rows_filled;
	int		scale;
	int		offset_x;
	int		offset_y;
	int		scale_offset;
	float	rotate_x;
	float	rotate_y;
	float	rotate_z;
	int		translate_x;
	int		translate_y;
	float	altitude;
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

// drawing
void		draw_grid(t_mlx_data *mlx_data);
void		my_pixel_put(t_mlx_data *data, int x, int y, int color);
void		print_map(t_map *fdf_map);
void		clear_image(t_mlx_data *data);

// colors
int			create_color(int r, int g, int b);
int			parse_hex_color(char *hex);

// line algorithm
t_coord		rotate_point(t_coord p, t_mlx_data *data);
t_point		project_point(t_mlx_data *mlx_data, int x, int y);
t_point		isometric_projection(t_coord p3d, t_mlx_data *data);
void		dda_line(t_mlx_data *mlx_data, t_point point1, t_point point2, int color);
void		bresenham_line(t_mlx_data *mlx_data, t_point from, t_point to);

// event handling
void		handle_panning(int keysym, t_mlx_data *mlx_data);
void		handle_rotate(int keysym, t_mlx_data *mlx_data);
void		handle_scaling(int keysym, t_mlx_data *mlx_data);
void		handle_reset(int keysm, t_mlx_data *mlx_data);
int			handle_exit(int keysym, t_mlx_data *mlx_data);
int			handle_events(int keysym, t_mlx_data *mlx_data);

// event handling helpers
int 		is_rotate(int keysym);
int 		is_scale(int keysym);
int 		is_pan(int keysym);
int			do_nothing(t_mlx_data *mlx_data);

// init
t_mlx_data	*init_mlx_and_window_and_fdf_map(char *filename);
t_map		*allocate_and_init_map(char *map_name);
void		init_image(t_mlx_data *mlx_data);
void		init_fdf_map(t_mlx_data *mlx_data, char *filename);
t_map		*allocate_and_init_map(char *map_name);
int			get_z_range(t_map *map);

// parsing
int			get_map_height(char *map_name);
int			get_line_width(char **line);
char		*get_next_line(int fd);
t_map		*get_fdf_map(char *map_name);
int			parse_map(t_map *map, char *map_name);
void		apply_default_view(t_map *map);
int			ends_with_fdf(char *map_name);
void		free_map(t_map *map);
void		free_split(char **s);
void		free_map(t_map *map);

# define HEIGHT 1920
# define WIDTH 1080
# define WINDOW_NAME "fdf"

#endif
