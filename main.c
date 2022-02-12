/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:08:28 by lvan-tic          #+#    #+#             */
/*   Updated: 2022/02/11 11:29:22 by lvan-tic         ###   ########.fr       */
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

void	child1(int *fd, char **argv, char **envp, char **paths)
{
	int		i;
	int		infile;
	char	**args;
	char 	*cmd;

	i = 0;
	infile = open(argv[1], O_RDONLY);
	args = ft_split(argv[2], ' ');
	close(fd[0]);
	dup2(infile, 0);
	dup2(fd[1], 1);
	close(infile);
	close(fd[1]);
	while (paths[i])
	{
		cmd = ft_strjoin(paths[i], argv[2]);
		execve(cmd, args, envp);
		i++;
	}
}

void	child2(int *fd, char **argv, char **envp, char **paths)
{
	int		i;
	int		outfile;
	char	**args;
	char	*cmd;

	i = 0;
	outfile = open(argv[4], O_WRONLY, O_CREAT);
	args = ft_split(argv[3], ' ');
	close(fd[1]);
	dup2(fd[0], 0);
	dup2(outfile, 1);
	close(fd[0]);
	close(outfile);
	while (execve(paths[i], args, envp))
	{
		cmd = ft_strjoin(paths[i], argv[3]);
		execve(cmd, args, envp);
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		pid1;
	int		pid2;
	char	**paths;

	if (argc != 5)
		return (0);
	paths = NULL;
	paths = parse_paths(envp);
	pipe(fd);
	pid1 = fork();
	if (pid1 == 0)
	{
		child1(fd, argv, envp, paths);
	}
	else
	{
		waitpid(pid1, NULL, 0);
		pid2 = fork();
		if (pid2 == 0)
			child2(fd, argv, envp, paths);
		else
		{
			close(fd[0]);
			close(fd[1]);
			waitpid(pid2, NULL, 0);
		}
	}
	return (0);
}
