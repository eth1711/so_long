/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:20:55 by etlim             #+#    #+#             */
/*   Updated: 2023/05/11 23:45:02 by etlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// void	printmap(char **map)
// {
// 	int	i;
// 	int	y = 0;
// 	while (map[y])
// 	{
// 		i = 0;
// 		while(map[y][i])
// 		{
// 			ft_printf("%c]", map[y][i]);
// 			i++;
// 		}
// 		map++;
// 	}
// 	ft_printf("\n");
// }

void	render(t_game *game)
{
	t_pos	pos;
	char	*str;

	animate_coin(game);
	animate_player(game);
	pos.y = 0;
	mlx_clear_window(game->mlx, game->win);
	while (game->map[pos.y])
	{
		pos.x = 0;
		while (game->map[pos.y][pos.x] != '\n' && game->map[pos.y][pos.x])
		{
			put_img(game, game->map[pos.y][pos.x], (64 * pos.x), (64 * pos.y));
			++pos.x;
		}
		pos.y++;
	}
	str = ft_strdup("moves:");
	mlx_string_put(game->mlx, game->win, 0, 0, 0x00FF00, str);
	free(str);
	str = ft_itoa(game->move_count);
	mlx_string_put(game->mlx, game->win, 65, 0, 0x00FF00, str);
	free(str);
}

void	movep_check(t_game *game, int y, int x)
{
	if (game->map[y][x] == '1' || game->map[y][x] == 'E')
		return ;
	if (game->map[y][x] == 'X')
		exit_prog (game, 0);
	if (game->map[y][x] == 'O')
		exit_prog (game, 1);
	else
	{
		if (game->map[y][x] == 'C' && --game->coin_count == 0)
					game->map[game->e_pos.y][game->e_pos.x] = 'O';
		game->map[game->p_pos.y][game->p_pos.x] = '0';
		game->map[y][x] = 'P';
		game->p_pos.x = x;
		game->p_pos.y = y;
		game->move_count++;
	}
	render(game);
}

void	movex_check(t_game *game, int y, int x)
{
	if (game->map[y][x] == '1' || game->map[y][x] == 'E' ||
			game->map[y][x] == 'C')
		return ;
	if (game->map[y][x] == 'P')
		exit_prog(game, 0);
	else
	{
		game->map[game->x_pos.y][game->x_pos.x] = '0';
		game->map[y][x] = 'X';
		game->x_pos.x = x;
		game->x_pos.y = y;
	}
	render(game);
}

int	px_input(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_prog(game, 0);
	else if (keycode == ARROW_UP)
		movep_check(game, game->p_pos.y - 1, game->p_pos.x);
	else if (keycode == ARROW_DOWN)
		movep_check(game, game->p_pos.y + 1, game->p_pos.x);
	else if (keycode == ARROW_LEFT)
		movep_check(game, game->p_pos.y, game->p_pos.x - 1);
	else if (keycode == ARROW_RIGHT)
		movep_check(game, game->p_pos.y, game->p_pos.x + 1);
	else if (keycode == KEY_UP)
		movex_check(game, game->x_pos.y - 1, game->x_pos.x);
	else if (keycode == KEY_DOWN)
		movex_check(game, game->x_pos.y + 1, game->x_pos.x);
	else if (keycode == KEY_LEFT)
		movex_check(game, game->x_pos.y, game->x_pos.x - 1);
	else if (keycode == KEY_RIGHT)
		movex_check(game, game->x_pos.y, game->x_pos.x + 1);
	return (0);
}

void	loop(char *str)
{
	t_game	game;

	init_display(&game, str);
	mlx_key_hook(game.win, px_input, &game);
	mlx_hook(game.win, 17, 0, exit_prog, &game);
	render(&game);
	mlx_loop(game.mlx);
}
