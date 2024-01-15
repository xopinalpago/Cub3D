/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:22:39 by aducobu           #+#    #+#             */
/*   Updated: 2023/11/21 13:22:40 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
	free(data->sprite.sprite);
	free(data->sprite.sprite_order);
	free(data->sprite.sprite_dist);
	init_sprite(data);
	sprite_casting(data);
	draw(data);
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
			data->buffer[y][x++] = 0;
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
	if (data->dis_map == 1)
		mini_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->main.img, 0, 0);
}
