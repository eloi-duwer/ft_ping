/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <eduwer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 15:49:23 by eduwer            #+#    #+#             */
/*   Updated: 2016/11/09 17:27:18 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static size_t	count_words(char *s, char c)
{
	size_t nb_words;

	nb_words = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != c && *s != '\0')
			nb_words++;
		while (*s != c && *s != '\0')
			s++;
	}
	return (nb_words);
}

static size_t	nb_char(char *s, char c)
{
	size_t i;

	i = 0;
	while (*s != c && *s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

static char		*create_and_fill(char **newtab, int i, char *pt_s, char c)
{
	int j;

	newtab[i] = (char *)malloc(sizeof(char) * (nb_char(pt_s, c) + 1));
	if (newtab[i] == NULL)
		return (NULL);
	newtab[i][nb_char(pt_s, c)] = '\0';
	j = 0;
	while (*pt_s != c && *pt_s != '\0')
	{
		newtab[i][j++] = *pt_s;
		pt_s++;
	}
	return (pt_s);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**newtab;
	char	*pt_s;
	int		i;
	size_t	nb_words;

	if (s == NULL)
		return (NULL);
	pt_s = (char *)s;
	nb_words = count_words(pt_s, c);
	if ((newtab = (char **)malloc(sizeof(char *) * (nb_words + 1))) == NULL)
		return (NULL);
	newtab[nb_words] = NULL;
	i = 0;
	while (i < (int)nb_words)
	{
		while (*pt_s == c && *pt_s != '\0')
			pt_s++;
		if (*pt_s != c && *pt_s != '\0')
		{
			if ((pt_s = create_and_fill(newtab, i, pt_s, c)) == NULL)
				return (NULL);
		}
		i++;
	}
	return (newtab);
}
