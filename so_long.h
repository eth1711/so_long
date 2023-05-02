/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:36:00 by etlim             #+#    #+#             */
/*   Updated: 2023/05/02 16:44:58 by etlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// # include "minilibx_macos/mlx.h"
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "Resources/external_functions/ft_printf.h"
# include "Resources/external_functions/get_next_line_bonus.h"

enum
{
	ARROW_UP = 126,
	ARROW_DOWN = 125,
	ARROW_LEFT = 123,
	ARROW_RIGHT = 124,
	KEY_UP = 13,
	KEY_DOWN = 1,
	KEY_LEFT = 0,
	KEY_RIGHT = 2,
	KEY_ESC = 53,
	IMG_SIZE = 64,
};

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	int			move_count;
	int			coin_count;
	t_pos		size;
	t_pos		p_pos;
	t_pos		e_pos;
	t_sprites	sprites;
}				t_game;

typedef struct s_sprites
{
	void	*wall;
	void	*player;
	void	*exit;
	void	*exit_open;
	void	*collectible;
	void	*enemy;
}			t_sprites;
typedef struct s_pce
{
	int	p;
	int	c;
	int	e;
	int	x;
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

//freemap.c
int		freemap(char **str);

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
int		valid_char(char c, t_info *info);

#endif
