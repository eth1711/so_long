/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethanlim <ethanlim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:36:00 by etlim             #+#    #+#             */
/*   Updated: 2023/05/09 00:36:13 by ethanlim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx_macos/mlx.h"
// # include <mlx.h>
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

typedef struct s_sprites
{
	void	*wall;
	void	*player;
	void	*exit;
	void	*exit_open;
	void	*collectible;
	void	*enemy;
}			t_sprites;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	int			move_count;
	int			coin_count;
	t_pos		size;
	t_pos		p_pos;
	t_pos		x_pos;
	t_pos		e_pos;
	t_sprites	sprites;
}				t_game;

//external functions
void	*ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		strline(char *str);

//free.c
void		freemap(char **str);
int		exit_prog(t_game *game, int i);

//init.c
void	pce_locate(t_game *game);
void	x_locate(t_game *game);
void	init_images(t_game *game);
void	init_display(t_game *game, char	*str);

//loops.c
void	render(t_game *game);
void	movep_check(t_game *game, int y, int x);
void	movex_check(t_game *game, int y, int x);
void	loop(char *str);
int		px_input(int keycode, t_game *game);

//main.c
int	main(int ac, char **av);

//parse.c
int		pce_check(char **str, t_pce	*pce);
int		wall_check(char *str);
int		line_check(char **str, int line_nbr);
int		parsemap(char *map);
char	**str_alloc(char *map, int *line_nbr);

//pathcheck.c

void	locate_start(char **map, t_flood *fl, int line_nbr);
void	checker(char **map, t_flood *fl, t_pos *p, t_info *info);
void	floodfill(char **map, t_flood fl, t_pos pos, t_info *info);
int		pathcheck(char **map, int line_nbr, t_pce pce);
int		valid_char(char c, t_info *info);

//put_img.c
void put_img(t_game *game, char c, int x, int y);

#endif
