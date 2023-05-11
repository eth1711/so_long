/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:34:36 by etlim             #+#    #+#             */
/*   Updated: 2023/05/11 23:45:07 by etlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// void	file_to_img(t_game *game, char *str, void **p)
// {
// 	int		x;
// 	int		y;

// 	x = IMG_SIZE;
// 	y = IMG_SIZE;
// 	*p = mlx_xpm_file_to_image(game->mlx, str, &x, &y);
// }

void	put_img(t_game *game, char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.wall, x, y);
	else if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.player,
			x, y);
	else if (c == 'X')
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.enemy,
			x, y);
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.collectible,
			x, y);
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.exit, x, y);
	else if (c == 'O')
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.exit_open,
			x, y);
}

void	animate_coin(t_game *game)
{
	if ((game->move_count % 2) == 0)
		game->sprites.collectible = game->sprites.collectible1;
	else
		game->sprites.collectible = game->sprites.collectible2;
}

void	animate_player(t_game *game)
{
	if ((game->move_count % 2) == 0)
		game->sprites.player = game->sprites.player1;
	else
		game->sprites.player = game->sprites.player2;
}
