/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 06:07:48 by slathouw          #+#    #+#             */
/*   Updated: 2021/11/09 13:48:17 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_triplet(t_frame *f)
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

int	minimax(t_stack *s, int minhash, int max)
{
	int			minimax;
	int			curr_hash;

	minimax = max;
	while (s)
	{
		curr_hash = s_el_hash(s);
		if (curr_hash > minhash && curr_hash < minimax)
			minimax = s_el_hash(s);
		s = s->next;
	}
	if (minimax == max)
		return (minhash);
	return (minimax);
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
	int	minimax_a;

	b_hash = s_el_hash(f->st_b);
	minimax_a = minimax(f->st_a, b_hash,
			ft_lstsize(f->st_a) + ft_lstsize(f->st_b));
	//print_stacks(f);
	//ft_printf("----> elhash= %i | minimax_a= %i |\n", b_hash, minimax_a);
	if (minimax_a == b_hash)
	{
		p(f, 'b');
		return ;
	}
	else
	{
		rotate_to_top_a(f, minimax_a);
		p(f, 'b');
	}
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
//	print_stacks(f);
}
