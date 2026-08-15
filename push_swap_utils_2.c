/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabfajar <jurdiale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 20:26:56 by pabfajar          #+#    #+#             */
/*   Updated: 2026/08/12 17:04:25 by pabfajar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Counts the number of words in s separated by the delimiter c.
** Skips consecutive delimiters. Used by ft_split to know how much to malloc.
*/

static size_t	count_words(char const *s, char c)
{
	size_t	counter;
	size_t	num_words;

	counter = 0;
	num_words = 0;
	while (s[counter])
	{
		while (s[counter] == c)
			counter++;
		if (s[counter])
			num_words++;
		while (s[counter] && s[counter] != c)
			counter++;
	}
	return (num_words);
}

/* Counts the characters of the current word until delimiter c or end of string.
** Used by get_word to know how much to malloc for each word.
*/

static size_t	len_word(char const *s, char c)
{
	size_t	counter;

	counter = 0;
	while (s[counter] && s[counter] != c)
	{
		counter++;
	}
	return (counter);
}

/* Extracts the next word from s starting at index *ind.
** Advances *ind skipping delimiters, copies the word with ft_memcpy.
** Updates *ind to the end of the word. Returns NULL if malloc fails.
*/

static char	*get_word(char const *s, char c, size_t	*ind)
{
	size_t	len;
	char	*act_word;

	while (s[*ind] && s[*ind] == c)
		(*ind)++;
	len = len_word(s + *ind, c);
	act_word = malloc((len + 1) * sizeof(char));
	if (!act_word)
		return (NULL);
	ft_memcpy(act_word, s + *ind, len);
	act_word[len] = '\0';
	*ind += len;
	return (act_word);
}

/* Partially frees a split array in case malloc fails.
** Frees the first "words" strings and then the array itself.
*/

static void	free_split(char **split, size_t words)
{
	size_t	i;

	i = 0;
	while (i < words)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

/* Splits s into an array of strings using c as delimiter.
** Returns the array terminated with NULL. Returns NULL if s is NULL or malloc 
fails.
** Used in validate_numbers and checker main to support input as a single string.
*/

char	**ft_split(char const *s, char c)
{
	char	**list;
	size_t	words;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	words = count_words(s, c);
	list = malloc((words + 1) * sizeof(char *));
	if (!list)
		return (NULL);
	while (s[i] && j < words)
	{
		list[j] = get_word(s, c, &i);
		if (!list[j])
		{
			free_split(list, j);
			return (NULL);
		}
		j++;
	}
	list[words] = NULL;
	return (list);
}
