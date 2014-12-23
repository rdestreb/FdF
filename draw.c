/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/22 09:27:42 by rdestreb          #+#    #+#             */
/*   Updated: 2014/12/23 11:57:17 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
void	draw_color(t_disp *d, int x, int y)
{
	t_colors	*col;

	col = (t_colors *)ft_memalloc(sizeof(t_colors));

	mlx_pixel_put(d->mlx, d->win, cpt, p, 0xcol->r);

}
*/
void	draw_line(t_disp *d, t_coord *p1, t_coord *p2)
{
    int	cpt;
    int	p;

	if (abs(p1->X - p2->X) >= abs(p1->Y - p2->Y))
	{
		cpt = p1->X;
		while (abs(cpt - p2->X))
		{
			p = p1->Y + ((cpt - p1->X) * (p2->Y - p1->Y) / (p2->X - p1->X));
			mlx_pixel_put(d->mlx, d->win, cpt, p, 0xFF6600);
			(cpt < p2->X ? cpt++ : cpt--);
		}
	}
	else
	{
		cpt = p1->Y;
		while (abs(cpt - p2->Y))
		{
			p = p1->X + ((cpt - p1->Y) * (p2->X - p1->X) / (p2->Y - p1->Y));
			mlx_pixel_put(d->mlx, d->win, p, cpt, 0x0000FF);
			(cpt < p2->Y ? cpt++ : cpt--);
		}
	}
}

void	draw_map(t_disp *d)
{
	t_coord *c1;
	t_coord *c2;
	t_coord *c3;

	c1 = init_lst();
	c1 = c1->next;
    while (c1 && c1->next)
	{
		c2 = (t_coord *)ft_memalloc(sizeof(t_coord));
		c3 = (t_coord *)ft_memalloc(sizeof(t_coord));
		if (c1->x < c1->next->x)
		{
			c2->X = c1->next->X;
			c2->Y = c1->next->Y;
			draw_line(d, c1, c2);
		}
		if ((c3 = get_next_y(c1)) && (c1->z < c3->z))
		{
			draw_line(d, c1, c3);
			//free (c3);
		}
//		mlx_pixel_put(d->mlx, d->win, c1->X, c1->Y, 0xFF6600);
		c1 = c1->next;
		free (c2);
	}
}
