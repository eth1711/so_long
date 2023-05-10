/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:53:50 by etlim             #+#    #+#             */
/*   Updated: 2023/05/10 20:07:16 by etlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char	*ft_strdup(char *s1)
{
	char	*dst;
	int		i;

	i = 0;
	dst = malloc((ft_strlen(&s1[i]) + 1) * (sizeof(char)));
	if (!dst)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
    char *mine;
    char *theirs;
    char *a;
    char *b;
    char *c;
    char *d;
    
    a = "world";
    b = "hello";
    c = "world";
    d = "hello";

    mine = ft_strdup(a);
    theirs = strdup(c);
    printf("Made: %s\n", mine);
    printf("Original: %s\n", theirs);
} */