/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 09:57:09 by slathouw          #+#    #+#             */
/*   Updated: 2021/10/15 12:04:29 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	has_duplicates(t_stack *stack)
{
	t_stack	*i;
	t_stack	*j;

	i = stack;
	while (i && i->next)
	{
		j = i->next;
		while (j)
		{
			if (S_EL_NUMBER(i) == S_EL_NUMBER(j))
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
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

void	radix_sort(t_frame *f)
{
	int	hash_bit;
	int	max_bit;

	hash_bit = 0;
	max_bit = max_hash_bit(f->a_to_sort);
	hash_el_to_index(f->st_a);
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

t_stack	*sort(t_stack *stack_a)
{
	t_frame	f;

	f.st_a = stack_a;
	f.a_to_sort = ft_lstsize(stack_a);
	f.st_b = NULL;
	f.b_to_sort = 0;
	radix_sort(&f);
	return (f.st_a);
}

int	main(int argc, char **argv)
{
	t_stack		*input_stack;

	if (argc == 2)
		input_stack = parse_string(argv[1]);
	if (argc > 2)
		input_stack = parse_args(argc - 1, ++argv);
	if (!input_stack)
		return (1);
	if (has_duplicates(input_stack))
	{
		ft_printf("ERROR: Duplicate numbers not allowed!\n");
		ft_lstclear(&input_stack, &free);
		return (1);
	}
	if (!is_sorted(input_stack))
		input_stack = sort(input_stack);
	ft_lstclear(&input_stack, &free);
	return (0);
}
