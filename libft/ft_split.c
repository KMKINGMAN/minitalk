/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 01:40:01 by mkurkar           #+#    #+#             */
/*   Updated: 2024/12/24 13:32:51 by mkurkar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*get_word(char const *s, char c, int *start)
{
	int		end;
	int		len;
	char	*word;

	end = *start;
	len = 0;
	while (s[end] && s[end] != c)
	{
		end++;
		len++;
	}
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	end = *start;
	len = 0;
	while (s[end] && s[end] != c)
	{
		word[len] = s[end];
		end++;
		len++;
	}
	word[len] = '\0';
	*start = end;
	return (word);
}

static char	**free_result(char **result, int max_index)
{
	int	i;

	i = 0;
	while (i < max_index)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		word_count;
	char	**result;
	int		i;
	int		start;

	word_count = count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);
	i = 0;
	start = 0;
	while (i < word_count)
	{
		while (s[start] && s[start] == c)
			start++;
		result[i] = get_word(s, c, &start);
		if (!result[i])
			return (free_result(result, i));
		i++;
	}
	result[i] = NULL;
	return (result);
}

// // create a test example for this code
// int main(void)
// {
// 	char const *s = "Hello World";
// 	char c = ' ';
// 	char **result = ft_split(s, c);
// 	int i = 0;
// 	while (result[i])
// 	{
// 		printf("%s\n", result[i]);
// 		i++;
// 	}
// 	free_result(result, i); // Free the memory allocated for the result
// 	return (0);
// }
