/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmazier <kmazier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 17:23:05 by kmazier           #+#    #+#             */
/*   Updated: 2020/12/17 17:23:05 by kmazier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_draw_pixel(t_vars *vars, int x, int y, int color)
{
    char    *dst;

    dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void    ft_draw_texture_line(t_vars *vars, t_img img, int x, int start_y, int end_y, int line_height, int tex_x)
{
    double  step;
    double  tex_pos;
    int     tex_y;

    step = 1.0 * img.height / line_height;
    tex_pos = (start_y - vars->cub->height / 2 + line_height / 2) * step;
    while (start_y < end_y)
    {
       tex_y = (int)tex_pos & (img.height - 1);
       tex_pos  += step;
       ft_draw_pixel(vars, x, start_y, img.addr[img.width * tex_y + tex_x]);
       start_y++;
    }
}
