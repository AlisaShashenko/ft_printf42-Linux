/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashashen <ashashen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 11:58:09 by ajordan-          #+#    #+#             */
/*   Updated: 2024/06/10 17:33:49 by ashashen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*%c Prints a single character.*/

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}
/**
 * @brief ft_formats function is a versatile function for formatted output in C.
 * It takes a format specifier and a variable argument list, allowing it to print
 * various data types according to the format codes.It relies on helper functions
 * to perform the actual printing and returns the total number of characters
 * printed.
 * 
 * 
 * @param args This is a variable argument list that provides access to
 * the list of arguments passed to the function after the named arguments.
 * @param format This is a character (char) that specifies a format
 * specifier for printing.
 * @return int 
 * 
 * The function uses a series of if statements to check the value
 * of the format character and call appropriate printing functions based
 * on the format specifier:
 * 'c': Prints a character using ft_printchar.
 * 's': Prints a string using ft_printstr.
 * 'p': Prints a pointer address using ft_print_ptr.
 * 'd': Prints a signed integer using ft_printnbr.
 * 'i': Treated the same as 'd'.
 * 'u': Prints an unsigned integer using ft_print_unsigned.
 * 'x': Prints a hexadecimal number in lowercase using ft_print_hex.
 * 'X': Prints a hexadecimal number in uppercase using ft_print_hex.
 * '%': Prints a literal percent sign using ft_printpercent.
 * After processing the format specifier, the function returns the total
 * number of characters printed (print_length).
 * 
 */

int	ft_formats(va_list args, const char format)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length += ft_printchar(va_arg(args, int));
	else if (format == 's')
		print_length += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		print_length += ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		print_length += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		print_length += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		print_length += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		print_length += ft_printpercent();
	return (print_length);
}

/**
 * @brief 
 * 
 * @param const_char*str This is a pointer to a constant format string
 * that can contain regular characters and format specifiers starting with %.
 * 
 * @param ... This is a list of variable arguments. It allows you to
 * pass an arbitrary number of arguments to the function after the format string.
 * @return int 
 */

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		print_length;

	i = 0;
	print_length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_length += ft_formats(args, str[i + 1]);
			i++;
		}
		else
			print_length += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (print_length);
}
