/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 09:25:00 by slathouw          #+#    #+#             */
/*   Updated: 2021/10/12 09:11:30 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libftprintf/includes/ft_printf_bonus.h"

# define TO_EL_PTR(el)	((t_stack_el *)el)

# define S_EL_HASH(el)		((t_stack_el *)el->content)->hash
# define S_EL_NUMBER(el)		((t_stack_el *)el->content)->number

/*ARRAY STRUCT AND FUNCTIONS*/

typedef struct s_stack_el
{
	int	number;
	int	hash;
}		t_stack_el;

typedef t_list t_stack;

typedef struct s_cmdlist
{
	int		count;
	char	*cmd_str;
}			t_cmdlist;

typedef struct s_frame
{
	t_stack		*st_a;
	int			a_len;
	t_stack		*st_b;
	int			b_len;
	t_cmdlist	*cmds;
}				t_frame;

/*PUSH_SWAP COMMANDS*/

/*SORTING FUNCTIONS*/

#endif
