/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:13:03 by etlim             #+#    #+#             */
/*   Updated: 2023/04/05 19:20:17 by etlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// #include "stdio.h"

void	ft_checkchar(va_list args, const char format, int *total)
{
	if (format == 'c')
		ft_printchar(va_arg(args, int), total);
	else if (format == 's')
		ft_printstr(va_arg(args, char *), total);
	else if (format == 'i' || format == 'd')
		ft_printnum((long long int)va_arg(args, int), "0123456789", total);
	else if (format == 'u')
		ft_printnum((long int)va_arg(args, unsigned int), "0123456789", total);
	else if (format == 'x')
		ft_printnum((long long int)va_arg(args, unsigned long int),
			"0123456789abcdef", total);
	else if (format == 'p')
	{
		ft_printchar('0', total);
		ft_printchar('x', total);
		ft_printnum_unsigned((long int)va_arg(args, unsigned long int),
			"0123456789abcdef", total);
	}
	else if (format == 'X')
		ft_printnum((long int)va_arg(args, unsigned long int),
			"0123456789ABCDEF", total);
	else if (format == '%')
		ft_printchar('%', total);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total;
	int		i;

	total = 0;
	i = -1;
	va_start(args, format);
	while (format[++i] != '\0')
	{
		if (format[i] == '%')
		{
			ft_checkchar (args, format[i + 1], &total);
			i++;
		}
		else
			ft_printchar(format[i], &total);
	}
	va_end(args);
	return (total);
}
// int main(void)
// {
// 	int mine;
// 	int original;
// 	char *str = "banana";
// 	original = printf("start %d %% end\n", 2147483647);
// 	mine = ft_printf("start %d %% end\n", 2147483647);
// 	printf("my count: %i, original count: %i\n", mine, original);
// }