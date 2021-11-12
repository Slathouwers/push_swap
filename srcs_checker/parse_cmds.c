/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 09:31:52 by slathouw          #+#    #+#             */
/*   Updated: 2021/11/12 09:33:08 by slathouw         ###   ########.fr       */
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
