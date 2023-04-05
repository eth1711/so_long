/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:41:48 by etlim             #+#    #+#             */
/*   Updated: 2023/04/05 19:23:40 by etlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//checks the number of players, collectibles, and exits  
int	pce_check(char **str)
{
	t_pce	pce;
	t_pos	pos;

	pos.y = 0;
	pce.p = 0;
	pce.c = 0;
	pce.e = 0;
	while (str[pos.y])
	{
		pos.x = 0;
		while (str[pos.y][pos.x] != '\0' && str[pos.y][pos.x] != '\n')
		{
			if (str[pos.y][pos.x] == 'P')
				pce.p += 1;
			else if (str[pos.y][pos.x] == 'C')
				pce.c += 1;
			else if (str[pos.y][pos.x] == 'E')
				pce.e += 1;
		pos.x++;
		}
	pos.y++;
	}
	if ((pce.p != 1) || (pce.c < 1) || (pce.e != 1))
		return (1);
	return (0);
}

// moves the info from .ber file to string
char	**str_alloc(char *map, int *line_nbr)
{
	char	**str;
	int		fd;
	int		i;

	i = -1;
	fd = open(map, O_RDONLY);
	while (get_next_line_bonus(fd))
		*line_nbr += 1;
	close(fd);
	str = ft_calloc(sizeof(char *), (*line_nbr + 1));
	str[*line_nbr] = NULL;
	while (++i < *line_nbr)
		str[i] = get_next_line_bonus(fd);
	close(fd);
	return (str);
}

//parses map and checks if the contents are valid
int	parsemap(char *map)
{
	char	**str;
	int		line_nbr;

	line_nbr = 0;
	str = str_alloc(map, &line_nbr);
	if (pce_check(str))
	{
		return (1);
	}
	return (0);
}
