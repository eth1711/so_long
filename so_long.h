/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:36:00 by etlim             #+#    #+#             */
/*   Updated: 2023/04/19 18:55:28 by etlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// # include "minilibx_macos/mlx.h"
# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "Resources/external_functions/ft_printf.h"
# include "Resources/external_functions/get_next_line_bonus.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits;
	int		line;
	int		endian;
}			t_data;

typedef struct s_pce
{
	int	p;
	int	c;
	int	e;
}		t_pce;

typedef struct s_pos
{
	int	x;
	int	y;
}		t_pos;

typedef struct s_info
{
	int	coins;
	int	counter;
	int	exit;
}		t_info;

typedef struct s_flood
{
	int	s_x;
	int	s_y;
	int	b_x;
	int	b_y;
}		t_flood;

//external functions
void	*ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);

//parse.c
int		pce_check(char **str);
int		strline(char *str);
int		wall_check(char *str);
int		line_check(char **str, int line_nbr);
int		parsemap(char *map);

char	**str_alloc(char *map, int *line_nbr);

//pathcheck.c

int		pathcheck(char **map, int line_nbr, t_pce pce);
void	locate_start(char **map, t_flood *fl, int line_nbr);
int		checker(char **map, t_flood *fl, t_pos *pos, t_info info);
int		floodfill(char **map, t_flood fl, t_pos pos, t_info *info);

#endif
