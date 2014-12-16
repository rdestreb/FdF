/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 13:38:09 by rdestreb          #+#    #+#             */
/*   Updated: 2014/12/16 17:45:24 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
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
};

struct	s_disp
{
	void	*mlx;
	void	*win;
	int		win_size;
};

#endif
