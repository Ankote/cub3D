/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 10:42:10 by aankote           #+#    #+#             */
/*   Updated: 2023/05/20 15:27:36 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void get_intercepts_ver(t_data *data)
{


    int check_left;
    
    data->cords.xinterc_ver = floor(data->player.px_pos / CARE) * CARE;
    check_left = 0;
    if(cos(data->player.routation_ang <= 0))
        check_left = 1;
    if(!check_left)
    {
        data->cords.xinterc_ver += CARE;
        data->cords.yinterc_ver = data->player.py_pos - tan(data->player.routation_ang) * (data->cords.xinterc_ver - data->player.px_pos);
    }
    else
        data->cords.yinterc_ver = data->player.py_pos + tan(data->player.routation_ang) * (data->player.px_pos - data->cords.xinterc_ver);
    draw_ray(data, data->cords.xinterc_ver,  data->cords.yinterc_ver, GREEN);                                                                                                                          
}
