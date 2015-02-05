/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 13:38:09 by rdestreb          #+#    #+#             */
/*   Updated: 2015/02/05 19:40:38 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
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
# include "../libft/libft.h"

# define ISO 0
# define PARA 1

typedef struct s_coord	t_coord;
typedef struct s_disp	t_disp;
typedef struct s_image	t_image;
typedef struct s_param	t_param;
typedef struct s_color	t_color;

struct	s_coord
{
	int		x;
	int		y;
	int		z;
	int		xp;
	int		yp;
	t_coord	*next;
};

struct	s_param
{
	int		zoom;
	int		x0;
	int		y0;
	double	cst;
	double	cst2;
	int		proj;
	int		abs;
	int		ord;
};

struct	s_color
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
};

struct	s_image
{
	void	*ptr;
	char	*data;
	int		width;
	int		heigth;
	int		bpp;
	int		endian;
	int		size_line;
};

struct	s_disp
{
	void	*mlx;
	void	*win;
	t_image	*img;
	int		win_size;
	t_coord	*c;
};

void	is_valid(char *path);
void	read_map(char *path);
void	print_error(char *error);
void	main_draw(char *path);
int		mouse_hook(int button, int x, int y, t_disp *d);
int		key_hook(int keycode, t_disp *d);
int		expose_hook(t_disp *d);
void	init_params(t_disp *d);
t_param	*get_params(void);
t_coord	*get_coord(char *line, t_coord *lst);
t_coord	*init_lst(void);
t_coord	*add_link(t_coord *c);
t_coord	*get_next_y(t_coord *c);
void	disp_lst(t_coord *lst);
void	projection(t_coord *c);
void	draw_line(t_disp *d, t_coord *p1, t_coord *p2);
void	draw_map(t_disp *d);
int		mlx_pxl_to_image(t_image *img, int x, int y, int color);
int		rgb_to_int(t_color *rgb);
void	redraw_image(t_disp *d);
void	create_image(t_disp *d);

#endif
