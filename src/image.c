/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 15:49:11 by rdestreb          #+#    #+#             */
/*   Updated: 2015/02/06 18:50:50 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		mlx_pxl_to_image(t_image *img, int x, int y, int color)
{
	int	octets;

	octets = img->bpp / 8;
	if (x > 0 && x < img->width && y > 0 && y < img->heigth)
		ft_memcpy(&img->data[octets * (x + img->size_line / octets * y)]
					, &color, octets);
	return (0);
}

void	redraw_image(t_disp *d)
{
	mlx_destroy_image(d->mlx, d->img->ptr);
	ft_memdel((void *)&d->img);
	create_image(d);
	projection(d->c);
	draw_map(d);
	expose_hook(d);
}

void	create_image(t_disp *d)
{
	d->img = (t_image *)ft_memalloc(sizeof(t_image));
	d->img->width = d->win_size;
	d->img->heigth = d->win_size;
	d->img->ptr = mlx_new_image(d->mlx, d->img->width, d->img->heigth);
	d->img->data = mlx_get_data_addr(d->img->ptr, &d->img->bpp,
									&d->img->size_line, &d->img->endian);
}
