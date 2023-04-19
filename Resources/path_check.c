/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:52:02 by etlim             #+#    #+#             */
/*   Updated: 2023/04/19 18:52:52 by etlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//locates P(player) which will be the starting point of floodfill function
void	locate_start(char **map, t_flood *fl, int line_nbr)
{
	fl->s_x = line_nbr;
	fl->s_y = strline(map[0]);
	fl->b_y = 1;
	while (map[fl->b_y])
	{
		fl->b_x = 0;
		while (map[fl->b_y][fl->b_x] != '\n')
		{
			if (map[fl->b_y][fl->b_x] == 'P')
				return ;
			fl->b_x++;
		}
		fl->b_y++;
	}
}

int	checker(char **map, t_flood *fl, t_pos *pos, t_info info)
{
	fl->b_x = p->x;
	fl->b_y = p->y;
	if (map[fl->b_y][fl->b_x] == 'C')
		info.counter += 1;
	map[fl->b_y][fl->b_x] == 'F';
}

int	floodfill(char **map, t_flood fl, t_pos pos, t_info *info)
{
	checker(map, &fl, &pos, info);
	
}

int	pathcheck(char **map, int line_nbr, t_pce pce)
{
	t_flood	fl;
	t_pos	pos;
	t_info	info;

	info.coins = pce.c;
	info.counter = 0;
	locate_start(map, &fl, line_nbr);
	p.x = fl->b_x;
	p.y = fl->b_y;
	floodfill()
}
