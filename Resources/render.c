/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethanlim <ethanlim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:59:56 by etlim             #+#    #+#             */
/*   Updated: 2023/04/30 13:28:05 by ethanlim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	pce_locate(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	game->coin_count = 0;
	while (game->map[++y])
	{
		x = 0;
		while (game->map[y][x] && game->map[y][x] != '\n')
		{
			if (game->map[y][x] == 'P')
			{
				game->p_pos.x = x;
				game->p_pos.y = y;
			}
			if (game->map[y][x] == 'C')
				game->coin_count++;
			if (game->map[y][x] == 'E')
			{
				game->e_pos.x = x;
				game->e_pos.y = y;
			}
			x++;
		}
	}
}

void	init_images(t_game *game)
{
	int	w;
	int	h;

	w = 64;
	h = 64;
	game->sprites.player = mlx_xpm_file_to_image(game->mlx,
			"Resources/Textures/pacman.xpm", &w, &h);
	game->sprites.wall = mlx_xpm_file_to_image(game->mlx,
			"Resources/Textures/wall.xpm", &w, &h);
	game->sprites.collectible = mlx_xpm_file_to_image(game->mlx,
			"Resources/Textures/coin.xpm", &w, &h);
	game->sprites.exit = mlx_xpm_file_to_image(game->mlx,
			"Resources/Textures/exit.xpm", &w, &h);
	game->sprites.enemy = mlx_xpm_file_to_image(game->mlx,
			"Resources/Textures/enemy.xpm", &w, &h);
}

void	init_display(t_game *game, char	*str)
{
	game->move_count = 0;
	game->size.y = 0;
	game->map = str_alloc(str, &game->size.y);
	game->size.x = strline(game->map[0]);
	pce_locate(game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, IMG_SIZE * game->size.x,
			IMG_SIZE * game->size.y, "My Map");
	init_images(game);
	
}