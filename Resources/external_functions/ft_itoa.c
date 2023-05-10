/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 08:49:14 by etlim             #+#    #+#             */
/*   Updated: 2023/05/10 20:00:07 by etlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Converts an integer value to a null-terminated string using the specified 
base and stores the result in the array given by str parameter.
*/

#include "../../so_long.h"

static int	numb_len(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (11);
	if (n == 2147483647)
		return (10);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > 0)
	{
		n = (n / 10);
		i++;
	}
	return (i);
}

static void	ft_handle(int *n, char *s, int *i)
{
	if (*n == 0)
		s[0] = '0';
	if (*n < 0)
	{
		s[0] = '-';
		if (*n == -2147483648)
		{
			s[1] = '2';
			*n = -147483648;
		}
		*n = *n * -1;
		(*i)++;
	}
}

char	*ft_itoa(int n)
{
	int		i;
	int		j;
	int		t;
	char	*s;

	i = 0;
	j = numb_len(n);
	t = numb_len(n);
	s = (char *)malloc(sizeof(char) * (j + 1));
	if (!s)
		return (NULL);
	ft_handle(&n, s, &i);
	j = j - 1;
	while (n > 0)
	{
		s[j--] = 48 + (n % 10);
		n = n / 10;
	}
	s[t] = '\0';
	return (s);
}

// if (n == 0)
// 	s[0] = '0';
// if (n < 0)
// {
// 	s[0] = '-';
// 	if (n == -2147483648)
// 	{
// 		s[1] = '2';
// 		n = -147483648;
// 	}
// 	n = n * -1;
// 	i++;
// }

/* #include <stdio.h>
#include <limits.h>

int	main(void)
{
	printf("%s\n", ft_itoa(293864720));
} */