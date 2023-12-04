/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msinke <msinke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:32:54 by msinke            #+#    #+#             */
/*   Updated: 2023/12/04 15:47:38 by msinke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_hexlow(int x)
{
	size_t	value;
	bool	lower;

	lower = false;
	value = (size_t)x;
	return (print_hex(value, lower));
}

size_t	ft_hexup(int X)
{
	size_t	value;
	bool	upper;

	upper = true;
	value = (size_t)X;
	return (print_hex(value, upper));
}

int	ft_printf(const char *str, ...)
{
	size_t	count;
	va_list	args;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			if (*(str + 1) == 'c')
			{
				int c = va_arg(args, int);
				count += ft_char(c);
				str += 2;
			}
			else if (*(str + 1) == 's')
			{
				char *string = va_arg(args, char *);
				count += ft_string(string);
				str += 2;
			}
			else if (*(str + 1) == 'p')
			{
				void* ptr = va_arg(args, void*);
				count += ft_ptr(ptr);
				str += 2;
			}
			else if (*(str + 1) == 'd')
			{
				int dec = va_arg(args, int);
				count += ft_putnbr(dec);
				str += 2;
			}
			else if (*(str + 1) == 'i')
			{
				int i = va_arg(args, int);
				count += ft_putnbr(i);
				str += 2;
			}
			else if (*(str + 1) == 'u')
			{
				int u = va_arg(args, int);
				count += ft_putnbr(u);
				str += 2;
			}
			else if (*(str + 1) == 'x')
			{
				int x = va_arg(args, int);
				count += ft_hexlow(x);
				str += 2;
			}
			else if (*(str + 1) == 'X')
			{
				int X = va_arg(args, int);
				count += ft_hexup(X);
				str += 2;
			}
			else if (*(str + 1) == '%')
			{
				char percent = '%';
				write(1, &percent, 1);
				str += 2;
				count++;
			}
		}
		write(1, str, 1);
		++str;
		++count;
	}
	va_end(args);
	return ((int)count);
}

// int	main(void)
// {
// 	char a = 'a';
//     int i = 42;
//     unsigned int u = 123;
//     char *str = "Hello, World!";
//     void *ptr = (void *)&i;

//     printf("Testing ft_printf:\n");

//     // Basic tests
//     ft_printf("Character: %c\n", a);
//     ft_printf("String: %s\n", str);
//     ft_printf("Pointer: %p\n", ptr);
// 	ft_printf("Character: %c\n", a);
//     ft_printf("String: %s\n", str);
//     ft_printf("Pointer: %p\n", ptr);
// 	ft_printf(" %p ", -1);
// 	ft_printf(" %p ", 16);
// 	ft_printf(" %p ", 17);
// 	ft_printf(" %p %p ", LONG_MIN, LONG_MAX);
// 	ft_printf(" %p %p ", INT_MIN, INT_MAX);
// 	ft_printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
// 	ft_printf(" %p %p ", 0, 0);
//     ft_printf("Integer: %d, %i\n", i, i);
//     ft_printf("Unsigned Integer: %u\n", u);
//     ft_printf("Lowercase Hexadecimal: %x\n", i);
//     ft_printf("Uppercase Hexadecimal: %X\n", i);
//     ft_printf("Double Percent: %%\n");

//     // Test with multiple format specifiers
//     ft_printf("Multiple Format Specifiers: %c %s %p %d %x %%\n", a, str, ptr, i, i);

//     // Test with precision and width
//     ft_printf("Precision and Width: %10.4s\n", str);

//     // Test with zero-padding
//     ft_printf("Zero Padding: %08d\n", i);

//     // Test with negative numbers
//     ft_printf("Negative Number: %d\n", -42);

//     // Test with special characters
//     ft_printf("Special Characters: %c\n", '\n');

//     // Compare with original printf
//     printf("\nTesting original printf for comparison:\n");

//     printf("Character: %c\n", a);
//     printf("String: %s\n", str);
//     printf("Pointer: %p\n", ptr);
//     printf("Integer: %d, %i\n", i, i);
//     printf("Unsigned Integer: %u\n", u);
//     printf("Lowercase Hexadecimal: %x\n", i);
//     printf("Uppercase Hexadecimal: %X\n", i);
//     printf("Double Percent: %%\n");

//     // Test with multiple format specifiers
//     printf("Multiple Format Specifiers: %c %s %p %d %x %%\n", a, str, ptr, i, i);

//     // Test with precision and width
//     printf("Precision and Width: %10.4s\n", str);

//     // Test with zero-padding
//     printf("Zero Padding: %08d\n", i);

//     // Test with negative numbers
//     printf("Negative Number: %d\n", -42);

//     // Test with special characters
//     printf("Special Characters: %c\n", '\n');

//     return 0;
// }