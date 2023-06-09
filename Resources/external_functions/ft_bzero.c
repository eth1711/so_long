/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:36:21 by etlim             #+#    #+#             */
/*   Updated: 2023/04/17 15:13:45 by etlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	*ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
	return (s);
}
/* This function made everything in a string become zero */

/* #include <stdio.h>

int	main(void)
{
    char bzero[] = "hellooooooo";

    printf("%s\n", ft_bzero(bzero, 5));
} */