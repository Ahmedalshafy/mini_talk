/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:20:07 by aalshafy          #+#    #+#             */
/*   Updated: 2023/11/18 11:35:07 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putlonghex(unsigned long long nb, char c)
{
	char	*base;
	int		count;

	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nb < 16)
		return (ft_putchar(base[nb]));
	else
	{
		count = ft_putlonghex((nb / 16), c);
		return (count + ft_putlonghex((nb % 16), c));
	}
}

int	ft_putadd(void *p)
{
	unsigned long long	i;
	int					count;

	i = (unsigned long long) p;
	count = ft_putstr("0x");
	count += ft_putlonghex(i, 'x');
	return (count);
}

// int	main(void)
// {
// 	int	x = -2147483648;
// 	int *s = &x;
//     int y;

//     ft_putadd(s);
// 	printf("\n");
// 	printf("%p\n", s);
// 	// printf("%llu\n", s);
// }

// char	*base;
	// int		count;

	// if (c == 'x')
	// 	base = "0123456789abcdef";
	// else
	// 	base = "0123456789ABCDEF";
	// if (nb < 0)
	// {
	// 	ft_putchar('-');
	// 	return (ft_puthex(-nb, c) + 1);
	// }
	// else if (nb < 16)
	// 	return (ft_putchar(base[nb]));
	// else
	// {
	// 	count = ft_puthex((nb / 16), c);
	// 	return (count + ft_puthex((nb % 16), c));
	// }