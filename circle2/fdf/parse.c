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

// uses malloc
t_coord	*fill_line(char **fdf_line, int width, int row_index)
{
	t_coord	*array;
	int		i;

	array = malloc(sizeof(t_coord) * width);
	if (!array)
		return (NULL);
	i = 0;
	while (i < width)
	{
		if (ft_strchr(fdf_line[i], ','))
			array[i].color = parse_hex_color(ft_strchr(fdf_line[i], ',') + 1);
		else
			array[i].color = 0xFFFFFF;
		array[i].x = i;
		array[i].y = row_index;
		array[i].z = ft_atoi(fdf_line[i]);
		i++;
	}
	return (array);
}

int	parse_single_line(t_map *map, char *line)
{
	char	**fdf_line;
	int		line_width;

	fdf_line = ft_split(line, ' ');
	if (!fdf_line)
		return (0);
	line_width = get_line_width(fdf_line);
	if (line_width == 0)
		return (0);
	if (map->rows_filled == 0)
		map->width = line_width;
	map->array[map->rows_filled]
		= fill_line(fdf_line, map->width, map->rows_filled);
	if (!map->array[map->rows_filled])
		return (0);
	map->rows_filled++;
	free_split(fdf_line);
	return (1);
}

int	parse_all_lines(t_map *map, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (0);
	while (line)
	{
		if (!parse_single_line(map, line))
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}

int	parse_map(t_map *map, char *map_name)
{
	int	status;
	int	fd;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (0);
	status = parse_all_lines(map, fd);
	close (fd);
	return (status);
}

// checks for correct file format, returns fdf map or null
t_map	*get_fdf_map(char *map_name)
{
	t_map	*map;

	if (!ends_with_fdf(map_name))
		return (NULL);
	map = allocate_and_init_map(map_name);
	if (!map)
		return (NULL);
	if (!parse_map(map, map_name))
	{
		free_map(map);
		return (NULL);
	}
	return (map);
}
