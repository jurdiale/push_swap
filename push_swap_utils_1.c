/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabfajar <jurdiale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:34:53 by jurdiale          #+#    #+#             */
/*   Updated: 2026/08/12 17:07:55 by pabfajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Converts a string to long. Skips leading spaces and accepts a sign.
** Returns a long (not int) to detect overflow before truncation.
*/

long	ft_atol(char *str)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

/* Compares two strings. Returns 0 if they are equal, ASCII difference 
otherwise.
** Used in parse_flags and execute_operation of the checker.
*/

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

/* Fills n bytes of memory with the value c.
** Used to initialize t_count to 0 in init_all.
*/

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
		*ptr++ = (unsigned char)c;
	return (s);
}

/* Copies n bytes from src to dst. Returns dst.
** Used by get_word in ft_split to copy each word.
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				count;
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	count = 0;
	if (dst == (void *)0 && src == (void *)0)
		return (dst);
	while (count < n)
	{
		d[count] = s[count];
		count++;
	}
	return (dst);
}

/* Frees an array of strings created by ft_split.
** Frees each individual string and then the pointer array.
*/

void	free_numbers(char **numbers)
{
	int	j;

	j = 0;
	while (numbers[j] != NULL)
	{
		free(numbers[j]);
		j++;
	}
	free(numbers);
}
