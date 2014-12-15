/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 13:42:05 by rdestreb          #+#    #+#             */
/*   Updated: 2014/12/15 20:45:26 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_disp *d, t_coord *p1, t_coord *p2)
{
	int	ori;

	if (p2->x >= p2->y)
	{
		ori = p1->x;
		while (abs(p1->x - p2->x))
		{
			mlx_pixel_put(d->mlx, d->win, p1->x, p1->y + ((p1->x - ori) * (p2->y - p1->y)/(p2->x - ori)), 0xFF6600);
			if (p1->x < p2->x)
				p1->x++;
			else if (p1->x > p2->x)
				p1->x--;
		}
	}
	else
	{
		ori = p1->y;
		while (abs(p1->y - p2->y))
		{
			mlx_pixel_put(d->mlx, d->win, p1->x + ((p1->y - ori) * (p2->x - p1->x)/(p2->y - ori)), p1->y, 0x0000FF);
			if (p1->y < p2->y)
				p1->y++;
			else if (p1->y > p2->y)
				p1->y--;
		}
	}
}

void	draw_rep(t_disp *d)
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
	abs1->y = d->win_size/2;
	abs2->x = d->win_size;
	abs2->y = d->win_size/2;
	ord1->x = d->win_size/2;
	ord1->y = 0;
	ord2->x = d->win_size/2;
	ord2->y = d->win_size;
	draw_line(d, abs2, abs1);
	draw_line(d, ord2, ord1);
}

void	draw_diag(t_disp *d)
{
	t_coord	*p1;
	t_coord	*p2;
	t_coord	*p3;
	t_coord	*p4;
	t_coord	*p5;
	t_coord	*p6;
	t_coord	*p7;
	t_coord	*p8;

	p1 = (t_coord *)ft_memalloc(sizeof(t_coord));
	p2 = (t_coord *)ft_memalloc(sizeof(t_coord));
	p3 = (t_coord *)ft_memalloc(sizeof(t_coord));
	p4 = (t_coord *)ft_memalloc(sizeof(t_coord));
	p5 = (t_coord *)ft_memalloc(sizeof(t_coord));
	p6 = (t_coord *)ft_memalloc(sizeof(t_coord));
	p7 = (t_coord *)ft_memalloc(sizeof(t_coord));
	p8 = (t_coord *)ft_memalloc(sizeof(t_coord));
	p1->x = 250;
	p1->y = 100;
	p2->x = 750;
	p2->y = 900;
	p3->x = 750;
	p3->y = 100;
	p4->x = 250;
	p4->y = 900;
	p5->x = 100;
	p5->y = 250;
	p6->x = 900;
	p6->y = 750;
	p7->x = 100;
	p7->y = 750;
	p8->x = 900;
	p8->y = 250;
	draw_line(d, p1, p2);
	draw_line(d, p3, p4);
	draw_line(d, p5, p6);
	draw_line(d, p7, p8);
}

void draw_function(t_disp *d)
{
	t_coord	*c;

	c = (t_coord *)ft_memalloc(sizeof(t_coord));
	while (c->x < d->win_size)
	{
		c->y = log(c->x) * 10;
		mlx_pixel_put(d->mlx, d->win, c->x + d->win_size/2, d->win_size/2 - c->y, 0x0000FF);
		c->x++;
	}
}
/*
void	draw_circle(t_disp *d, int win_size)
{
	t_coord *c;
	double	alpha;
	double	pi;

	alpha = 0;
	pi = 3.1416
	c = (t_coord *)ft_memalloc(sizeof(t_coord));
	while (alpha < 2)

}
*/
void	draw_square(t_disp *d)
{
	t_coord *c;

	c = (t_coord *)ft_memalloc(sizeof(t_coord));
	c->x = d->win_size * 0.25;
	printf("win size = %d\n", d->win_size);
	while (c->x < d->win_size * 0.75)
	{
		c->y = d->win_size * 0.25;
		while (c->y < d->win_size * 0.75)
		{
			mlx_pixel_put(d->mlx, d->win, c->x, c->y, 0xFF6600);
			c->y++;
		}
		c->x++;
	}
}

int		expose_hook(t_disp *d)
{
//	draw_rep(d);
//	draw_function(d);
	draw_diag(d);
//	draw_square(d);
	return (0);
}

int		key_hook(int keycode, t_disp *d)
{
	d = d;
	printf("keycode = %d\n", keycode);
	if (keycode == 65307)
		exit(0);
	return(0);
}

int		mouse_hook(int button, int x, int y, t_disp *d)
{
	int	i;

	printf("button = %d(%d, %d)\n", button, x, y);
	i = -1;
	if (button == 1)
		while (++i < 6)
		{
			mlx_pixel_put(d->mlx, d->win, x+i, y, 0xFF0000);
			mlx_pixel_put(d->mlx, d->win, x+2*i, y+2*i, 0xFF0000);
			mlx_pixel_put(d->mlx, d->win, x, y+i, 0xFF0000);
//			mlx_pixel_put(d->mlx, d->win, x, y, 0xFF0000);
		}
	i = -1;
	if (button == 3)
		while (++i < 10)
			mlx_pixel_put(d->mlx, d->win, x-i, y, 0x000FF);
	return(0);
}

int		main(void)
{
	t_disp	*d;

	d = (t_disp *)ft_memalloc(sizeof(t_disp));
	d->win_size = 1000;
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, d->win_size, d->win_size, "test window");
	mlx_expose_hook(d->win, expose_hook, d);
	mlx_key_hook(d->win, key_hook, d);
	mlx_mouse_hook(d->win, mouse_hook, d);
	mlx_loop(d->mlx);
	return(0);
}
