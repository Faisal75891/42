/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 20:03:11 by fbaras            #+#    #+#             */
/*   Updated: 2025/12/24 20:03:11 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	apply_opacity(int color, float opacity)
{
	int r = ((color >> 16) & 0xFF) * opacity;
	int g = ((color >> 8) & 0xFF) * opacity;
	int b = (color & 0xFF) * opacity;
	return (r << 16 | g << 8 | b);
}

void	wu_line(t_mlx_data *data, t_point s, t_point e)
{
	float	dx = e.x - s.x;
	float	dy = e.y - s.y;
	float	gradient;
	int		color1, color2;
	
	// Edge case: same point
	if (s.x == e.x && s.y == e.y)
	{
		my_pixel_put(data, s.x, s.y, s.color);
		return;
	}
	
	// Swap if drawing right to left
	if (s.x > e.x)
	{
		t_point tmp = s;
		s = e;
		e = tmp;
		dx = -dx;
		dy = -dy;
	}
	
	// Check if line is steep (iterate over y) or shallow (iterate over x)
	if (fabs(dy) > fabs(dx))
	{
		// Steep line: iterate over y
		gradient = dx / dy;
		if (s.y > e.y)
		{
			t_point tmp = s;
			s = e;
			e = tmp;
		}
		float x = s.x;
		int y = s.y;
		while (y <= e.y)
		{
			float frac = x - (int)x;
			color1 = apply_opacity(s.color, 1.0 - frac);
			color2 = apply_opacity(s.color, frac);
			my_pixel_put(data, (int)x, y, color1);
			my_pixel_put(data, (int)x + 1, y, color2);
			x += gradient;
			y++;
		}
	}
	else
	{
		// Shallow line: iterate over x
		gradient = dy / dx;
		float y = s.y;
		int x = s.x;
		while (x <= e.x)
		{
			float frac = y - (int)y;
			color1 = apply_opacity(s.color, 1.0 - frac);
			color2 = apply_opacity(s.color, frac);
			my_pixel_put(data, x, (int)y, color1);
			my_pixel_put(data, x, (int)y + 1, color2);
			y += gradient;
			x++;
		}
	}
}
