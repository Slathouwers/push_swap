/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 09:25:00 by slathouw          #+#    #+#             */
/*   Updated: 2021/10/09 10:10:37 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libftprintf/includes/ft_printf_bonus.h"

/*ARRAY STRUCT AND FUNCTIONS*/

typedef struct s_stack
{
	int				content;
	int				hash;
	struct s_stack	*next;
}	t_stack;

typedef struct s_frame
{
	struct s_stack	*st_a;
	int				a_len;
	struct s_stack	*st_b;
	int				b_len;
}	t_frame;

/*PUSH_SWAP COMMANDS*/

/*SORTING FUNCTIONS*/

#endif
