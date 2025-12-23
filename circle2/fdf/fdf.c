/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 18:36:18 by fbaras            #+#    #+#             */
/*   Updated: 2025/12/18 19:51:13 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_exit(int keysym, t_mlx_data *mlx_data)
{
	if (keysym == 65307)
	{
		clear_image(mlx_data);
		mlx_destroy_window(mlx_data->mlx_ptr, mlx_data->win_ptr);
		free(mlx_data->mlx_ptr);
		exit(0);
	}
	else if (keysym == 101)
	{
		mlx_data->fdf_map->scale_offset++;
		clear_image(mlx_data);
		draw_grid(mlx_data);
	}
	else if (keysym == 113)
	{
		mlx_data->fdf_map->scale_offset--;
		clear_image(mlx_data);
		draw_grid(mlx_data);
	}
	else if (keysym == 65362)
	{
		mlx_data->fdf_map->rotate_x += 10;
		clear_image(mlx_data);
		draw_grid(mlx_data);
	}
	else if (keysym == 65364)
	{
		mlx_data->fdf_map->rotate_x -= 10;
		clear_image(mlx_data);
		draw_grid(mlx_data);
	}
	else if (keysym == 65361)
	{
		mlx_data->fdf_map->rotate_y += 10;
		clear_image(mlx_data);
		draw_grid(mlx_data);
	}
	else if (keysym == 65363)
	{
		mlx_data->fdf_map->rotate_y -= 10;
		clear_image(mlx_data);
		draw_grid(mlx_data);
	}
	else if (keysym == 122)
	{
		mlx_data->fdf_map->rotate_z += 10;
		clear_image(mlx_data);
		draw_grid(mlx_data);
	}
	else if (keysym == 120)
	{
		mlx_data->fdf_map->rotate_z -= 10;
		clear_image(mlx_data);
		draw_grid(mlx_data);
	}
	else if (keysym == 119)  // 'w' - move up
	{
		mlx_data->fdf_map->translate_y -= 10;
		clear_image(mlx_data);
		draw_grid(mlx_data);
	}
	else if (keysym == 115)  // 's' - move down
	{
		mlx_data->fdf_map->translate_y += 10;
		clear_image(mlx_data);
		draw_grid(mlx_data);
	}
	else if (keysym == 97)   // 'a' - move left
	{
		mlx_data->fdf_map->translate_x -= 10;
		clear_image(mlx_data);
		draw_grid(mlx_data);
	}
	else if (keysym == 100)  // 'd' - move right (change from 'e')
	{
		mlx_data->fdf_map->translate_x += 10;
		clear_image(mlx_data);
		draw_grid(mlx_data);
	}
	ft_printf("key pressed: %d\n", keysym);
	return (0);
}

int	do_nothing (t_mlx_data *mlx_data)
{
	(void) mlx_data;
	return (0);
}

void	clear_image(t_mlx_data *data)
{
	ft_memset(data->addr, 0, HEIGHT * data->line_length);
}

int	parse_hex_color(char *hex)
{
	int	val;
	int	i;
	int	byte;

	val = 0;
	i = 1;
	while (hex[i])
	{
		byte = hex[i];
		if (byte >= '0' && byte <= '9')
			byte = byte - '0';
		else if (byte >= 'a' && byte <= 'f')
			byte = byte - 'a' + 10;
		else if (byte >= 'A' && byte <= 'F')
			byte = byte - 'A' + 10;
		val = (val << 4) | (byte & 0xf);
		i++;
	}
	return (val);
}

void	my_pixel_put(t_mlx_data *data, int x, int y, int color)
{
	char	*dst;
	int		offset;

	if (x >= WIDTH || x < 0 || y < 0 ||  y >= HEIGHT)
		return ;
	offset = (y * data->line_length + x * (data->bpp / 8));
	dst = data->addr + offset;
	*(unsigned int *) dst = color;
}

void	DDA_line(t_mlx_data *mlx_data, t_point line1, t_point line2, int color)
{
    float	delta_x;
    float	delta_y;
    int	    steps;
    float	x_inc;
    float	y_inc;
    float	x;
    float	y;
    int	    i;

    delta_x = line2.x - line1.x;  // DON'T use fabs here - keep the sign!
    delta_y = line2.y - line1.y;  // DON'T use fabs here - keep the sign!
    
    // Use fabs only to determine number of steps
    if (fabs(delta_x) > fabs(delta_y))
        steps = fabs(delta_x);
    else
        steps = fabs(delta_y);
    
    // Increments will have correct sign (negative or positive)
    x_inc = delta_x / (float)steps;
    y_inc = delta_y / (float)steps;

    x = line1.x;
    y = line1.y;

    i = 0;
    while (i <= steps)
    {
        my_pixel_put(mlx_data, (int)x, (int)y, color);
        x += x_inc;
        y += y_inc;
        i++;
    }
}
t_point	isometric_projection(t_coord p3d, int scale, int offset_x, int offset_y)
{
	t_point	p;

	p.x = (p3d.x - p3d.y) * cos(0.523599) * scale + offset_x;
	p.y = ((p3d.x + p3d.y) * sin(0.523599) - p3d.z) * scale + offset_y;

	return (p);
}

void	print_map(t_map *fdf_map)
{
	for (int y = 0; y < fdf_map->height; y++)
	{
		for (int x = 0; x < fdf_map->width; x++)
		{
			ft_printf("[%d]", fdf_map->array[y][x]);
		}
		ft_printf(" ");
		ft_printf("\n");
	}
}

// copied from chatgpt lol
t_coord	rotate_point(t_coord p, float angle_x, float angle_y, float angle_z)
{
	t_coord	rotated;
	float	rad_x;
	float	rad_y;
	float	rad_z;
	float	y1;
	float	z1;
	float	x2;
	float	z2;

	rad_x = angle_x * 0.0174533;  // Convert to radians
    rad_y = angle_y * 0.0174533;
    rad_z = angle_z * 0.0174533;
	y1 = p.y * cos(rad_x) - p.z * sin(rad_x);
	z1 = p.y * sin(rad_x) + p.z * cos(rad_x);
	x2 = p.x * cos(rad_y) + z1 * sin(rad_y);
	z2 = -p.x * sin(rad_y) + z1 * cos(rad_y);
	rotated.x = x2 * cos(rad_z) - y1 * sin(rad_z);
	rotated.y = x2 * sin(rad_z) + y1 * cos(rad_z);
	rotated.z = z2;
	rotated.color = p.color;
	return (rotated);
}

void	draw_grid(t_mlx_data *mlx_data)
{	
	t_coord	p1;
	t_coord	p2;
	int		color;

	mlx_data->fdf_map->scale = (WIDTH / 0.6) / (mlx_data->fdf_map->height + mlx_data->fdf_map->width) + mlx_data->fdf_map->scale_offset;
	mlx_data->fdf_map->offset_x = (WIDTH/ 4);
	mlx_data->fdf_map->offset_y = (HEIGHT / 4);
	int y = 0;
	while(y < mlx_data->fdf_map->height)
	{
		int x = 0;
		while (x < mlx_data->fdf_map->width)
		{			
			p1.x = x;
			p1.y = y;
			p1.z = mlx_data->fdf_map->array[y][x].z;
			p1.color = mlx_data->fdf_map->array[y][x].color;
			p1 = rotate_point(p1, mlx_data->fdf_map->rotate_x, mlx_data->fdf_map->rotate_y, mlx_data->fdf_map->rotate_z);
			t_point coord1 = isometric_projection(p1, mlx_data->fdf_map->scale, mlx_data->fdf_map->offset_x + mlx_data->fdf_map->translate_x, mlx_data->fdf_map->offset_y + mlx_data->fdf_map->translate_y);
			if (x + 1< mlx_data->fdf_map->width)
			{
				p2.x = x + 1;
				p2.y = y;
				p2.z = mlx_data->fdf_map->array[y][x + 1].z;
				p2.color = mlx_data->fdf_map->array[y][x + 1].color;
				color = (p1.color + p2.color ) / 2;
				p2 = rotate_point(p2, mlx_data->fdf_map->rotate_x, mlx_data->fdf_map->rotate_y, mlx_data->fdf_map->rotate_z);
				t_point coord2 = isometric_projection(p2, mlx_data->fdf_map->scale, mlx_data->fdf_map->offset_x + mlx_data->fdf_map->translate_x, mlx_data->fdf_map->offset_y + mlx_data->fdf_map->translate_y);
				DDA_line(mlx_data, coord1, coord2, color);
			}
			if (y + 1 < mlx_data->fdf_map->height)
			{
				p2.x = x;
				p2.y = y + 1;
				p2.z = mlx_data->fdf_map->array[y + 1][x].z;
				p2.color = mlx_data->fdf_map->array[y + 1][x].color; 
				color = (p1.color + p2.color ) / 2;
				p2 = rotate_point(p2, mlx_data->fdf_map->rotate_x, mlx_data->fdf_map->rotate_y, mlx_data->fdf_map->rotate_z);
				t_point coord2 = isometric_projection(p2, mlx_data->fdf_map->scale, mlx_data->fdf_map->offset_x + mlx_data->fdf_map->translate_x, mlx_data->fdf_map->offset_y + mlx_data->fdf_map->translate_y);
				DDA_line(mlx_data, coord1, coord2, color);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->win_ptr, mlx_data->img, 0, 0);

}

int	create_color(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	main(int argc, char **argv)
{
	t_mlx_data	*mlx_data;
	(void)argc;
	//(void)argv;

	mlx_data = malloc (sizeof(t_mlx_data));
	if (!mlx_data)
		return (1);
	mlx_data->mlx_ptr = mlx_init();
	if (!mlx_data->mlx_ptr)
		return (1);
	mlx_data->win_ptr = mlx_new_window(mlx_data->mlx_ptr, WIDTH, HEIGHT, "sigma");
	if (mlx_data->win_ptr == NULL)
	{
		free(mlx_data->mlx_ptr);
		return (1);
	}
	mlx_data->img = mlx_new_image(mlx_data->mlx_ptr, WIDTH, HEIGHT);
	mlx_data->addr = mlx_get_data_addr(mlx_data->img, &mlx_data->bpp, &mlx_data->line_length, &mlx_data->endian);
	mlx_data->filename = argv[1];
	mlx_data->fdf_map = get_fdf_map(mlx_data->filename);
	if (!mlx_data->fdf_map->array)
		return (1);
	draw_grid(mlx_data);
	mlx_loop_hook(mlx_data->mlx_ptr, &do_nothing, mlx_data);
	mlx_key_hook(mlx_data->win_ptr, &handle_exit, mlx_data);
	mlx_loop(mlx_data->mlx_ptr);
}
