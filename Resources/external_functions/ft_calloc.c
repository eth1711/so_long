/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:32:08 by etlim             #+#    #+#             */
/*   Updated: 2023/04/05 19:28:01 by etlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../so_long.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*z;

	if (count != 0 && size >= SIZE_MAX / count)
		return (NULL);
	z = malloc(size * (count));
	if (!z)
		return (NULL);
	ft_bzero(z, (size * count));
	return (z);
}
