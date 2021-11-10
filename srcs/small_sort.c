/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 06:07:48 by slathouw          #+#    #+#             */
/*   Updated: 2021/11/10 09:57:58 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_triplet(t_frame *f)
{
	const t_stack	*stack = f->st_a;
	const int		first = s_el_hash((t_stack *)stack);
	const int		second = s_el_hash((t_stack *)stack->next);
	const int		third = s_el_hash((t_stack *)stack->next->next);

	if (third > second && second < first && first < third)
		s(f, 'a');
	else if (third < second && second < first && first > third)
	{
		s(f, 'a');
		rr(f, 'a');
	}
	else if (third > second && second < first && first > third)
		r(f, 'a');
	else if (third < second && second > first && first < third)
	{
		s(f, 'a');
		r(f, 'a');
	}
	else if (third < second && second > first && first > third)
		rr(f, 'a');
}

static void	sort_split_triplet(t_frame *f)
{
	while (f->a_to_sort > 3)
	{
		p(f, 'a');
		f->a_to_sort--;
		f->b_to_sort++;
	}
	sort_triplet(f);
	while (f->b_to_sort > 0)
	{
		pushb_insert(f);
		f->b_to_sort--;
	}
	rotate_to_top_a(f, 0);
}

void	small_sort(t_frame *f)
{
	hash_el_to_index(f->st_a);
	if (!is_sorted(f->st_a))
	{
		if (f->a_to_sort == 2)
			s(f, 'a');
		else if (f->a_to_sort == 3)
			sort_triplet(f);
		else
			sort_split_triplet(f);
	}
}
