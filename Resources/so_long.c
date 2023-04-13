/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:46:21 by etlim             #+#    #+#             */
/*   Updated: 2023/04/05 16:47:49 by etlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		if (parsemap(av[1]))
		{
			ft_printf("Valid Map!\n");
			return (0);
		}
		ft_printf("Invalid Map!\n");
		return (0);
	}
	ft_printf("Not enough arguments!\n");
	return (0);
}
