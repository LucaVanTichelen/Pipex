/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:51:29 by lvan-tic          #+#    #+#             */
/*   Updated: 2022/02/07 14:57:29 by lvan-tic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_fill_s1(char const *s1, int a, char *str)
{
	while (s1[a])
	{
		str[a] = s1[a];
		a++;
	}
	return (a);
}

static void	ft_fill_s2(char const *s2, int a, int b, char *str)
{
	while (s2[b])
	{
		str[a] = s2[b];
		a++;
		b++;
	}
	str[a] = s2[b];
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		a;
	int		b;
	char	*str;

	if (!s1 || !s2)
		return (0);
	a = 0;
	b = 0;
	while (s1[a])
		a++;
	while (s2[b])
		b++;
	str = malloc(sizeof(char) * (a + b + 1));
	if (!(str))
		return (0);
	a = 0;
	b = 0;
	a = ft_fill_s1(s1, a, str);
	ft_fill_s2(s2, a, b, str);
	return (str);
}
