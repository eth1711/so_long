/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:59:56 by etlim             #+#    #+#             */
/*   Updated: 2023/05/11 23:40:39 by etlim            ###   ########.fr       */
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
		x = -1;
		while (game->map[y][++x] && game->map[y][x] != '\n')
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
		}
	}
}

void	x_locate(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x] && game->map[y][x] != '\n')
		{
			if (game->map[y][x] == 'X')
			{
				game->x_pos.x = x;
				game->x_pos.y = y;
			}
		}
	}
}

void	init_images(t_game *game, int x, int y)
{
	game->sprites.player = mlx_xpm_file_to_image(game->mlx,
			"Resources/Textures/pacman1.xpm", &x, &y);
	game->sprites.player1 = mlx_xpm_file_to_image(game->mlx,
			"Resources/Textures/pacman1.xpm", &x, &y);
	game->sprites.player2 = mlx_xpm_file_to_image(game->mlx,
			"Resources/Textures/pacman2.xpm", &x, &y);
	game->sprites.wall = mlx_xpm_file_to_image(game->mlx,
			"Resources/Textures/wall.xpm", &x, &y);
	game->sprites.collectible = mlx_xpm_file_to_image(game->mlx,
			"Resources/Textures/coin1.xpm", &x, &y);
	game->sprites.collectible1 = mlx_xpm_file_to_image(game->mlx,
			"Resources/Textures/coin1.xpm", &x, &y);
	game->sprites.collectible2 = mlx_xpm_file_to_image(game->mlx,
			"Resources/Textures/coin2.xpm", &x, &y);
	game->sprites.enemy = mlx_xpm_file_to_image(game->mlx,
			"Resources/Textures/enemy.xpm", &x, &y);
	game->sprites.exit = mlx_xpm_file_to_image(game->mlx,
			"Resources/Textures/exit.xpm", &x, &y);
	game->sprites.exit_open = mlx_xpm_file_to_image(game->mlx,
			"Resources/Textures/exit_open.xpm", &x, &y);
}

// void	init_images(t_game *game)
// {
// 	file_to_img(game, "Resources/Textures/pacman2.xpm", &game->sprites.player);
// 	file_to_img(game, "Resources/Textures/enemy2.xpm", &game->sprites.enemy);
// 	file_to_img(game, "Resources/Textures/coin2.xpm",
// 		&game->sprites.collectible);
// 	file_to_img(game, "Resources/Textures/wall2.xpm", &game->sprites.exit);
// 	file_to_img(game, "Resources/Textures/exit_open.xpm",
// 		&game->sprites.exit_open);
// 	file_to_img(game, "Resources/Textures/wall2.xpm", &game->sprites.wall);
// }

void	init_display(t_game *game, char	*str)
{
	game->move_count = 0;
	game->size.y = 0;
	game->map = str_alloc(str, &game->size.y);
	game->size.x = strline(game->map[0]);
	pce_locate(game);
	x_locate(game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, IMG_SIZE * game->size.x,
			IMG_SIZE * game->size.y, "My Map");
	init_images(game, 64, 64);
}
