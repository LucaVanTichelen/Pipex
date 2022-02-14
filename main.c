/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:08:28 by lvan-tic          #+#    #+#             */
/*   Updated: 2022/02/14 14:37:25 by lvan-tic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

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

int	check_input(int argc, char **argv)
{
	int	fd;

	if (argc != 5)
	{
		write(2, "invalid number of arguments\n", 28);
		return (1);
	}
	if (access(argv[1], R_OK))
	{
		write(2, "permission denied: ", 20);
		write(2, argv[1], ft_strlen(argv[1]));
		write(2, "\n", 1);
		return (2);
	}
	fd = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0644);
	close(fd);
	if (access(argv[4], W_OK))
	{
		write(2, "permission denied: ", 20);
		write(2, argv[4], ft_strlen(argv[4]));
		write(2, "\n", 1);
		return (3);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	char	**paths;

	if (check_input(argc, argv))
		return (1);
	paths = NULL;
	paths = parse_paths(envp);
	pipe(fd);
	pipex(argv, envp, fd, paths);
	free_arr(paths);
	return (0);
}
