/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:22:27 by aducobu           #+#    #+#             */
/*   Updated: 2023/11/21 13:54:31 by aducobu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	is_sp(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	is_digit_map(char c)
{
	if (c == '1' || c == '0')
		return (1);
	return (0);
}

int	is_carac_minimap(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	is_carac_map(char c, t_map *data)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	if (data->path_co != NULL && c == 'C')
		return (1);
	if (data->path_d != NULL && c == 'D')
		return (1);
	return (0);
}

int	test_valid_carac(char c, t_map *data)
{
	if (!is_carac_map(c, data) && !is_digit_map(c) && !is_sp(c))
		return (0);
	return (1);
}
