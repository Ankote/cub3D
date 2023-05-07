/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:39:40 by aankote           #+#    #+#             */
/*   Updated: 2023/05/07 18:45:58 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int create_window(t_mlxk *win)
{
    win->mlx = mlx_init();
    win->mlx_win = mlx_new_window(win->mlx, WIN_X,
			WIN_Y, "SAIYANS cub3D");
    return (0);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(int ac ,char **av)
{
	t_mlxk window;
	t_data *data;
	int fd;
	ac = 00;
	
	fd = open(av[1], O_RDONLY, 0777);
	data->map = split_map(fd);
	data = (t_data *)malloc(sizeof(t_data));
	create_window(&window);
	data->win = window;
	create_map(data);
	mlx_hook(data->win.mlx_win, 17, 0, &ft_exit, NULL);
    mlx_hook(window.mlx_win, 2, 0, ft_key_hook, data);
	mlx_loop(window.mlx);
}