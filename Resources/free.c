/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:54:02 by etlim             #+#    #+#             */
/*   Updated: 2023/05/11 22:34:59 by etlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	freemap(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free (str[i]);
	free (str[i]);
}

int	exit_prog(t_game *game, int i)
{
	if (i == 1)
		ft_printf("You won!\n");
	else
		ft_printf("YOU LOSE!\n");
	freemap(game->map);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}
