/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:46:38 by lvan-tic          #+#    #+#             */
/*   Updated: 2022/02/14 16:13:07 by lvan-tic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *str)
{
	write(2, "command not found: ", 19);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
}

void	child1(int *fd, char **argv, char **envp, char **paths)
{
	int		i;
	int		infile;
	char	**args;
	char	*cmd1;
	char	*cmd2;

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
		cmd1 = ft_strjoin(paths[i], "/");
		cmd2 = ft_strjoin(cmd1, args[0]);
		free(cmd1);
		execve(cmd2, args, envp);
		free(cmd2);
		i++;
	}
	ft_error(args[0]);
	free_arr(args);
}

void	child2(int *fd, char **argv, char **envp, char **paths)
{
	int		i;
	int		outfile;
	char	**args;
	char	*cmd1;
	char	*cmd2;

	i = 0;
	outfile = open(argv[4], O_WRONLY);
	args = ft_split(argv[3], ' ');
	close(fd[1]);
	dup2(fd[0], 0);
	dup2(outfile, 1);
	close(fd[0]);
	close(outfile);
	while (paths[i])
	{
		cmd1 = ft_strjoin(paths[i], "/");
		cmd2 = ft_strjoin(cmd1, args[0]);
		free(cmd1);
		execve(cmd2, args, envp);
		free(cmd2);
		i++;
	}
	ft_error(args[0]);
	free_arr(args);
}

void	pipex(char **argv, char **envp, int *fd, char **paths)
{
	int		pid1;
	int		pid2;

	pid1 = fork();
	if (pid1 == 0)
		child1(fd, argv, envp, paths);
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
}
