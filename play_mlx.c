/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 13:42:05 by rdestreb          #+#    #+#             */
/*   Updated: 2014/12/16 18:43:37 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_disp *d, t_coord *p1, t_coord *p2)
{
	int	o;
	int p;

	if (abs(p1->x - p2->x) >= abs(p1->y - p2->y))
	{
		o = p1->x;
		while (abs(p1->x - p2->x))
		{
			p = p1->y + ((p1->x - o) * (p2->y - p1->y) / (p2->x - o));
			mlx_pixel_put(d->mlx, d->win, p1->x, p, 0xFF6600);
			(p1->x < p2->x ? p1->x++ : p1->x--);
		}
	}
	else
	{
		o = p1->y;
		while (abs(p1->y - p2->y))
		{
			p = p1->x + ((p1->y - o) * (p2->x - p1->x) / (p2->y - o));
			mlx_pixel_put(d->mlx, d->win, p, p1->y, 0x0000FF);
			(p1->y < p2->y ? p1->y++ : p1->y--);
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
	draw_line(d, abs1, abs2);
	draw_line(d, ord1, ord2);
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

void	draw_ellipse(t_disp *d, int x0, int y0, int r1, int r2)
{
	t_coord *c;
	double	alpha;

	alpha = 0;
	c = (t_coord *)ft_memalloc(sizeof(t_coord));
	while (alpha < 2 * M_PI)
	{
		c->x = cos(alpha) * r1 + x0;
		c->y = sin(alpha) * r2 + y0;
		mlx_pixel_put(d->mlx, d->win, c->x, c->y, 0xFF0000);
		alpha += (2 * M_PI) / (8 * r1);
	}
}

void	draw_circle(t_disp *d, int x0, int y0, int r)
{
	t_coord *c;
	double	alpha;

	alpha = 0;
	c = (t_coord *)ft_memalloc(sizeof(t_coord));
	while (alpha < 2 * M_PI)
	{
		c->x = cos(alpha) * r + x0;
		c->y = sin(alpha) * r + y0;
		mlx_pixel_put(d->mlx, d->win, c->x, c->y, 0x00FF00);
		alpha += (2 * M_PI) / (8 * r);
	}
}

void	draw_square(t_disp *d)
{
	t_coord *c;

	c = (t_coord *)ft_memalloc(sizeof(t_coord));
	c->x = d->win_size * 0.25;
	while (c->x <= d->win_size * 0.75)
	{
		c->y = d->win_size * 0.25;
		while (c->y <= d->win_size * 0.75)
		{
			mlx_pixel_put(d->mlx, d->win, c->x, c->y, 0xFF6600);
			c->y++;
		}
		c->x++;
	}
}

void	draw_cube(t_disp *d)
{
	t_coord *c;

	c = (t_coord *)ft_memalloc(sizeof(t_coord));
	c->x = d->win_size * 0.25;
	while (c->x <= d->win_size * 0.75)
	{
		c->y = d->win_size * 0.25;
		while (c->y <= d->win_size * 0.75)
		{
			c->z = -1;
			while (++c->z <= 100)
			{
				if (c->x == d->win_size*0.75 && c->y == d->win_size*0.25)
					mlx_pixel_put(d->mlx, d->win, c->x + c->z, c->y - c->z, 0x000000);
				else if (c->y == d->win_size * 0.25)
					mlx_pixel_put(d->mlx, d->win, c->x + c->z, c->y - c->z, 0x808080);
				else if (c->x == d->win_size * 0.75)
					mlx_pixel_put(d->mlx, d->win, c->x + c->z, c->y - c->z, 0x808080);
				else
					mlx_pixel_put(d->mlx, d->win, c->x + c->z, c->y - c->z, 0xFF6600);
			}
			c->y++;
		}
		c->x++;
	}
}

int		expose_hook(t_disp *d)
{
	draw_rep(d);
//	draw_function(d);
	draw_diag(d);
//	draw_square(d);
//	draw_cube(d);
	draw_circle(d, d->win_size/2, d->win_size/2, d->win_size/2);
	draw_ellipse(d, d->win_size/2, d->win_size/2, 250, 400);
	draw_ellipse(d, d->win_size/2, d->win_size/2, 400, 200);
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
