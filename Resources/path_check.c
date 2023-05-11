/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:52:02 by etlim             #+#    #+#             */
/*   Updated: 2023/05/12 00:08:49 by etlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//locates P(player) which will be the starting point of floodfill function
void	locate_start(char **map, t_flood *fl, int line_nbr)
{
	fl->s_x = strline(map[0]);
	fl->s_y = line_nbr;
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

//check whether the character in the map is valid
int	valid_char(char c, t_info *info)
{
	if (c == '0' || c == 'C' || c == 'X')
		return (1);
	else if (c == 'E')
		info->exit = 1;
	ft_printf("exit :%i\n", info->exit);
	return (0);
}

//separated part of first part of floodfill
void	checker(char **map, t_flood *fl, t_pos *pos, t_info *info)
{
	fl->b_x = pos->x;
	fl->b_y = pos->y;
	if (map[fl->b_y][fl->b_x] == 'C')
		info->counter += 1;
	map[fl->b_y][fl->b_x] = 'F';
}

//Up, down , left , right
//had to separate function into two because passed 25 lines
//floods the map from player until reaches exit
void	floodfill(char **map, t_flood fl, t_pos pos, t_info *info)
{
	checker(map, &fl, &pos, info);
	if ((fl.b_y > 0) && (valid_char(map[fl.b_y - 1][fl.b_x], info)))
	{
		pos.x = fl.b_x;
		pos.y = fl.b_y - 1;
		floodfill(map, fl, pos, info);
	}
	if (fl.b_y < fl.s_y && valid_char(map[fl.b_y + 1][fl.b_x], info))
	{
		pos.x = fl.b_x;
		pos.y = fl.b_y + 1;
		floodfill(map, fl, pos, info);
	}
	if (fl.b_x < fl.s_x && valid_char(map[fl.b_y][fl.b_x + 1], info))
	{
		pos.x = fl.b_x + 1;
		pos.y = fl.b_y;
		floodfill(map, fl, pos, info);
	}
	if (fl.b_x > 0 && valid_char(map[fl.b_y][fl.b_x - 1], info))
	{
		pos.x = fl.b_x - 1;
		pos.y = fl.b_y;
		floodfill(map, fl, pos, info);
	}
}

//checks the path whether accesible or not
int	pathcheck(char **map, int line_nbr, t_pce pce)
{
	t_flood	fl;
	t_pos	pos;
	t_info	info;

	info.coins = pce.c;
	info.counter = 0;
	locate_start(map, &fl, line_nbr);
	pos.x = fl.b_x;
	pos.y = fl.b_y;
	info.exit = 0;
	floodfill(map, fl, pos, &info);
	if (info.exit == 1 && info.counter == info.coins)
		return (1);
	return (0);
}
