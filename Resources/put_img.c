/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:34:36 by etlim             #+#    #+#             */
/*   Updated: 2023/05/09 17:37:33 by etlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_img(t_game *game, char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.wall, x, y);
	if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.player,
			x, y);
	if (c == 'X')
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.enemy,
			x, y);
	if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.collectible,
			x, y);
	if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.exit, x, y);
	if (c == 'O')
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.exit_open,
			x, y);
}
