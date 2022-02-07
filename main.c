/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:08:28 by lvan-tic          #+#    #+#             */
/*   Updated: 2022/02/07 16:09:37 by lvan-tic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

char	**parse_paths(char **envp)
{
	char	**paths;
	char	*str;
	int		i;

	i = 0;
	str = ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i]));
	while (str == NULL)
	{
		i++;
		str = ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i]));
	}
	str = ft_substr(str, 6, ft_strlen(str));
	paths = ft_split(str, ':');
	free(str);
	return (paths);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		pid1;
	int		pid2;
	char	**paths;

	paths = NULL;
	paths = parse_paths(envp);
	pipe(fd);
	pid1 = fork();
	if (pid1 > 0)
		pid2 = fork();
	return (0);
}
