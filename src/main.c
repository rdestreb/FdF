/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/20 11:53:25 by rdestreb          #+#    #+#             */
/*   Updated: 2015/02/06 18:46:15 by rdestreb         ###   ########.fr       */
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

	c = (t_coord *)ft_memalloc(sizeof(t_coord));
	points = ft_strsplit(line, ' ');
	c->z = zed++;
	i = -1;
	while (points[++i])
	{
		c->x = i;
		c->y = ft_atoi(points[i]);
		lst = add_link(c);
	}
	ft_strdel(&line);
	ft_strdel(points);
	return (lst);
}

void	read_map(char *path)
{
	int		fd;
	int		gnl;
	t_coord	*lst;
	char	*line;

	fd = open(path, O_RDONLY, S_IRUSR);
	if (fd == -1)
		print_error("Open failure");
	while ((gnl = get_next_line (fd, &line)) > 0)
	{
		if (gnl == -1)
			print_error("Read failure");
		lst = get_coord(line, lst);
	}
	close (fd);
}

void	is_valid(char *path)
{
	int		fd;
	int		ret;
	int		i;
	char	buff[BUFF_SIZE + 1];

	fd = open(path, O_RDONLY, S_IRUSR);
	if (fd == -1)
		print_error("Open failure");
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		i = -1;
		buff[ret] = 0;
		while (buff[++i])
		{
			if (!(ft_isdigit(buff[i])) && buff[i] != '-' && buff[i] != ' '
				&& buff[i] != '\n')
			{
				ft_putstr_fd("Error : Map is invalid\n", 2);
				exit(1);
			}
		}
	}
	close(fd);
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		is_valid(av[1]);
		main_draw(av[1]);
	}
	else if (ac == 1)
	{
		ft_putstr_fd("Error : missing argument\n", 2);
		exit(1);
	}
	else
	{
		ft_putstr_fd("Error : Can only read 1 map\n", 2);
		exit(1);
	}
	return (0);
}
