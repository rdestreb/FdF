/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/20 14:41:45 by rdestreb          #+#    #+#             */
/*   Updated: 2014/12/22 11:21:43 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     expose_hook(t_disp *d)
{
	t_coord	*c1;
	t_coord	*c2;

	c1 = init_lst();
	c1 = c1->next;
	while (c1 && c1->next)
	{
		c2 = (t_coord *)ft_memalloc(sizeof(t_coord));
		if (c1->x < c1->next->x)
		{
			c2->X = c1->next->X;
			c2->Y = c1->next->Y;
			draw_line(d, c1, c2);
		}
//		mlx_pixel_put(d->mlx, d->win, c1->X, c1->Y, 0xFF6600);
		c1 = c1->next;
	}
	return (0);
}

int     key_hook(int keycode, t_disp *d)
{
	d = d;
	printf("keycode = %d\n", keycode);
	if (keycode == 65307)
		exit(1);
	return(0);
}

int     mouse_hook(int button, int x, int y, t_disp *d)
{
	int i;

	printf("button = %d(%d, %d)\n", button, x, y);
    i = -1;
    if (button == 1)
		while (++i < 6)
		{
			mlx_pixel_put(d->mlx, d->win, x+i, y, 0xFF0000);
			mlx_pixel_put(d->mlx, d->win, x+2*i, y+2*i, 0xFF0000);
			mlx_pixel_put(d->mlx, d->win, x, y+i, 0xFF0000);
			//          mlx_pixel_put(d->mlx, d->win, x,)
		}
	i = -1;
	if (button == 3)
		//while (++i < 10)
		mlx_pixel_put(d->mlx, d->win, x-i, y, 0x000FF);
	return(0);
}


void	main_draw(void)
{
	t_disp  *d;

	d = (t_disp *)ft_memalloc(sizeof(t_disp));
	d->win_size = 1000;
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, d->win_size, d->win_size, "test window");
	mlx_expose_hook(d->win, expose_hook, d);
	mlx_key_hook(d->win, key_hook, d);
	mlx_mouse_hook(d->win, mouse_hook, d);
//	mlx_loop_hook(d->mlx, key_hook, d);
	mlx_loop(d->mlx);
}
