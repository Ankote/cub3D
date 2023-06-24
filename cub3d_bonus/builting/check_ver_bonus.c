/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ver_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 10:42:10 by aankote           #+#    #+#             */
/*   Updated: 2023/06/20 11:14:57 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	check_hit_ver(char **map, int x_cor, int y_cor)
{
	int	x;
	int	y;

	x = x_cor / CARE;
	y = y_cor / CARE;
	if (map[y][x] == '1' || map[y][x - 1] == '1')
		return (0);
	if (map[y][x] == ' ' || map[y][x - 1] == ' ')
		return (0);
	return (1);
}

void	get_intercepts_ver(t_data *data)
{
	double	tang;

	tang = tan(data->player.ray_angle);
	data->cords.xinterc_ver = floor(data->player.px_pos / CARE) * CARE;
	if (cos(data->player.ray_angle) >= 0)
		data->cords.xinterc_ver += CARE;
	data->cords.yinterc_ver = data->player.py_pos + tang
		* ((data->cords.xinterc_ver - data->player.px_pos));
	if (data->cords.yinterc_ver >= data->win.map_y)
		data->cords.yinterc_ver = data->win.map_y - CARE;
	if (data->cords.yinterc_ver <= 0)
		data->cords.yinterc_ver = 0;
	data->cords.xb_ver = data->cords.xinterc_ver;
	data->cords.yb_ver = data->cords.yinterc_ver ;
}

int	hit_ver_wall(t_data *data)
{
	double	x_step;

	get_intercepts_ver(data);
	data->cords.ysteps_ver = CARE * fabs(tan(data->player.ray_angle));
	if (sin(data->player.ray_angle) < 0)
		data->cords.ysteps_ver = -CARE * fabs(tan(data->player.ray_angle));
	x_step = CARE;
	if (cos(data->player.ray_angle) <= 0)
		x_step = -CARE;
	while (1)
	{
		if (data->cords.yb_ver >= data->win.map_y)
			data->cords.yb_ver = data->win.map_y - CARE;
		if (data->cords.yb_ver <= 0)
			data->cords.yb_ver = 0;
		if (!check_hit_ver(data->map->map_copy,
				data->cords.xb_ver, data->cords.yb_ver))
			return (1);
		data->cords.xb_ver += x_step;
		data->cords.yb_ver += data->cords.ysteps_ver;
	}
	return (0);
}
