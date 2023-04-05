/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:36:00 by etlim             #+#    #+#             */
/*   Updated: 2023/04/05 19:23:48 by etlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "Resources/external_functions/ft_printf/ft_printf.h"
# include "Resources/external_functions/getnextline/get_next_line_bonus.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits;
	int		line;
	int		endian;
}			t_data;

typedef struct s_pce
{
	int	p;
	int	c;
	int	e;
}		t_pce;

typedef struct s_pos
{
	int	x;
	int	y;
}		t_pos;

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);

int		parsemap(char *map);
int		pce_check(char **str);

char	**str_alloc(char *map, int *line_nbr);

#endif
