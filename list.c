/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/20 15:37:36 by rdestreb          #+#    #+#             */
/*   Updated: 2014/12/22 16:44:28 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord	*init_lst(void)
{
	static t_coord *lst = NULL;

	if (!lst)
		lst = (t_coord *)ft_memalloc(sizeof(t_coord));
	return(lst);
}

t_coord	*add_link(t_coord *c)
{
	t_coord *lst;
	t_coord	*add;

	add = (t_coord *)ft_memalloc(sizeof(t_coord));
	add->x = c->x;
	add->y = c->y;
	add->z = c->z;
	add->X = c->X;
	add->Y = c->Y;
	lst = init_lst();
	while (lst->next)
		lst = lst->next;
	lst->next = add;
	return (lst);
}

t_coord *get_next_y(t_coord *c)
{
	t_coord	*lst;

	lst = init_lst();
	lst = lst->next;
	while (lst)
	{
		if ((lst->x == c->x) && (lst->z == (c->z + 1)))
			return (lst);
		lst = lst->next;
	}
	return(NULL);
}

void	disp_lst(t_coord *lst)
{
	lst = init_lst();
	lst = lst->next;
	while (lst)
	{
		printf("x = %d\ny = %d\nz = %d\n\n", lst->x, lst->y, lst->z);
		lst = lst->next;
	}
}
