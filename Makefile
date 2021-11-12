# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/06 14:26:03 by slathouw          #+#    #+#              #
#    Updated: 2021/11/12 09:34:49 by slathouw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#############
# VARIABLES #
#############

NAME 	= push_swap
LIBFT 	= libftprintf
INCLUDES= includes
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
OBJDIR	= obj

#PUSH_SWAP files 
SOURCES	= push_swap.c print.c radix_utils.c parsing.c \
		  rotate.c push.c radix_sort.c parsing_utils.c \
		  swap.c ptr_conversions.c small_sort.c small_sort_utils.c
SRCDIR 	= srcs
SRCS 	= ${addprefix $(SRCDIR)/, $(SOURCES)}
OBJS	= ${addprefix $(OBJDIR)/, $(SOURCES:.c=.o)}

#CHECKER files
CHECKSOURCES = checker.c parsing_utils.c parsing.c print.c ptr_conversions.c \
				stack_utils.c push.c rotate.c swap.c doublerotate.c run_cmds.c \
				parse_cmds.c
CHECKSRCDIR  = srcs_checker
CHECKSRCS 	 = ${addprefix $(CHECKSRCDIR)/, $(CHECKSOURCES)}
CHECKOBJS	 = ${addprefix $(OBJDIR)/ch_, $(CHECKSOURCES:.c=.o)}

###############
# COMPILATION #
###############

all : 		${NAME}

#PUSH_SWAP linking compilation
$(NAME) :	$(OBJS)
	@make -C $(LIBFT)
	@cp libftprintf/libftprintf.a .
	@${CC} ${CFLAGS} -I ${INCLUDES} ${OBJS} libftprintf.a -o ${NAME}
	@echo "push_swap binary created!"

#PUSH_SWAP object compilation
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p obj
	@${CC} ${CFLAGS} -I ${INCLUDES} -c $< -o $@

#CHECKER linking compilation
checker:	$(CHECKOBJS)
	@make -C $(LIBFT)
	@cp libftprintf/libftprintf.a .
	@${CC} ${CFLAGS} -I ${INCLUDES} ${CHECKOBJS} libftprintf.a -o checker
	@echo "checker binary created!"

#CHECKER object compilation
$(OBJDIR)/ch_%.o: $(CHECKSRCDIR)/%.c
	@mkdir -p obj
	@${CC} ${CFLAGS} -I ${INCLUDES} -c $< -o $@

clean:
	@rm -f $(OBJS) $(CHECKOBJS)
	@rm -rf $(OBJDIR)
	@make clean -C $(LIBFT)
	@echo "objects removed..."

fclean: clean
	@rm -f $(NAME) checker libftprintf.a
	@make fclean -C $(LIBFT)
	@echo "binaries removed..."


re :		fclean all

.PHONY: all clean fclean re bonus
