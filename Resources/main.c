/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethanlim <ethanlim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:46:21 by etlim             #+#    #+#             */
/*   Updated: 2023/05/09 00:15:25 by ethanlim         ###   ########.fr       */
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
			loop(av[1]);
			return (0);
		}
		ft_printf("Invalid Map!\n");
		return (0);
	}
	ft_printf("Invalid number of arguments!\n");
	return (0);
}
