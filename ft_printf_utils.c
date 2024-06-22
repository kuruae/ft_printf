/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagnani <emagnani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:15:55 by emagnani          #+#    #+#             */
/*   Updated: 2024/06/22 18:36:52 by emagnani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int	print_base_digit_lowercase(long nb, int base)
{
	int		count;
	char	*baseset;

	count = 0;
	baseset = "0123456789abcdef";
	if (nb < 0)
	{
		count += print_char('-');
		nb = -nb;
	}
	if (nb >= base)
		count += print_base_digit_lowercase(nb / base, base);
	count += print_char(baseset[nb % base]);
	return (count);
}

int	print_base_digit_uppercase(long nb, int base)
{
	int		count;
	char	*baseset;

	count = 0;
	baseset = "0123456789ABCDEF";
	if (nb < 0)
	{
		count += print_char('-');
		nb = -nb;
	}
	if (nb >= base)
		count += print_base_digit_uppercase(nb / base, base);
	count += print_char(baseset[nb % base]);
	return (count);
}

int	print_string(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (*s)
	{
		print_char((int)*s);
		s++;
		count++;
	}
	return (count);
}

int	print_addr(void *ptr)
{
	int			count;
	uintptr_t	addr;

	count = 0;
	addr = (uintptr_t)ptr;
	if (!addr)
		count += print_string("(nil)");
	else
	{
		count += print_string("0x");
		count += print_base_digit_lowercase(addr, 16);
	}
	return (count);
}
