/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashashen <ashashen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:40:58 by ajordan-          #+#    #+#             */
/*   Updated: 2024/06/10 17:31:51 by ashashen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

/**
 * @brief The ft_putstr function traverses the string character by character,
 * using the write function to print each character to standard output.
 * It stops when it encounters a null character (\0)
 * 
 * @param str This is a pointer to the character string to be output.
 */

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
/*%s Print a string*/
/**
 * @brief checks if str points to NULL. If so, it prints "(null)"
 * and returns 6. If str is not NULL, it prints the characters of the
 * string one by one until it encounters a null character, and returns
 * the number of characters printed.
 * 
 * @param str  This is a pointer to the character string to be output.
 */

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

/*%d Prints a decimal number (base 10).*/
/*%i Prints a base 10 integer.*/
/**
 * @brief Converts an integer (n) to a string using ft_itoa.
 * Prints the resulting string to standard output using ft_printstr.
 * Frees the memory allocated for the string.
 * Returns the number of characters printed.
 * 
 * @param n This is the integer to be output.
 * @return int
 */

int	ft_printnbr(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	len = ft_printstr(num);
	free(num);
	return (len);
}
/*%% to print the percentage symbol.*/

int	ft_printpercent(void)
{
	write(1, "%", 1);
	return (1);
}
