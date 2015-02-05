/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/22 09:27:42 by rdestreb          #+#    #+#             */
/*   Updated: 2015/02/05 20:08:53 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	projection(t_coord *c)
{
	t_param	*par;

	c = init_lst();
	c = c->next;
	par = get_params();
	while (c)
	{
		if (((par->proj) % 2) == ISO)
		{
			c->xp = (par->cst * c->x - par->cst2 * c->z) * par->zoom + par->x0;
			c->yp = ((par->cst / 2) * c->x + (par->cst2 / 2) * c->z - c->y) *
				par->zoom + par->y0;
		}
		else
		{
			c->xp = (c->x - par->cst * c->z) * par->zoom + par->x0;
			c->yp = (par->cst / 2 * c->z - c->y) * par->zoom + par->y0;
		}
		c = c->next;
	}
}

void	draw_line(t_disp *d, t_coord *p1, t_coord *p2)
{
	int	cpt;
	int	p;

	if (abs(p1->xp - p2->xp) >= abs(p1->yp - p2->yp))
	{
		cpt = p1->xp;
		while (abs(cpt - p2->xp))
		{
			p = p1->yp + (cpt - p1->xp) * (p2->yp - p1->yp) / (p2->xp - p1->xp);
			//mlx_pixel_put(d->mlx, d->win, cpt, p, 0xFF6600);
			mlx_pxl_to_image(d->img, cpt, p, 500);
			(cpt < p2->xp ? cpt++ : cpt--);
		}
	}
	else
	{
		cpt = p1->yp;
		while (abs(cpt - p2->yp))
		{
			p = p1->xp + (cpt - p1->yp) * (p2->xp - p1->xp) / (p2->yp - p1->yp);
			//mlx_pixel_put(d->mlx, d->win, p, cpt, 0x0000FF);
			mlx_pxl_to_image(d->img, p, cpt, 500);
			(cpt < p2->yp ? cpt++ : cpt--);
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
			c2->xp = c1->next->xp;
			c2->yp = c1->next->yp;
			draw_line(d, c1, c2);
		}
		if ((c3 = get_next_y(c1)) && (c1->z < c3->z))
			draw_line(d, c1, c3);
		c1 = c1->next;
		free (c2);
	}
}
