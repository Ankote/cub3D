/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:32:52 by aankote           #+#    #+#             */
/*   Updated: 2023/06/17 11:22:38 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int check_move(t_data *data, int x, int y)
{
    
    if(data->map[(y) / CARE][(x) / CARE] == '1')
        return(0);
    return (1);
}

 int move_up(t_data *data)
{
    int x;
    int y;
    double cosin;
    double sino;
    int i;

    i = 0;
    cosin = cos(data->player.routation_ang);
    sino = sin(data->player.routation_ang);
    data->player.walk_dir = 1; 
    while(++i <= MOVE_SPEED)
    {
        data->player.movestep = data->player.walk_dir * i;
        x = (data->player.px_pos + P_SIZE / 2) + cosin * data->player.movestep;
        y = (data->player.py_pos + P_SIZE / 2) + sino * data->player.movestep;
        if(!check_move(data, x , y))
            return(0);
    }
    update_walk(data);
    return (0);
}

int move_down(t_data *data)
{
    int x;
    int y;
    double cosin;
    double sino;
    int i;
    
    i = 0;
    cosin = cos(data->player.routation_ang);
    sino = sin(data->player.routation_ang);
    data->player.walk_dir = -1;
    while(++i <= MOVE_SPEED)
    {
        data->player.movestep = data->player.walk_dir * i;
        x = data->player.px_pos + cosin * data->player.movestep;
        y =data->player.py_pos  + sino * data->player.movestep;
        if(!check_move(data, x, y))
            return(0);
    }
    update_walk(data);
    return (0);
}

int move_left(t_data *data)
{
    int x;
    int y;
    double cosin;
    double sino;
    int i;
    
    i = 0;
    cosin = cos(data->player.routation_ang + rad(90));
    sino = sin(data->player.routation_ang + rad(90));
    data->player.walk_dir = -1;
    while (++i <= MOVE_SPEED)
    {
        data->player.movestep = data->player.walk_dir * i;
        x = data->player.px_pos + cosin * data->player.movestep;
        y = data->player.py_pos  + sino  * data->player.movestep;
        if(!check_move(data, x, y))
            return (0);
    }
    update_walk_rl(data);
    return (0);
}

int move_right(t_data *data)
{
    int x;
    int y;
    double cosin;
    double sino;
    int i;
    
    i = 0;
    cosin = cos(data->player.routation_ang + rad(90));
    sino = sin(data->player.routation_ang + rad(90));
    data->player.walk_dir = 1;
    while (++i <= MOVE_SPEED)
    {
        data->player.movestep = data->player.walk_dir * i;
        x = data->player.px_pos + cosin * data->player.movestep;
        y = data->player.py_pos  + sino  * data->player.movestep;
        if(!check_move(data, x, y))
            return (0);
    }
    update_walk_rl(data);
    return (0);
}
