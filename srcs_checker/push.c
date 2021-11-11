/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 12:03:42 by slathouw          #+#    #+#             */
/*   Updated: 2021/11/11 15:40:49 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	push(t_stack **from, t_stack **to)
{
	t_stack	*f;
	t_stack	*t;
	t_stack	*tmp;

	f = (*from)->next;
	tmp = *from;
	tmp->next = *to;
	t = tmp;
	*from = f;
	*to = t;
}

void	p(t_frame *f, char c)
{
	if (c == 'a')
	{
		push(&(f->st_a), &(f->st_b));
		f->a_to_sort--;
		f->b_to_sort++;
	}
	else
	{
		push(&(f->st_b), &(f->st_a));
		f->a_to_sort++;
		f->b_to_sort--;
	}
}
