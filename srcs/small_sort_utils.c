/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 09:53:46 by slathouw          #+#    #+#             */
/*   Updated: 2021/11/10 10:34:10 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	maximin(t_stack *s, int minhash, int max)
{
	int			maximin;
	int			curr_hash;

	maximin = max;
	while (s)
	{
		curr_hash = s_el_hash(s);
		if (curr_hash > minhash && curr_hash < maximin)
			maximin = s_el_hash(s);
		s = s->next;
	}
	if (maximin == max)
		return (minhash);
	return (maximin);
}

void	rotate_to_top_a(t_frame *f, int hash)
{
	t_stack	*s;
	int		el_idx;
	int		rots;
	int		revs;

	s = f->st_a;
	el_idx = 0;
	while (s->next && s_el_hash(s) != hash)
	{
		s = s->next;
		el_idx++;
	}
	rots = el_idx;
	revs = ft_lstsize(f->st_a) - el_idx;
	if (rots > revs)
		while (revs-- > 0)
			rr(f, 'a');
	else
		while (rots-- > 0)
			r(f, 'a');
}

void	pushb_insert(t_frame *f)
{
	int	b_hash;
	int	maximin_a;

	b_hash = s_el_hash(f->st_b);
	maximin_a = maximin(f->st_a, b_hash,
			ft_lstsize(f->st_a) + ft_lstsize(f->st_b));
	if (maximin_a == b_hash)
	{
		rotate_to_top_a(f, 0);
		p(f, 'b');
		return ;
	}
	else
	{
		rotate_to_top_a(f, maximin_a);
		p(f, 'b');
	}
}
