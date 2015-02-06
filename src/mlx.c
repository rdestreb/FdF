/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/20 14:41:45 by rdestreb          #+#    #+#             */
/*   Updated: 2015/02/06 19:22:54 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_hud(t_disp *d)
{
	t_param	*par;

	par = get_params();
	mlx_string_put(d->mlx, d->win, d->win_size / 25, d->win_size / 25, 0xFFFFFF,
					"Shift projection = Right mouse button");
	mlx_string_put(d->mlx, d->win, d->win_size / 25, d->win_size / 19, 0xFFFFFF,
					"Move map = Arrows");
	mlx_string_put(d->mlx, d->win, d->win_size / 25, d->win_size / 15, 0xFFFFFF,
					"Zoom/Dezoom = Mouse wheel");
	mlx_string_put(d->mlx, d->win, d->win_size / 25, d->win_size / 12, 0xFFFFFF,
					"Orientation +/- = Home/End");
	if (((par->proj) % 2) == ISO)
	{
		mlx_string_put(d->mlx, d->win, d->win_size / 2.5, d->win_size * 0.95,
						0x00FF00, "Curent projection = ISO");
		mlx_string_put(d->mlx, d->win, d->win_size / 25, d->win_size / 10,
						0xFFFFFF, "Orientation 2 +/- = PgUp/PgDn");
	}
	else
		mlx_string_put(d->mlx, d->win, d->win_size / 2.5, d->win_size * 0.95,
						0xFF0000, "Curent projection = PARA");
}

void	main_draw(char *path)
{
	t_disp	*d;

	d = (t_disp *)ft_memalloc(sizeof(t_disp));
	d->win_size = 1000;
	init_params(d);
	read_map(path);
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, d->win_size, d->win_size, "test window");
	create_image(d);
	projection(d->c);
	draw_map(d);
	mlx_expose_hook(d->win, expose_hook, d);
	mlx_key_hook(d->win, key_hook, d);
	mlx_mouse_hook(d->win, mouse_hook, d);
	mlx_loop(d->mlx);
}
