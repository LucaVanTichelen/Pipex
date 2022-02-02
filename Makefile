# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/30 09:24:38 by lvan-tic          #+#    #+#              #
#    Updated: 2022/01/30 09:25:29 by lvan-tic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	pipex

SRCS	=	ft_printf.c		\
			ft_putstr.c		\
			ft_numbers.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	@ar -rc $(NAME) $(OBJS)

clean	:	
	@$(RM) $(OBJS)

fclean	:	clean
	@$(RM) $(NAME)

re		:	fclean all