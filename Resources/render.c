/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:59:56 by etlim             #+#    #+#             */
/*   Updated: 2023/04/27 17:48:44 by etlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	textures(t_game *game)
{
	int	w;
	int	h;

	w = 64;
	h = 64;
	game->sprites.player = mlx_xpm_file_to_image(game->mlx,
			"Resources/Textures/pacman.xpm", &w, &h);
}
