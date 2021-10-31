/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 12:03:42 by slathouw          #+#    #+#             */
/*   Updated: 2021/10/31 05:58:48 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack **s)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*rest;

	if (ft_lstsize(*s) >= 2)
	{
		first = *s;
		second = first->next;
		rest = second->next;
		first->next = rest;
		second->next = first;
		*s = second;
	}
}

void	s(t_frame *f, char c)
{
	if (c == 'a' && ft_lstsize(f->st_a) >= 2)
	{
		swap(&(f->st_a));
		ft_printf("s%c\n", c);
	}
	else if (ft_lstsize(f->st_b) >= 2)
	{
		swap(&(f->st_b));
		ft_printf("s%c\n", c);
	}
}

void	ss(t_frame *f)
{
	if (ft_lstsize(f->st_b) >= 2 && ft_lstsize(f->st_a) >= 2)
	{
		swap(&(f->st_a));
		swap(&(f->st_b));
		ft_printf("ss\n");
	}
}
