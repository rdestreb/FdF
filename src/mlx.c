/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/20 14:41:45 by rdestreb          #+#    #+#             */
/*   Updated: 2015/02/05 20:13:46 by rdestreb         ###   ########.fr       */
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

int		expose_hook(t_disp *d)
{
	mlx_put_image_to_window(d->mlx, d->win, d->img->ptr, 0, 0);
	print_hud(d);
	return (0);
}

int		key_hook(int keycode, t_disp *d)
{
	t_param	*par;

	par = get_params();
	if (keycode)
	{
		if (keycode == 65307)
			exit(1);
		if (keycode == 65361)
			par->x0 -= 10;
		if (keycode == 65362)
			par->y0 -= 10;
		if (keycode == 65363)
			par->x0 += 10;
		if (keycode == 65364)
			par->y0 += 10;
		if (keycode == 65367 && par->cst > 0)
			par->cst -= 0.1;
		if (keycode == 65360 && par->cst < 2)
			par->cst += 0.1;
		if (keycode == 65365 && par->cst2 < 2)
			par->cst2 += 0.1;
		if (keycode == 65366 && par->cst2 > 0)
			par->cst2 -= 0.1;
		//	mlx_clear_window(d->mlx, d->win);
		redraw_image(d);
	}
	return (0);
}

int		mouse_hook(int button, int x, int y, t_disp *d)
{
	t_param	*par;

	par = get_params();
	x = x;
	y = y;
	if (button)
	{
		if (button == 3)
			par->proj += 1;
		if (button == 4 && par->zoom < 100)
			par->zoom += 1;
		if (button == 5 && par->zoom > 1)
			par->zoom -= 1;
		//mlx_clear_window(d->mlx, d->win);
		redraw_image(d);
	}
	return (0);
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
