/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 06:07:48 by slathouw          #+#    #+#             */
/*   Updated: 2021/10/31 08:29:18 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_triplet(t_frame *f)
{
	const t_stack	*stack = f->st_a;
	const int		first = s_el_hash((t_stack *)stack);
	const int		second = s_el_hash((t_stack *)stack->next);
	const int		third = s_el_hash((t_stack *)stack->next->next);

	print_stacks(f);
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
	print_stacks(f);
}

void	sort_split_triplet(t_frame *f)
{
	while (f->a_to_sort > 3)
	{
		p(f, 'a');
		f->a_to_sort--;
		f->b_to_sort++;
	}
	sort_triplet(f);
	//TODO: implement pushing back from b
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
