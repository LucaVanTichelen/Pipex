/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:31:10 by lvan-tic          #+#    #+#             */
/*   Updated: 2022/02/07 15:17:52 by lvan-tic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**ft_malloc(char **str, int *tab, int x)
{
	str[tab[1]] = malloc(sizeof(char) * (tab[0] - x + 1));
	if (!(str[tab[1]]))
	{
		while (tab[1] >= 0)
		{
			free(str[tab[1]]);
			tab[1]--;
		}
		return (0);
	}
	return (str);
}

char	**ft_fill_split(char const *s, char c, char **str, int *tab)
{
	int	x;

	while (s[tab[0]])
	{
		while (s[tab[0]] && s[tab[0]] == c)
			tab[0]++;
		x = tab[0];
		if (!(s[tab[0]]))
			break ;
		while (s[tab[0]] != c && s[tab[0]])
			tab[0]++;
		if (!ft_malloc(str, tab, x))
			return (0);
		while (s[x] != c && s[x] != '\0')
			str[tab[1]][tab[2]++] = s[x++];
		str[tab[1]][tab[2]] = '\0';
		tab[2] = 0;
		if (s[tab[0]])
			tab[0]++;
		x++;
		tab[1]++;
	}
	str[tab[1]] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		tab[3];
	int		i;
	int		x;

	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	i = 0;
	x = 1;
	if (!s)
		return (0);
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			x++;
		i++;
	}
	str = malloc(sizeof(char *) * x);
	if (!(str))
		return (0);
	str = ft_fill_split(s, c, str, tab);
	return (str);
}
