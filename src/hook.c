/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 19:13:47 by rdestreb          #+#    #+#             */
/*   Updated: 2015/04/02 15:44:05 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		expose_hook(t_disp *d)
{
	mlx_put_image_to_window(d->mlx, d->win, d->img->ptr, 0, 0);
	print_hud(d);
	return (0);
}

void	key_hook3(int keycode, t_disp *d)
{
	t_param *par;

	par = get_params();
	if (keycode == 119 && par->cst > 0.5)
	{
		par->cst -= 0.1;
		redraw_image(d);
	}
	if (keycode == 115 && par->cst < 1.5)
	{
		par->cst += 0.1;
		redraw_image(d);
	}
	if (keycode == 116 && par->cst2 < 1.5)
	{
		par->cst2 += 0.1;
		redraw_image(d);
	}
	if (keycode == 121 && par->cst2 > 0.5)
	{
		par->cst2 -= 0.1;
		redraw_image(d);
	}
}

void	key_hook2(int keycode, t_disp *d)
{
	t_param *par;

	par = get_params();
	if (keycode == 123)
	{
		par->x0 -= 10;
		redraw_image(d);
	}
	if (keycode == 125)
	{
		par->y0 -= 10;
		redraw_image(d);
	}
	if (keycode == 124)
	{
		par->x0 += 10;
		redraw_image(d);
	}
	if (keycode == 126)
	{
		par->y0 += 10;
		redraw_image(d);
	}
}

int		key_hook(int keycode, t_disp *d)
{
	if (keycode == 53)
	{
		exit(1);
		redraw_image(d);
	}
	key_hook2(keycode, d);
	key_hook3(keycode, d);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_disp *d)
{
	t_param *par;

	par = get_params();
	(void)x;
	(void)y;
	if (button == 2)
	{
		par->proj += 1;
		redraw_image(d);
	}
	if (button == 4 && par->zoom < 100)
	{
		par->zoom += 1;
		redraw_image(d);
	}
	if (button == 5 && par->zoom > 1)
	{
		par->zoom -= 1;
		redraw_image(d);
	}
	return (0);
}
