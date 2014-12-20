/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/20 15:37:36 by rdestreb          #+#    #+#             */
/*   Updated: 2014/12/20 16:33:50 by rdestreb         ###   ########.fr       */
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
	add = c;
	lst = init_lst();
	ft_putendl("coucou");
	while (lst->next)
		lst = lst->next;
	lst->next = add;
	return (lst);
}

void	disp_lst(t_coord *lst)
{
	lst = init_lst();
	while (lst)
	{
		printf("x = %d\ny = %d\nz = %d\n\n", lst->x, lst->y, lst->z);
		lst = lst->next;
	}
}
