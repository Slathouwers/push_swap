/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:02:14 by slathouw          #+#    #+#             */
/*   Updated: 2021/11/11 13:20:49 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	print_cmdlist(t_cmds *c)
{
	ft_printf("COMMAND LIST =\n");
	while (c)
	{
		ft_printf("%s", (char *)c->content);
		c = c->next;
	}
}

t_cmds	*parse_cmds(void)
{
	t_cmds	*cmds;
	char	*line;

	cmds = NULL;
	line = get_next_line(0);
	while (line)
	{
		ft_lstadd_back(&cmds, ft_lstnew(line));
		line = get_next_line(0);
	}
	print_cmdlist(cmds);
	//TODO: Write parsing routines to parse cmdlist and check for formatting
	return (cmds);
}

void	exit_error(t_stack *s_to_free, t_cmds *c_to_free)
{
	if (s_to_free)
		ft_lstclear(&s_to_free, &free);
	if (c_to_free)
		ft_lstclear(&c_to_free, &free);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_stack		*input_stack;
	int			is_len;
	t_cmds		*cmd_list;

	if (argc == 2)
		input_stack = parse_string(argv[1]);
	if (argc > 2)
		input_stack = parse_args(argc - 1, ++argv);
	if (!input_stack)
		exit_error(NULL, NULL);
	if (has_duplicates(input_stack))
		exit_error(input_stack, NULL);
	is_len = ft_lstsize(input_stack);
	cmd_list = parse_cmds();
	if (!cmd_list)
		exit_error(input_stack, NULL);
	//input_stack = run_cmdslst(input_stack, cmd_list); //TODO: run cmdlist on frame
	if (is_len == ft_lstsize(input_stack) && is_sorted(input_stack))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(&input_stack, &free);
	ft_lstclear(&cmd_list, &free);
	return (0);
}
