/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_casting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeriau <rmeriau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:01:06 by rmeriau           #+#    #+#             */
/*   Updated: 2023/11/20 11:01:07 by rmeriau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	get_color(char *s)
{
	char			**comp;
	unsigned int	color;
	int				r;
	int				g;
	int				b;

	comp = ft_split_char(s, ',');
	if (!comp)
		return (0);
	r = ft_atoi(comp[0]);
	g = ft_atoi(comp[1]);
	b = ft_atoi(comp[2]);
	color = ((unsigned int)r << 16 | (unsigned int)g << 8 | (unsigned int)b);
	free_tab(comp);
	return (color);
}

void	floor_casting(t_map *data)
{
	int				y;
	int				x;
	unsigned int	ceiling_color;
	unsigned int	floor_color;

	ceiling_color = get_color(data->c_color);
	floor_color = get_color(data->f_color);
	x = 0;
	while (x < data->width)
	{
		y = 0;
		while (y < data->height && data->buffer[y][x] == 0)
			data->buffer[y++][x] = ceiling_color;
		while (y < data->height && data->buffer[y][x] != 0)
			y++;
		while (y < data->height && data->buffer[y][x] == 0)
			data->buffer[y++][x] = floor_color;
		x++;
	}
}
