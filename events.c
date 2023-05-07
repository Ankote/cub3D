/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:48:48 by aankote           #+#    #+#             */
/*   Updated: 2023/05/07 18:09:44 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_exit(void *key)
{
	(void)key;
    printf("Exit\n");
	exit(0);
}

int ft_key_hook(int key, t_data *data)
{
    printf("%d\n", key);
    if(key == 53)
    {
        printf("Exit\n");
        exit (0);
    }
    if(key == 13)
    {
        printf("Up\n");
        move_up(data);
    }
    if(key == 2)
    {
        printf("Right\n");
        move_right(data);
    }
    if(key == 0)
    {
        move_left(data);
        printf("Left\n");
    }
    if(key == 1)
    {
        move_down(data);
        printf("down\n");
    }
    draw_lines(data);
    return (0);
}