/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 09:57:09 by slathouw          #+#    #+#             */
/*   Updated: 2021/11/10 11:12:18 by slathouw         ###   ########.fr       */
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
			if (s_el_number(i) == s_el_number(j))
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

t_stack	*sort(t_stack *stack_a)
{
	t_frame	f;

	f.st_a = stack_a;
	f.a_to_sort = ft_lstsize(stack_a);
	f.st_b = NULL;
	f.b_to_sort = 0;
	if (f.a_to_sort < 50)
		small_sort(&f);
	else
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
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (has_duplicates(input_stack))
	{
		write(2, "Error\n", 6);
		ft_lstclear(&input_stack, &free);
		return (1);
	}
	input_stack = sort(input_stack);
	ft_lstclear(&input_stack, &free);
	return (0);
}
