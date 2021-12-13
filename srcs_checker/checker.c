/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:02:14 by slathouw          #+#    #+#             */
/*   Updated: 2021/12/13 09:55:55 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

/*MAIN*/
void	exit_error(t_stack *s_to_free, t_cmds *c_to_free)
{
	if (s_to_free)
		ft_lstclear(&s_to_free, &free);
	if (c_to_free)
		ft_lstclear(&c_to_free, &free);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	check_input_stack(t_stack *is)
{
	if (!is)
		exit_error(NULL, NULL);
	if (has_duplicates(is))
		exit_error(is, NULL);
}

int	main(int argc, char **argv)
{
	t_stack		*input_stack;
	int			is_len;
	t_cmds		*cmd_list;
	int			cmd_len;

	if (argc < 2)
		return (0);
	if (argc == 2)
		input_stack = parse_string(argv[1]);
	if (argc > 2)
		input_stack = parse_args(argc - 1, ++argv);
	check_input_stack(input_stack);
	is_len = ft_lstsize(input_stack);
	cmd_list = parse_cmds(&cmd_len);
	if (cmd_len != ft_lstsize(cmd_list))
		exit_error(input_stack, NULL);
	input_stack = run_cmdslst(input_stack, cmd_list);
	if (is_len == ft_lstsize(input_stack) && is_sorted(input_stack))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(&input_stack, &free);
	ft_lstclear(&cmd_list, &free);
	system("leaks checker");
	return (0);
}
