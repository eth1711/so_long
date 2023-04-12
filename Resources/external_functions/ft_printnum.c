/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:17:39 by etlim             #+#    #+#             */
/*   Updated: 2023/01/19 18:53:27 by etlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
/**
 * @brief this function prints numbers whether it be in decimal, 
 * integer, hexadecimal , or pointer
 * 
 * @param num 
 * input
 * @param hex 
 * formatof the numbers to be printed out
 * @param count 
 * total count
 */

// for pointer and other unsigned just call this resursion
void ft_printnum_unsigned(unsigned long long int num, char *hex, int *count)
{
	int len = ft_strlen(hex);
	if (num > 0)
		ft_printnum(num / len, hex, count);
	ft_printchar(hex[num % len], count);
}


void ft_printnum(long long int num, char *hex, int *count)
{
	int len = ft_strlen(hex);
	// check if number is positive or negative
	if (num < 0)
	{
		ft_printchar('-', count);
		num = num * -1; // chenge to positive
		ft_printnum(num, hex, count); // call printnum
	}
	else
	{
		if (num >= len)
			ft_printnum(num / len, hex, count);
		ft_printchar(hex[num % len], count);
	}
}

// int main()
// {
// 	char *hallo = "0123456789abcdef";
// 	int count = '4327';
// 	ft_printnum_unsigned(-1, hallo, &count);
// }