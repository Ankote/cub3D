/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_hor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <aankote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:31:04 by aankote           #+#    #+#             */
/*   Updated: 2023/05/25 11:53:45 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../cub3d.h"
 
int check_hit_hor(char **map, int x_cor, int y_cor)
{
    int x;
    int y;

    x = x_cor / CARE;
    y = y_cor / CARE;
    if(map[y][x] == '1' || map[y - 1][x] == '1')
        return (0);
    return (1);
}

int get_intercepts(t_data *data)
{
    int check_down;
    
    check_down = 0;
    if(sin(data->player.ray_angle) >= 0)
        check_down = 1;
    data->cords.yinterc_hor = floor((data->player.py_pos) / CARE) * CARE;
    if(check_down)
        data->cords.yinterc_hor += CARE ;
    data->cords.xinterc_hor = data->player.px_pos + (data->cords.yinterc_hor 
        - data->player.py_pos) / tan(data->player.ray_angle);
    if(data->cords.xinterc_hor >= data->win.map_x)
        data->cords.xinterc_hor = data->win.map_x - CARE;
    if(data->cords.xinterc_hor <= 0)
        data->cords.xinterc_hor = 0;
    if(!check_hit_hor(data->map, data->cords.xinterc_hor, data->cords.yinterc_hor))
    {
        data->cords.xb_hor = data->cords.xinterc_hor;
        data->cords.yb_hor = data->cords.yinterc_hor;
        return (1);
    }
    return(0);
}

int get_second_hor_cord(t_data *data)
{
    int check_down;
    int check_left;

    if(get_intercepts(data))
        return (1);
    check_down = 0;
    if(sin(data->player.ray_angle) <= 0)
        check_down = 1;
    data->cords.yb_hor = data->cords.yinterc_hor - CARE;
    if(!check_down)
        data->cords.yb_hor = data->cords.yinterc_hor + CARE;
    check_left = 0; 
    if(cos(data->player.ray_angle) <= 0)
        check_left = 1;
    if(!check_left)
        data->cords.xb_hor = data->cords.xinterc_hor + fabs(CARE / tan(data->player.ray_angle));
    else
        data->cords.xb_hor = data->cords.xinterc_hor - fabs(CARE / tan(data->player.ray_angle)) ;
    if(data->cords.xb_hor >= data->win.map_x)
        data->cords.xb_hor = data->win.map_x - CARE;
    if(data->cords.xb_hor <= 0)
        data->cords.xb_hor = CARE;
    if(!check_hit_hor(data->map, data->cords.xb_hor, data->cords.yb_hor))
        return (1);
    return(0);
}

int   hit_hor_wall(t_data *data)
 {   
    int y_step;

    if(get_second_hor_cord(data))
        return(1);
    data->cords.xsteps_hor =  (data->cords.xb_hor - data->cords.xinterc_hor);
    y_step = CARE;
    if(sin(data->player.ray_angle > 0))
         y_step =  -CARE ;
    while(1)
    {
        if(data->cords.xb_hor >= data->win.map_x)
            data->cords.xb_hor = data->win.map_x  - CARE;
        if(data->cords.xb_hor <= 0)
            data->cords.xb_hor = CARE;
        if(!check_hit_hor(data->map, data->cords.xb_hor, data->cords.yb_hor))
            return (1);
        data->cords.xb_hor += data->cords.xsteps_hor;
        data->cords.yb_hor += y_step;  
    }
    return (0);
 }

 void draw_rays(t_data *data)
 {
    // int x;

    // x = 0;
    // double rr = 0.0001;
    
	data->player.ray_angle = data->player.routation_ang - rad(30);
    printf("p_ang = %f   ray_ang = %f\n", (data->player.routation_ang), (data->player.ray_angle));
    if(data->player.routation_ang  == (double)4.712389)
    {
        printf("whattttt\n");
        // while(2);
        data->player.ray_angle = rad(330);
    }
    else
        printf("noooo\n");
    // while(x < WIN_X)
    // {
        hit_hor_wall(data);
        // get_second_hor_cord(data);
    draw_ray(data, data->cords.xb_hor , data->cords.yb_hor, GREEN);
    //     printf("%f\n",  deg(data->player.ray_angle));
       
    //     data->player.ray_angle += rad(60)/ WIN_X;
    //     if (data->player.ray_angle >= rad(360))
    //         data->player.ray_angle = rad(0);
    //     x ++;
    // }
 }