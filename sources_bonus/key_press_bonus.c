/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:23:27 by aducobu           #+#    #+#             */
/*   Updated: 2023/11/21 13:51:13 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	key_press(int keycode, t_map *data)
{
	if (keycode == 119)
		data->w = 1;
	else if (keycode == 115)
		data->s = 1;
	else if (keycode == 100)
		data->d = 1;
	else if (keycode == 97)
		data->a = 1;
	else if (keycode == 65363)
		data->right = 1;
	else if (keycode == 65361)
		data->left = 1;
	else if (keycode == 65505)
		data->shift = 1;
	else if (keycode == XK_Escape)
		mlx_loop_end(data->mlx_ptr);
	return (0);
}

int	key_release(int keycode, t_map *data)
{
	if (keycode == 119)
		data->w = 0;
	else if (keycode == 115)
		data->s = 0;
	else if (keycode == 100)
		data->d = 0;
	else if (keycode == 97)
		data->a = 0;
	else if (keycode == 101)
	{
		if (data->map[(int)data->posy][(int)data->posx] != 'D')
		{
			data->doors *= -1;
		}
	}
	else if (keycode == 65363)
		data->right = 0;
	else if (keycode == 65361)
		data->left = 0;
	else if (keycode == 65505)
		data->shift = 0;
	else if (keycode == 109)
		data->dis_map *= -1;
	return (0);
}

void	key_hook_part2(t_map *data)
{
	if (data->b_left == 1)
	{
		if (data->mx < (data->width / 2))
			mouse_x(data);
		if (data->mx > (data->width / 2))
			mouse_y(data);
	}
	else
	{
		mlx_mouse_show(data->mlx_ptr, data->win_ptr);
	}
}

int	key_hook(t_map *data)
{
	data->speed = 0.01;
	if (data->shift)
		data->speed = 0.03;
	if (data->w)
		w_key(data);
	if (data->s)
		s_key(data);
	if (data->a)
		a_key(data);
	if (data->d)
		d_key(data);
	if (data->right)
		right_key(data);
	if (data->left)
		left_key(data);
	key_hook_part2(data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	display(data);
	return (1);
}
