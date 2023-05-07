/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:32:52 by aankote           #+#    #+#             */
/*   Updated: 2023/05/06 15:47:00 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

 int move_up(t_data *data)
{
    if(data->py_pos > 3)
    {
        replace_player(data, data->px_pos, data->py_pos);
        data->py_pos -= 3;
        draw_player(data, data->px_pos, data->py_pos); 
    }
    return (0);
}

int move_down(t_data *data)
{
    if(data->py_pos < MAP_Y - 10)
    {
        replace_player(data, data->px_pos, data->py_pos);
        data->py_pos += 3;
        draw_player(data, data->px_pos, data->py_pos);
    }
    
    return (0);
}

int move_left(t_data *data)
{
    if(data->px_pos > 3)
    {
        replace_player(data, data->px_pos, data->py_pos);
        data->px_pos -= 3;
        draw_player(data, data->px_pos, data->py_pos); 
    }
    return (0);
}

int move_right(t_data *data)
{
    if(data->px_pos < MAP_X - 10)
    {
        replace_player(data, data->px_pos, data->py_pos);
        data->px_pos += 3;
        draw_player(data, data->px_pos, data->py_pos);
    }
    return (0);
}