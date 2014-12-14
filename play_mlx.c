/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 13:42:05 by rdestreb          #+#    #+#             */
/*   Updated: 2014/12/14 17:53:54 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_disp *d, t_coord *p1, t_coord *p2)
{
	while (fabs(p1->x - p2->x) || fabs(p1->y - p2->y))
	{
		mlx_pixel_put(d->mlx, d->win, p1->x, p1->y, 0xFF6600);
		if (p1->x < p2->x)
			p1->x++;
		else if (p1->x > p2->x)
			p1->x--;
		if (p1->y < p2->y)
			p1->y++;
		else if (p1->y > p2->y)
			p1->y--;
	}
}

void	draw_rep(t_disp *d, int win_size)
{
	t_coord	*abs1;
	t_coord	*abs2;
	t_coord	*ord1;
	t_coord	*ord2;

	abs1 = (t_coord *)ft_memalloc(sizeof(t_coord));
	abs2 = (t_coord *)ft_memalloc(sizeof(t_coord));
	ord1 = (t_coord *)ft_memalloc(sizeof(t_coord));
	ord2 = (t_coord *)ft_memalloc(sizeof(t_coord));
	abs1->x = 0;
	abs1->y = win_size/2;
	abs2->x = win_size;
	abs2->y = win_size/2;
	ord1->x = win_size/2;
	ord1->y = 0;
	ord2->x = win_size/2;
	ord2->y = win_size;
	draw_line(d, abs2, abs1);
	draw_line(d, ord2, ord1);
}

void	draw_diag(t_disp *d, int win_size)
{
	t_coord	*p1;
	t_coord	*p2;
	t_coord	*p3;
	t_coord	*p4;

	p1 = (t_coord *)ft_memalloc(sizeof(t_coord));
	p2 = (t_coord *)ft_memalloc(sizeof(t_coord));
	p3 = (t_coord *)ft_memalloc(sizeof(t_coord));
	p4 = (t_coord *)ft_memalloc(sizeof(t_coord));
	p1->x = 0;
	p1->y = 0;
	p2->x = win_size;
	p2->y = win_size;
	p3->x = 0;
	p3->y = win_size;
	p4->x = win_size;
	p4->y = 0;
	draw_line(d, p2, p1);
	draw_line(d, p4, p3);
}

int	main(void)
{
	int		win_size;
	t_coord *c;
	t_disp	*d;

	win_size = 1000;
	d = (t_disp *)ft_memalloc(sizeof(t_disp));
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, win_size, win_size, "test window");
	c = (t_coord *)ft_memalloc(sizeof(t_coord));
	c->x = 0 + (win_size/2);
	c->y = 0;
//	while (c->x < win_size)
//	{
//		while (c->y < 750)
//		{
//		c->y = win_size - log(c->x);
//		mlx_pixel_put(d->mlx, d->win, c->x, c->y, 0xFF6600);
//			c->y++;
//		}
//		c->x++;
//	}
	draw_rep(d, win_size);
	draw_diag(d, win_size);
	sleep(7);
	return(0);
}
