/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suykim <suykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 00:17:30 by suykim            #+#    #+#             */
/*   Updated: 2020/04/17 00:18:03 by suykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_words(int n_word, char **words)
{
	int i;

	i = 0;
	while (i < n_word)
	{
		free(words[i]);
		i++;
	}
	free(words);
}

static int	count_words(const char *str, char sep)
{
	int i;
	int word_count;
	int in_word;

	i = 0;
	word_count = 0;
	in_word = 0;
	while (str[i])
	{
		if (str[i] != sep)
		{
			if (!in_word)
				word_count++;
			in_word = 1;
		}
		else
			in_word = 0;
		i++;
	}
	return (word_count);
}

static int	new_word_pos(const char *str, int n_word, char sep)
{
	int i;
	int word_count;
	int in_word;

	i = 0;
	in_word = 0;
	word_count = 0;
	while (str[i])
	{
		if (str[i] != sep)
		{
			if (!in_word)
			{
				word_count++;
				if (word_count == n_word + 1)
					break ;
			}
			in_word = 1;
		}
		else
			in_word = 0;
		i++;
	}
	return (i);
}

static char	*n_word(const char *str, int n_word, char sep, char **words)
{
	int		i;
	int		j;
	int		k;
	char	*word;

	i = new_word_pos(str, n_word, sep);
	k = i;
	while (str[k] && str[k] != sep)
		k++;
	if (!(word = (char *)malloc((k - i + 1) * sizeof(char))))
	{
		free_words(n_word, words);
		return (0);
	}
	j = 0;
	while (str[i] && str[i] != sep)
	{
		word[j] = str[i];
		i++;
		j++;
	}
	word[j] = 0;
	return (word);
}

char		**ft_split(char const *s, char c)
{
	char	**words;
	int		word_count;
	int		i;

	word_count = count_words(s, c);
	if (!(words = (char **)malloc((word_count + 1) * sizeof(char *))))
		return (0);
	words[word_count] = NULL;
	i = 0;
	while (i < word_count)
	{
		words[i] = n_word(s, i, c, words);
		i++;
	}
	return (words);
}
