/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/22 09:27:42 by rdestreb          #+#    #+#             */
/*   Updated: 2014/12/22 11:05:29 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_disp *d, t_coord *p1, t_coord *p2)
{
    int	o;
    int	p;

	if (abs(p1->X - p2->X) >= abs(p1->Y - p2->Y))
	{
		o = p1->X;
		while (abs(p1->X - p2->X))
		{
			p = p1->Y + ((p1->X - o) * (p2->Y - p1->Y) / (p2->X - o));
			mlx_pixel_put(d->mlx, d->win, p1->X, p, 0xFF6600);
			(p1->X < p2->X ? p1->X++ : p1->X--);
		}
	}
	else
	{
		o = p1->Y;
		while (abs(p1->Y - p2->Y))
		{
			p = p1->X + ((p1->Y - o) * (p2->X - p1->X) / (p2->Y - o));
			mlx_pixel_put(d->mlx, d->win, p, p1->Y, 0x0000FF);
			(p1->Y < p2->Y ? p1->Y++ : p1->Y--);
		}
	}
}

