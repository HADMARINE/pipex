/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:38:40 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/10 11:46:33 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_words_count(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != 0)
	{
		if ((i == 0 && str[i] != c)
			|| (str[i] != c && str[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

void	*cleanmem(char **val, int idx)
{
	while (idx >= 0)
	{
		free(val[idx]);
		idx--;
	}
	free(val);
	return (NULL);
}

char	*get_next_word(char const **str, char c)
{
	int		i;
	int		j;
	char	*ss;
	int		init;

	i = -1;
	init = 0;
	while ((*str)[++i])
	{
		if (((*str)[i] != c && ((*str)[i + 1] == 0 || (*str)[i + 1] == c)))
		{
			ss = (char *)malloc(sizeof(char) * (++i - init + 1));
			if (!ss)
				return ((char *)-1);
			j = -1;
			while (++j < i - init)
				ss[j] = (*str)[j + init];
			ss[j] = 0;
			*str += i;
			return (ss);
		}
		if ((*str)[i] == c)
			init++;
	}
	return (NULL);
}

char	**ft_split(char const *str, char c)
{
	int			words_count;
	char		**val;
	char		*t_ch;
	int			idx;
	char const	*ss;

	if (!str)
		return (NULL);
	ss = str;
	words_count = get_words_count(str, c);
	val = malloc(sizeof(char *) * (words_count + 1));
	if (!val)
		return (NULL);
	idx = 0;
	t_ch = get_next_word(&ss, c);
	while (t_ch != 0 && t_ch != (char *)-1)
	{
		val[idx] = t_ch;
		idx++;
		t_ch = get_next_word(&ss, c);
	}
	if (t_ch == (char *)-1)
		return (cleanmem(val, idx));
	val[idx] = 0;
	return (val);
}
