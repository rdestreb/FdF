/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/20 14:41:45 by rdestreb          #+#    #+#             */
/*   Updated: 2014/12/22 16:45:42 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     expose_hook(t_disp *d)
{
	draw_map(d);
	return (0);
}

int     key_hook(int keycode, t_disp *d)
{
	d = d;
	printf("keycode = %d\n", keycode);
	if (keycode == 65307)
		exit(1);
	return (0);
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
