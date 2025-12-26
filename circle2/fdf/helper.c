/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 22:45:51 by fbaras            #+#    #+#             */
/*   Updated: 2025/12/23 22:45:51 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	create_color(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	print_map(t_map *fdf_map)
{
	int	y;
	int	x;

	y = 0;
	while (y < fdf_map->height)
	{
		x = 0;
		while (x < fdf_map->width)
		{
			ft_printf("[%d]", fdf_map->array[y][x].z);
			x++;
		}
		ft_printf(" ");
		ft_printf("\n");
		y++;
	}
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

	if (x >= WIDTH || x < 0 || y < 0 || y >= HEIGHT)
		return ;
	offset = (y * data->line_length + x * (data->bpp / 8));
	dst = data->addr + offset;
	*(unsigned int *) dst = color;
}
