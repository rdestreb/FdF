/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 10:08:51 by rdestreb          #+#    #+#             */
/*   Updated: 2015/01/05 10:22:34 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_params(t_disp *d)
{
	t_param	*par;

	par = get_params();
	par->zoom = 20;
	par->x0 = d->win_size / 2;
	par->y0 = d->win_size / 2;
	par->cst = 1;
	par->cst2 = 1;
	par->proj = 0;
}

t_param	*get_params(void)
{
	static t_param	*par = NULL;

	if (par)
		return (par);
	par = (t_param *)ft_memalloc(sizeof(t_param));
	return (par);
}
