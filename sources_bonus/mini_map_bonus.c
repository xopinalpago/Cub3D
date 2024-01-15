/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:23:42 by aducobu           #+#    #+#             */
/*   Updated: 2023/11/21 13:51:13 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	end_draw_fixed(t_map *d, t_2D p, t_2D square, int pixel_size)
{
	if (d->map[p.y][p.x] == '0' || is_carac_minimap(d->map[p.y][p.x])
			|| (d->map[p.y][p.x] == 'D' && d->doors == -1))
		draw_rectangle(d, square, pixel_size, 0xFFFFFF);
	else if (d->map[p.y][p.x] == 'D' && d->doors == 1)
		draw_rectangle(d, square, pixel_size, 0x008000);
	else if (d->map[p.y][p.x] == 'C')
	{
		draw_rectangle(d, square, pixel_size, 0xFFFFFF);
		square.x += pixel_size / 2;
		square.y += pixel_size / 2;
		draw_circle(d, square, pixel_size / 2, 0xFFD700);
	}
	else
		draw_rectangle(d, square, pixel_size, 0x000000);
}

void	do_draw_fixed(t_map *d, t_2D start, t_2D end, int pixel_size)
{
	t_2D	square;
	t_2D	p;

	p.y = start.y;
	p.x = start.x;
	while (p.y <= end.y)
	{
		p.x = start.x;
		while (p.x <= end.x)
		{
			square.x = (p.x - start.x) * pixel_size;
			square.y = (p.y - start.y) * pixel_size;
			if (p.y < 0 || p.y >= d->nb_line || p.x < 0
				|| p.x >= ft_strlen(d->map[p.y]))
				draw_rectangle(d, square, pixel_size, 0x000000);
			else
				end_draw_fixed(d, p, square, pixel_size);
			p.x++;
		}
		p.y++;
	}
}

void	draw_fixed_mini_map(t_map *data, t_2D view, int pixel_size)
{
	t_2D	start;
	t_2D	end;

	start.x = (int)data->posx - view.x;
	start.y = (int)data->posy - view.y;
	end.x = data->posx + view.x;
	end.y = data->posy + view.y;
	do_draw_fixed(data, start, end, pixel_size);
}

int	mini_map(t_map *data)
{
	t_2D	minimap_center;
	t_2D	view;
	int		pixel_size;

	pixel_size = 8;
	view.x = 5;
	view.y = 3;
	minimap_center.x = (view.x * 2 * pixel_size + 8) / 2;
	minimap_center.y = ((view.y + 1) * 2 * pixel_size - 8) / 2;
	draw_fixed_mini_map(data, view, pixel_size);
	draw_circle(data, minimap_center, pixel_size / 4, 0xFF0000);
	return (0);
}
