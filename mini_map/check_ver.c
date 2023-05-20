/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 10:42:10 by aankote           #+#    #+#             */
/*   Updated: 2023/05/20 18:14:49 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void get_intercepts_ver(t_data *data)
{


    int look_right;
    
    data->cords.xinterc_ver = floor(data->player.px_pos / CARE) * CARE;
    look_right = 0;
    if(cos(data->player.routation_ang >= 0))
        look_right = 1;
    if(look_right)
    {
        data->cords.xinterc_ver += CARE;
        data->cords.yinterc_ver = data->player.py_pos + tan(data->player.routation_ang) * (data->cords.xinterc_ver - data->player.px_pos);
    }
    else
    {
        printf("fuck2\n");
        data->cords.yinterc_ver = data->player.py_pos + fabs(tan(data->player.routation_ang) * (data->cords.xinterc_ver - data->player.px_pos));
    }
    draw_ray(data, data->cords.xinterc_ver,  data->cords.yinterc_ver, GREEN);                                                                                                                          
}

