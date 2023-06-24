/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_hor_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:31:04 by aankote           #+#    #+#             */
/*   Updated: 2023/06/20 11:14:48 by rakhsas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	check_hit_hor(char **map, int x_cor, int y_cor)
{
	int	x;
	int	y;

	x = x_cor / CARE;
	y = y_cor / CARE;
	if (map[y][x] == '1' || map[y - 1][x] == '1')
		return (0);
	if (map[y][x] == ' ' || map[y - 1][x] == ' ')
		return (0);
	return (1);
}

void	get_intercepts(t_data *data)
{
	data->cords.yinterc_hor = floor((data->player.py_pos) / CARE) * CARE;
	if (sin(data->player.ray_angle) >= 0)
		data->cords.yinterc_hor += CARE ;
	data->cords.xinterc_hor = data->player.px_pos + (data->cords.yinterc_hor
			- data->player.py_pos) / tan(data->player.ray_angle);
	if (data->cords.xinterc_hor >= data->win.map_x)
		data->cords.xinterc_hor = data->win.map_x - CARE;
	if (data->cords.yinterc_hor >= data->win.map_y)
		data->cords.yinterc_hor = data->win.map_y - CARE;
	if (data->cords.xinterc_hor <= 0)
		data->cords.xinterc_hor = 0;
	data->cords.xb_hor = data->cords.xinterc_hor;
	data->cords.yb_hor = data->cords.yinterc_hor;
}

int	hit_hor_wall(t_data *data)
{
	int	y_step;

	get_intercepts(data);
	data->cords.xsteps_hor = CARE / fabs(tan(data->player.ray_angle));
	if (cos(data->player.ray_angle) < 0)
		data->cords.xsteps_hor = -CARE / fabs(tan(data->player.ray_angle));
	y_step = CARE;
	if (sin (data->player.ray_angle) <= 0)
		y_step = -CARE;
	while (1)
	{
		if (data->cords.xb_hor >= data->win.map_x)
			data->cords.xb_hor = data->win.map_x - CARE;
		if (data->cords.xb_hor <= 0)
			data->cords.xb_hor = CARE;
		if (!check_hit_hor(data->map->map_copy,
				(int)data->cords.xb_hor, (int)data->cords.yb_hor))
			return (1);
		data->cords.xb_hor += data->cords.xsteps_hor;
		data->cords.yb_hor += y_step;
	}
}
