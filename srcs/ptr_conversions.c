/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_conversions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 06:15:07 by slathouw          #+#    #+#             */
/*   Updated: 2021/10/31 06:21:52 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack_el	*to_el_ptr(void *el)
{
	return ((t_stack_el *)el);
}

int	s_el_hash(t_stack *el)
{
	t_stack_el	*sel;

	sel = (t_stack_el *) el->content;
	return (sel->hash);
}

int	s_el_number(t_stack *el)
{
	t_stack_el	*sel;

	sel = (t_stack_el *) el->content;
	return (sel->number);
}
