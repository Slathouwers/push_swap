# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/06 14:26:03 by slathouw          #+#    #+#              #
#    Updated: 2021/10/15 11:08:31 by slathouw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= push_swap
LIBFT 	= libftprintf
INCLUDES= includes
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
OBJDIR	= obj


SOURCES	= push_swap.c print.c
SRCDIR 	= srcs
SRCS 	= ${addprefix $(SRCDIR)/, $(SOURCES)}
OBJS	= ${addprefix $(OBJDIR)/, $(SOURCES:.c=.o)}


all : 		${NAME}

$(NAME) :	$(OBJS)
	@make -C $(LIBFT)
	@cp libftprintf/libftprintf.a .
	@${CC} ${CFLAGS} -I ${INCLUDES} ${OBJS} libftprintf.a -o ${NAME}
	@echo "push_swap binary created!"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p obj
	@${CC} ${CFLAGS} -I ${INCLUDES} -c $< -o $@

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJDIR)
	@make clean -C $(LIBFT)
	@echo "push_swap objects removed..."

fclean: clean
	@rm -f server client libftprintf.a
	@make fclean -C $(LIBFT)
	@echo "push_swap objects removed..."


re :		fclean all

.PHONY: all clean fclean re bonus
