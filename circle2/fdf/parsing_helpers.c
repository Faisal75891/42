/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 03:47:07 by fbaras            #+#    #+#             */
/*   Updated: 2025/12/25 03:47:07 by fbaras           ###   ########.fr       */
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

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->array)
	{
		i = 0;
		while (i < map->rows_filled)
		{
			if (map->array[i])
				free(map->array[i]);
			i++;
		}
		free(map->array);
	}
	free(map);
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

int	ends_with_fdf(char *map_name)
{
	int	i;
	int	ext_len;

	ext_len = 0;
	i = 0;
	if (!map_name)
		return (1);
	while (map_name && map_name[i] != '.')
		i++;
	if (!map_name[i])
		return (1);
	while (map_name[i + ext_len])
		ext_len++;
	if (ft_strncmp(map_name + i, ".fdf", ext_len))
		return (0);
	return (1);
}
