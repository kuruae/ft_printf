/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagnani <emagnani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:12:51 by emagnani          #+#    #+#             */
/*   Updated: 2024/06/20 18:08:13 by emagnani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(int c)
{
	write(1, &c, 1);
	return (1);
}

int	print_d_i(int nb)
{
	return (count);
}

int	print_u(int nb)
{
	return (count);
}

int	print_x_X(int nb, int base)
{
	return (count);
}

int	print_s(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		write(1, &s, 1);
		i++;
		count++;
	}
	return (count);
}

int	print_p(void *ptr)
{

	return (count);
}

int	print_operator(char operator, va_list ap);
{
	count = 0
			if (*format == 'c')
				count += print_c(va_arg(ap, int));
			else if (*format== 's')
				count += print_s(va_arg(ap, char *));
			else if (*format == 'p')
				count += print_p(va_arg(ap, void *));
			else if (*format == ('d' || 'i' )
				count += print_d_i(va_arg(ap, int));
			else if (*format == 'u')
				count += print_u(va_arg(ap, ));
			else if (*format == 'x')
				count += print_x(va_arg(ap, unsigned int), 16);
			else if (*format == '%')
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	char	*str;

	va_start(ap, format);
	count = 0;

	if (!format)
		return -1;
	while (*format)
	{
		if (*format == '%')
			count += print_operator((*(++format), ap)
		else
			count += ft_putchar(*format);
		format++;
	}
	return (count);
}
