/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:02:14 by slathouw          #+#    #+#             */
/*   Updated: 2021/11/10 11:55:46 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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
	print_stack(input_stack);
	if (is_sorted(input_stack))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	//TODO: Set up frame to execute cmdlist instructions
	//TODO: Write parsing routines to parse cmdlist and check for formatting
	//			errors
	//TODO: run cmdlist on frame
	//TODO: check if stack b is empty && stack a is sorted
	return (0);
}
