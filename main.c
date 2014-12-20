/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/20 11:53:25 by rdestreb          #+#    #+#             */
/*   Updated: 2014/12/20 16:32:53 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_error(char *error)
{
	ft_putstr_fd("FdF: ", 2);
	perror(error);
	exit(1);
}

t_coord	*get_coord(char *line, t_coord *lst)
{
	static int	zed = 0;
	char		**points;
	t_coord		*c;
	int			i;

	c  = (t_coord *)ft_memalloc(sizeof(t_coord));
	points = ft_strsplit(line, ' ');
	c->z = zed++;
	i = -1;
	while (points[++i])
	{
		ft_putendl("coucou");
		c->x = i;
		c->y = ft_atoi(points[i]);
//		printf("x = %d\ny = %d\nz = %d\n\n", c->x, c->y, c->z);
		lst = add_link(c);
	}
	ft_strdel(&line);
	ft_strdel(points);
	return(lst);
}

void	read_map(char *path)
{
	int		fd;
	int 	gnl;
	t_coord		*lst;
	char	*line;

	if (!(fd = open(path, O_RDONLY, S_IRUSR)))
		print_error("Open failure");
	while ((gnl = get_next_line (fd, &line)) > 0)
	{
		if (gnl == -1)
			print_error("Read failure");
//		ft_putendl(line);
		lst = get_coord(line, lst);
	}
	disp_lst(lst);
	close (fd);
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		read_map(av[1]);
	}
	else
		print_error("Can only read 1 argument");
	return (0);
}
