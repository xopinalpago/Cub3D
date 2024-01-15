/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmeriau <rmeriau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:01:02 by rmeriau           #+#    #+#             */
/*   Updated: 2023/11/20 11:01:03 by rmeriau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_buffer(t_map *data)
{
	int	x;
	int	y;

	y = 0;
	data->buffer = malloc(sizeof(unsigned int *) * (data->height));
	if (!data->buffer)
		return (0);
	while (y < data->height)
	{
		x = 0;
		data->buffer[y] = malloc(sizeof(unsigned int) * (data->width));
		if (!data->buffer[x])
			return (free_buffer(data->buffer, data), 0);
		while (x < data->width)
		{
			data->buffer[y][x] = 0;
			x++;
		}
		y++;
	}
	return (1);
}

void	display(t_map *data)
{
	int	y;
	int	x;

	if (!init_buffer(data))
	{
		printf("Error\nMalloc");
		return ;
	}
	wall_casting(data);
	floor_casting(data);
	draw(data);
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			data->buffer[y][x] = 0;
			x++;
		}
		y++;
	}
	free_buffer(data->buffer, data);
}

void	draw(t_map *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			data->main.data[y * data->width + x] = data->buffer[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->main.img, 0, 0);
}
