/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 12:03:42 by slathouw          #+#    #+#             */
/*   Updated: 2021/10/15 12:04:05 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
		push(&(f->st_a), &(f->st_b));
	else
		push(&(f->st_b), &(f->st_a));
	if (c == 'a')
		c = 'b';
	else
		c = 'a';
	ft_printf("p%c\n", c);
}
