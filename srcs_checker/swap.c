/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 12:03:42 by slathouw          #+#    #+#             */
/*   Updated: 2021/11/11 16:42:25 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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
		swap(&(f->st_a));
	else if (ft_lstsize(f->st_b) >= 2)
		swap(&(f->st_b));
}

void	ss(t_frame *f)
{
	if (ft_lstsize(f->st_b) >= 2)
		swap(&(f->st_a));
	if (ft_lstsize(f->st_a) >= 2)
		swap(&(f->st_b));
}
