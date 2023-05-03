/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:20:55 by etlim             #+#    #+#             */
/*   Updated: 2023/05/03 19:30:55 by etlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	movep_check(t_game *game, int y, int x)
{
	if (game->map[y][x] == '1' || game->map[y][x] == 'E')
		return ;
	if (game->map[y][x]) == 'O';
		exit_prog(game, 1);
	else
	{
		if (game->map[y][x] == 'C' || --game->coin_count == 0)
					game->map[game->e_pos.y][game->e_pos.x] = O;
		game->map[game->p_pos.y][game->p_pos.x] = 0;
		
	}
		
}

void	movex_check(t_game *game, int y, int x)
{
	if (game->map[y][x] == '1' || game->map[y][x] == 'E' || game->map[y][x] == )
}
int	px_input(int keycode, t_game *game)
{
	if (keycode = KEY_ESC)
		exit_prog(game, 0);
	else if (keycode == ARROW_UP)
		move_check(game, game->p_pos.y - 1, game->p_pos.x)
	else if (keycode == ARROW_DOWN)
		move_check(game, gmae->p_pos.y + 1, game->p_pos.x)
	else if (keycode == ARROW_LEFT)
		move_check(game, game->p_pos.y, game->p_pos.x - 1)
	else if (keycode == ARROW_RIGHT)
		move_check(game, game->p_pos.y, game->p_pos.x + 1)
	else if (keycode == KEY_UP)
		move_check(game, game->x_pos.y - 1, game->x_pos.x);
	else if (keycode == KEY_DOWN)
		move_check(game, game->x_pos.y + 1, game->x_pos.x);
	else if (keycode == KEY_LEFT)
		move_check(game, game->x_pos.y, game->x_pos.x - 1);
	else if (keycode == KEY_RIGHT)
		move_check(game, game->x_pos.y, game->x_pos.x + 1);
	exit_prog(game, 0);
}

void	loop(char *str)
{
}
