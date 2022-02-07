/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:32:47 by lvan-tic          #+#    #+#             */
/*   Updated: 2022/02/07 14:54:35 by lvan-tic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

static char	*ft_fill(char *str, char const *s, unsigned int start, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && s[i])
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	if (len > i)
		str = malloc(sizeof(char) * (i + 1));
	else
		str = malloc(sizeof(char) * (len + 1));
	if (!(str))
		return (0);
	if (start > i)
	{
		str[0] = '\0';
		return (str);
	}
	return (ft_fill(str, s, start, len));
}
