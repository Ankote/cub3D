/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:39:40 by aankote           #+#    #+#             */
/*   Updated: 2023/05/22 18:38:48 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(int ac ,char **av)
{
	t_win window;
	t_data *data;
	int fd;
	ac = 00;
	
	data = (t_data *)malloc(sizeof(t_data));
	fd = open(av[1], O_RDONLY, 0777);
	data->map = split_map(fd);
	create_window(&window, data);
	get_dimensions(data); 
	data->player.routation_ang = PI / 2;
	data->player.ray_angle = data->player.routation_ang;
	data->player.turn_dir = 0;
	data->player.walk_dir = 0;
	draw_win(data);
	create_map(data);
	mlx_hook(data->win.mlx_win, 17, 0, &ft_exit, NULL);
    mlx_hook(window.mlx_win, 2, 0, ft_key_hook, data);
	mlx_loop(window.mlx);
}
