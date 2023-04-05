/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:41:48 by etlim             #+#    #+#             */
/*   Updated: 2023/04/04 19:41:23 by etlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**parse_map(char *map, int *line_nbr)
{
	int	fd;
	int	**str;
	int	i;

	fd = open(map, O_RDONLY);
	while (get_next_line(fd))
		*line_nbr += 1;
	close(fd);
}
