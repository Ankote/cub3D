/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:39:40 by aankote           #+#    #+#             */
/*   Updated: 2023/05/07 08:48:42 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int create_window(t_mlxk *win)
{
    win->mlx = mlx_init();
    win->mlx_win = mlx_new_window(win->mlx, WIN_X,
			WIN_Y, "SAIYANS cub3D");
    win->img = mlx_new_image(win->mlx, 1920, 1080);
    return (0);
}

int initializ(t_data *data)
{
    data->px_pos = 300;
    data->py_pos = 200;
    draw_map(data->win);
    draw_lines(data->win);
    draw_player(data, data->px_pos, data->py_pos);  
    return (0);
}

// int main(int ac, char **av)
// {
//     t_mlxk window;
//     t_data *data;
//     char **map;
//     int fd;
    
//     (void)ac;
//     data = (t_data *)malloc(sizeof(t_data));
//     create_window(&window);
//     data->win = window;
//     initializ(data);
//     fd = open(av[1], O_RDONLY, 0777);
//     map = split_map(fd);
//     mlx_hook(data->win.mlx_win, 17, 0, &ft_exit, NULL);
//     mlx_hook(window.mlx_win, 2, 0, ft_key_hook, data);
//     mlx_loop(window.mlx);
// }

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}