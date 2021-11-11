/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 11:58:52 by slathouw          #+#    #+#             */
/*   Updated: 2021/11/11 15:41:12 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

t_stack	*rotate(t_stack *s)
{
	t_stack	*tmp;

	if (!s || !s->next)
		return (s);
	tmp = s;
	s = tmp->next;
	tmp->next = NULL;
	ft_lstlast(s)->next = tmp;
	return (s);
}

void	r(t_frame *f, char c)
{
	if (c == 'a')
		f->st_a = rotate(f->st_a);
	else
		f->st_b = rotate(f->st_b);
}

t_stack	*rev_rotate(t_stack *s)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*sec_to_last;

	if (!s || !s->next)
		return (s);
	first = s;
	while (s && s->next)
	{
		sec_to_last = s;
		last = s->next;
		s = s->next;
	}
	sec_to_last->next = NULL;
	last->next = first;
	return (last);
}

void	rr(t_frame *f, char c)
{
	if (c == 'a')
		f->st_a = rev_rotate(f->st_a);
	else
		f->st_b = rev_rotate(f->st_b);
}
