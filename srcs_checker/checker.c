/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:02:14 by slathouw          #+#    #+#             */
/*   Updated: 2021/11/12 09:29:57 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

/*PARSE CMDS*/
int	ft_is_in(char *s, char **s_arr)
{
	while (*s_arr)
	{
		if (ft_strcmp(s, *s_arr) == 0)
			return (1);
		s_arr++;
	}
	return (0);
}

int	check_cmds(t_cmds *c)
{
	const char	*valid[] = {"sa\n", "sb\n", "ss\n", "pa\n", "pb\n", "ra\n"
		, "rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n", 0};

	while (c)
	{
		if (!ft_is_in((char *) c->content, (char **) valid))
			return (0);
		c = c->next;
	}
	return (1);
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
	if (!check_cmds(cmds))
	{
		ft_lstclear(&cmds, &free);
		cmds = NULL;
	}
	return (cmds);
}

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
	input_stack = run_cmdslst(input_stack, cmd_list);
	if (is_len == ft_lstsize(input_stack) && is_sorted(input_stack))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(&input_stack, &free);
	ft_lstclear(&cmd_list, &free);
	return (0);
}
