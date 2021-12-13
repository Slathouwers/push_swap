/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 09:31:52 by slathouw          #+#    #+#             */
/*   Updated: 2021/12/13 09:48:32 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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
	const char	*valid[] = {"sa\n", "sb\n", "ss\n", "pa\n", "pb\n", "ra\n",
		"rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n", 0};

	while (c)
	{
		if (!ft_is_in((char *) c->content, (char **) valid))
			return (0);
		c = c->next;
	}
	return (1);
}

t_cmds	*parse_cmds(int *cmd_count)
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
	*cmd_count = ft_lstsize(cmds);
	if (!check_cmds(cmds))
	{
		ft_lstclear(&cmds, &free);
		cmds = NULL;
	}
	return (cmds);
}
