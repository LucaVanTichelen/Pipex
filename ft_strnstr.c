/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 16:05:50 by lvan-tic          #+#    #+#             */
/*   Updated: 2022/02/07 14:49:47 by lvan-tic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static char	*ft_find(char *ihaystack, char *ineedle, size_t len)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (ihaystack[i] && i < len)
	{
		while (ihaystack[i] == ineedle[n] && ihaystack[i] && ineedle[n])
		{
			i++;
			n++;
		}
		if (ineedle[n] == '\0' && i <= len)
			return (ihaystack + i - n);
		else if (n != 0)
			i = i - n;
		i++;
		n = 0;
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*ihaystack;
	char	*ineedle;

	ihaystack = (char *) haystack;
	ineedle = (char *) needle;
	if (ineedle[0] == '\0' || ineedle == NULL)
		return (ihaystack);
	return (ft_find(ihaystack, ineedle, len));
}
