/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 21:07:27 by fbaras            #+#    #+#             */
/*   Updated: 2025/12/20 21:07:27 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_split(char **s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
	return ;
}

int	get_map_height(char *map_name)
{
	char	*line;
	int		height;
	int		fd;

	height = 0;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	return (height);
}

int	get_line_width(char **line)
{
	int		width;

	width = 0;
	while (line[width])
		width++;
	return (width);
}

t_map	*get_fdf_map(char *map_name)
{
	char	*line;
	char	**fdf_line;
	t_map	*map;
	int		fd;
	int		i;

	// TODO: handle errors and exit.!
	// TODO: init variables.
	map = malloc (sizeof(t_map));
	map->width = 0;
	map->array_size = 0;
	map->scale = 0;
	map->array = NULL;
	map->rotate_x = 0;
	map->rotate_y = 0;
	map->rotate_z = 0;
	map->translate_x = 420;
	map->translate_y = -80;
	map->scale_offset = -19;
	map->height = get_map_height(map_name);
	fd = open(map_name, O_RDONLY);
	// if (fd == -1)
	// 	return (NULL);
	map->array = malloc(sizeof(t_coord *) * map->height); //height of fdf map
	// if (!map->array)
	// 	return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		fdf_line = ft_split(line, ' ');
		// if (!fdf_line)
		// 	return (NULL);
		i = 0;
		map->width = get_line_width(fdf_line);
		map->array[map->array_size] = malloc (sizeof(t_coord) * map->width);
		while (fdf_line[i])
		{
			if (ft_strchr(fdf_line[i], ','))
				map->array[map->array_size][i].color = parse_hex_color(ft_strchr(fdf_line[i], ',') + 1);
			else
				map->array[map->array_size][i].color = create_color(255,255,255);
			map->array[map->array_size][i].z = ft_atoi(fdf_line[i]);
			i++;
		}
		map->array_size++;
		free_split(fdf_line);
		free(line);
		line = get_next_line(fd);
	}
	return (map);
}
