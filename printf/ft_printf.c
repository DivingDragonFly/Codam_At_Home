/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:32:54 by msinke            #+#    #+#             */
/*   Updated: 2023/11/20 20:27:44 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_adress(void	*value)
{
	uintptr_t	intptr_value;
	bool		upper;

	upper = 0;
	intptr_value = (uintptr_t)value;
	write(1, "0", 1);
	write(1, "x", 1);
	print_hex(intptr_value, upper);
}

int	ft_printf (const char *str, ...)
{
	va_list	args;

	va_start(args, str);
	while (str)
	{
		if (*str == '%')
		{
			if (*(str + 1) == 'c')
			{
				char c = va_arg(args, char);
				ft_putstr(c);
			}
			else if (*(str + 1) == 's')
			{
				char *string = va_arg(args, char *);
				ft_putstr(string);
			}
			else if (*(str + 1) == 'p')
			{
				void* ptr = va_arg(args, void*);
				print_adress(ptr);
			}
			else if (*(str + 1) == 'd')
			{
				int dec = va_arg(args, int);
				ft_putnbr(dec);
			}
			else if (*(str + 1) == 'i')
			{
				int i = va_arg(args, int);
			}
			else if (*(str + 1) == 'u')
			{
				int u = va_arg(args, int);
			}
			else if (*(str + 1) == 'x')
			{
				int x = va_arg(args, int)
			}
			else if (*(str + 1) == 'X')
			{
			
			}
			else if (*(str + 1) == '%')
			{
				ft_putstr('%');
			}
		}
		++str;
	}
}

int	main(void)
{
	char	a;
	int		x;
	int		X;

	x = 0X3A;
	X = 0x3A;
	a = 'a';
	print_adress(&a);
	printf("\n%p\n", &a);
	printf("%d\n", 10);
	return (0);
}

int	main(void)
{
	ft_printf("%c", 'd');
	write (1,"\n", 1);
	printf("%c", 'd');
	return (0);
}
