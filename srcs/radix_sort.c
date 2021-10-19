/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 12:06:30 by slathouw          #+#    #+#             */
/*   Updated: 2021/10/19 07:15:57 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_stack_bit_sorted(t_frame *f, int hash_bit)
{
	int		remaining;
	t_stack	*s;
	int		curr_bit;

	s = f->st_a;
	remaining = f->a_to_sort;
	while (s && remaining-- > 0)
	{
		curr_bit = get_bit(S_EL_HASH(s), hash_bit);
		if (curr_bit != 0)
			return (0);
		if (s->next)
			s = s->next;
		else
			break ;
	}
	return (1);
}

void	radix_sort_el(t_frame *f, char from_stack, int hash_bit)
{
	int		bit;

	if (from_stack == 'a')
		bit = get_bit(S_EL_HASH(f->st_a), hash_bit);
	else
		bit = get_bit(S_EL_HASH(f->st_b), hash_bit);
	if (bit == 0 && !is_stack_bit_sorted(f, hash_bit))
		p(f, from_stack);
	else if (bit == 1 && ft_lstsize(f->st_a) > 1)
		r(f, from_stack);
}

int	max_hash_bit(int max_hash)
{
	int	len;

	len = 0;
	while (max_hash)
	{
		max_hash /= 2;
		len++;
	}
	return (len);
}

int	is_sorted(t_stack *s)
{
	while (s && s->next)
	{
		if (S_EL_HASH(s) > S_EL_HASH(s->next))
			return (0);
		s = s->next;
	}
	return (1);
}

void	radix_sort(t_frame *f)
{
	int	hash_bit;
	int	max_bit;

	hash_bit = 0;
	max_bit = max_hash_bit(f->a_to_sort);
	hash_el_to_index(f->st_a);
	if (!is_sorted(f->st_a))
	{
		while (hash_bit < max_bit)
		{
			while (f->a_to_sort > 0)
			{
				radix_sort_el(f, 'a', hash_bit);
				f->a_to_sort--;
			}
			f->b_to_sort = ft_lstsize(f->st_b);
			while (f->b_to_sort-- > 0)
				p(f, 'b');
			hash_bit++;
			f->a_to_sort = ft_lstsize(f->st_a);
		}
	}
}
