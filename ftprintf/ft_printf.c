/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:25:36 by aalshafy          #+#    #+#             */
/*   Updated: 2023/11/18 14:45:26 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_conv(int c, va_list ap)
{
	int	count;

	count = 0;
	if (c == '%')
		count = ft_putchar('%');
	else if (c == 'i' || c == 'd')
		count = ft_putnbr(va_arg(ap, int));
	else if (c == 'u')
		count = ft_putunsigned(va_arg(ap, int));
	else if (c == 's')
		count = ft_putstr(va_arg(ap, char *));
	else if (c == 'c')
		count = ft_putchar(va_arg(ap, int));
	else if (c == 'x' || c == 'X')
		count = ft_puthex((va_arg(ap, int)), c);
	else if (c == 'p')
		count = ft_putadd((va_arg(ap, void *)));
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int		count;
	va_list	ap;

	count = 0;
	va_start(ap, s);
	while (*s)
	{
		if (*s == '%')
		{
			count += ft_check_conv(*(s + 1), ap);
			s++;
		}
		else
			count += write(1, s, 1);
		s++;
	}
	va_end(ap);
	return (count);
}
