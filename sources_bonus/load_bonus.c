/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:23:32 by aducobu           #+#    #+#             */
/*   Updated: 2023/11/21 13:54:31 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	load_img(t_map *data, t_image *img, char *path, int i)
{
	int	y;
	int	x;

	img->img = mlx_xpm_file_to_image(data->mlx_ptr, path, &data->tex_width,
			&data->tex_height);
	if (!img->img)
		return (printf("Error\nCannot load texture\n"), 0);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size,
			&img->endian);
	if (!img->data)
		return (printf("Error\nCannot load texture\n"), 0);
	data->tex[i] = malloc(sizeof(int) * (data->tex_height * data->tex_width));
	if (!data->tex[i])
		return (printf("Error\nMalloc textures\n"), 0);
	data->len_tex++;
	y = -1;
	while (++y < data->tex_height)
	{
		x = -1;
		while (++x < data->tex_width)
			data->tex[i][y * data->tex_width + x] = img->data[y
				* data->tex_width + x];
	}
	mlx_destroy_image(data->mlx_ptr, data->img.img);
	return (1);
}

int	load_tex_part2(t_map *data)
{
	if (data->path_d && data->nb_doors)
	{
		if (!load_img(data, &data->img, data->path_d, 4))
			return (0);
	}
	if (data->path_co && data->nb_sprites)
	{
		if (data->nb_doors)
		{
			if (!load_img(data, &data->img, data->path_co, 5))
				return (0);
		}
		else
		{
			if (!load_img(data, &data->img, data->path_co, 4))
				return (0);
		}
		if (!init_sprite(data))
			return (0);
	}
	return (1);
}

int	load_tex(t_map *data)
{
	data->tex = malloc(sizeof(int *) * (data->nb_tex));
	if (!data->tex)
		return (printf("Error\nMalloc\n"), 0);
	if (!load_img(data, &data->img, data->path_n, 0))
		return (0);
	if (!load_img(data, &data->img, data->path_s, 1))
		return (0);
	if (!load_img(data, &data->img, data->path_w, 2))
		return (0);
	if (!load_img(data, &data->img, data->path_e, 3))
		return (0);
	if (!load_tex_part2(data))
		return (0);
	return (1);
}
