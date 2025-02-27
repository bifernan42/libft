/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:49:24 by bifernan          #+#    #+#             */
/*   Updated: 2023/11/09 12:32:24 by bifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_sep(char c, char sep);

static int	ft_wordlen(char const *str, char sep)
{
	int	count;

	count = 0;
	while (*str != '\0' && !ft_is_sep(*str, sep))
	{
		count++;
		str++;
	}
	return (count);
}

static int	ft_is_sep(char c, char sep)
{
	if (c == sep)
		return (1);
	else
		return (0);
}

static int	ft_word_count(char const *str, char sep)
{
	int	is_word;
	int	word_count;

	is_word = 0;
	word_count = 0;
	while (*str != '\0')
	{
		if (!ft_is_sep(*str, sep))
		{
			if (!is_word)
			{
				word_count++;
				is_word = 1;
			}
			str++;
		}
		else
		{
			is_word = 0;
			str++;
		}
	}
	return (word_count);
}

static void	ft_strcpy(char const *src, char *dest, char sep)
{
	while (*src != '\0' && !ft_is_sep(*src, sep))
		*dest++ = *src++;
	*dest = '\0';
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**array;
	int		array_size;

	i = 0;
	array_size = ft_word_count(s, c) + 1;
	array = (char **)malloc(sizeof(char *) * array_size);
	if (!array)
		return (NULL);
	while (i < array_size - 1)
	{
		while (ft_is_sep(*s, c) && *s != '\0')
			s++;
		array[i] = (char *)malloc(sizeof(char) * (ft_wordlen(s, c) + 1));
		if (!array[i])
			return (NULL);
		ft_strcpy(s, array[i], c);
		while (!ft_is_sep(*s, c) && *s != '\0')
			s++;
		i++;
	}
	array[i] = NULL;
	return (array);
}

/*#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	array_size;
	int	i;
	char	**ptr2array;

	array_size = ft_word_count(argv[1], 'b');
	i = 0;
	ptr2array = ft_split(argv[1], 'b');
	while (i < array_size)
	{
		printf("%s\n", ptr2array[i]);
		free(ptr2array[i]);
		i++;
	}
	free(ptr2array);
	return (0);
}*/
