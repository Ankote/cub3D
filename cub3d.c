#include "cub3d.h"


void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	my_mlx_pixel_put1(t_data *data, t_img *img, int x, int y, int color)
{
	char	*dst;

	x /= 5;
	y /= 5;
	if ((x > 0 && x < WIN_X) && (y > 0 && y < WIN_Y))
	{
		x = x - ((data->player.px_pos / CARE) - 130);
		y = y - ((data->player.py_pos / CARE) - 130);
		dst = img->addr + (y * img->line_length
				+ x * (img->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

// int ft_key_hook2( t_data *data,int key)
// {
//     if(key < WIN_X / 2)
//     {
//         data->player.turn_dir = -1;
//         update_turn(data);
//     }
//     if(key > WIN_X / 2)
//     {
//        data->player.turn_dir = +1;
//        update_turn(data);
//     }
// 	return(0);
// }

int main(int ac ,char **av)
{
	t_win window;
	t_data *data;
	int fd;
	ac = 00;
	
	data = (t_data *)malloc(sizeof(t_data));
	fd = open(av[1], O_RDONLY, 0777);
	data->map = split_map(fd);
	get_player_pos(data);
	create_window(&window, data);
	initializ(data);
	mlx_hook(data->win.mlx_win, 17, 0, &ft_exit, NULL);
    mlx_hook(window.mlx_win, 2, 0, ft_key_hook, data);
	mlx_loop(window.mlx);
}
