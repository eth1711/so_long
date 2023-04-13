/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:13:15 by etlim             #+#    #+#             */
/*   Updated: 2023/04/05 19:17:49 by etlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_printchar(char c, int *count);
void	ft_printstr(char *s, int *count);
void	ft_printnum(long long int num, char *hex, int *count);
void	ft_printnum_unsigned(unsigned long long int num, char *hex, int *count);
void	ft_checkchar(va_list args, const char format, int *total);
int		ft_strlen(char *s);
int		ft_printf(const char *format, ...);

#endif