/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 09:57:09 by slathouw          #+#    #+#             */
/*   Updated: 2021/10/15 12:06:36 by slathouw         ###   ########.fr       */
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
