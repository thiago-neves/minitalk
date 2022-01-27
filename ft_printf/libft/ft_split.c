/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tneves <tneves@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 20:40:40 by tneves            #+#    #+#             */
/*   Updated: 2021/02/09 20:40:41 by tneves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words_number(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] && str[i] == c)
		i++;
	if (str[i])
	{
		i++;
		count++;
	}
	while (str[i] != 0)
	{
		if (str[i] != c && str[i - 1] == c)
		{
			count++;
			while (str[i] == c)
				i++;
		}
		i++;
	}
	return (count);
}

static int	word_size(char const *str, char c)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i] && str[i] != c)
	{
		i++;
		size++;
	}
	return (size);
}

static int	put_and_null_next(char **arr, int i, int j, char c)
{
	arr[i][j] = c;
	arr[i][j + 1] = 0;
	return (j + 1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;
	int		index;

	arr = (char **)malloc(sizeof(char *) * (words_number(s, c) + 1));
	i = -1;
	index = -1;
	while (s[++index])
	{
		if (s[index] != c)
		{
			if (i == -1 || s[index - 1] == c)
			{
				arr[++i] = (char *)malloc(sizeof(char)
						* (word_size(s + index, c) + 1));
				if (!arr)
					return (0);
				j = 0;
			}
			j = put_and_null_next(arr, i, j, s[index]);
		}
	}
	arr[++i] = 0;
	return (arr);
}
