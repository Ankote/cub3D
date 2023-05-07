/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:32:52 by aankote           #+#    #+#             */
/*   Updated: 2023/05/07 18:31:04 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

 int move_up(t_data *data)
{
    if(data->py_pos > 3)
    {
        data->py_pos -= 3;
        initializ(data);
    }
    return (0);
}

int move_down(t_data *data)
{
    if(data->py_pos < MAP_Y - 10)
    {
        data->py_pos += 3;
        initializ(data);
    }
    
    return (0);
}

int move_left(t_data *data)
{
    if(data->px_pos > 3)
    {
        data->px_pos -= 3;
        initializ(data);
    }
    return (0);
}

int move_right(t_data *data)
{
    if(data->px_pos < MAP_X - 10)
    {
        data->px_pos += 3;
        initializ(data);
    }
    return (0);
}