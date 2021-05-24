# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saray <saray.jafarzade@gmail.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/02 11:16:14 by saray             #+#    #+#              #
#    Updated: 2021/02/03 07:26:35 by saray            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR	=	libft/

LIBFT		=	libft.a

INC_DIR		=	includes/

SRCS_DIR	=	srcs/

SRCS_FILES	=	ft_align.c \
				ft_elem_manage.c \
				ft_prec.c \
				ft_set.c \
				ft_utils.c \
				ft_printf.c	

SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS		=	$(SRCS:.c=.o)

CC			=	clang

CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -f

NAME		=	libftprintf.a

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INC_DIR)

all:			$(NAME)

$(LIBFT):
				make -C $(LIBFT_DIR)
				cp $(LIBFT_DIR)$(LIBFT) $(NAME)

$(NAME):		$(OBJS) $(LIBFT)
				ar rcs $(NAME) $(OBJS)
clean:
				$(RM) $(OBJS)
				make clean -C $(LIBFT_DIR)

fclean:			clean
				$(RM) $(NAME) $(LIBFT)
				make fclean -C $(LIBFT_DIR)

re:				fclean all

.PHONY:			all clean fclean re
