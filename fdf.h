/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 13:38:09 by rdestreb          #+#    #+#             */
/*   Updated: 2014/12/22 16:40:05 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "libft/libft.h"

typedef struct s_coord t_coord;
typedef struct s_disp t_disp;

struct	s_coord
{
	int	x;
	int	y;
	int z;
	int	X;
	int	Y;
	t_coord	*next;
};

struct	s_disp
{
	void	*mlx;
	void	*win;
	int		win_size;
	t_coord	*c;
};

void	read_map(char *path);
t_coord	*get_coord(char *line, t_coord *lst);
void	print_error(char *error);
void	main_draw(void);
int		mouse_hook(int button, int x, int y, t_disp *d);
int		key_hook(int keycode, t_disp *d);
int		expose_hook(t_disp *d);
t_coord	*init_lst(void);
t_coord	*add_link(t_coord *c);
t_coord	*get_next_y(t_coord *c);
void	disp_lst(t_coord *lst);
void	draw_line(t_disp *d, t_coord *p1, t_coord *p2);
void	draw_map(t_disp *d);

#endif
