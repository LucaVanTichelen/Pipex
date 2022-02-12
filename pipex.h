/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:27:39 by lvan-tic          #+#    #+#             */
/*   Updated: 2022/02/11 11:19:15 by lvan-tic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

char	**ft_malloc(char **str, int *tab, int x);
char	**ft_fill_split(char const *s, char c, char **str, int *tab);
char	**ft_split(char const *s, char c);

int		ft_fill_s1(char const *s1, int a, char *str);
void	ft_fill_s2(char const *s2, int a, int b, char *str);
char	*ft_strjoin(char const *s1, char const *s2);

size_t	ft_strlen(const char *s);

char	*ft_find(char *ihaystack, char *ineedle, size_t len);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

char	*ft_fill(char *str, char const *s, unsigned int start, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);

char	**parse_paths(char **envp);
void	child1(int *fd, char **argv, char **envp, char **paths);
void	child2(int *fd, char **argv, char **envp, char **paths);

#endif