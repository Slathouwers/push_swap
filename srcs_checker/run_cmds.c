/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 09:28:42 by slathouw          #+#    #+#             */
/*   Updated: 2021/11/12 10:04:21 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	run_cmd(char *cmd, t_frame *f)
{
	if (ft_strcmp(cmd, SA) == 0)
		s(f, 'a');
	else if (ft_strcmp(cmd, SB) == 0)
		s(f, 'b');
	else if (ft_strcmp(cmd, SS) == 0)
		ss(f);
	else if (ft_strcmp(cmd, PA) == 0)
		p(f, 'b');
	else if (ft_strcmp(cmd, PB) == 0)
		p(f, 'a');
	else if (ft_strcmp(cmd, RA) == 0)
		r(f, 'a');
	else if (ft_strcmp(cmd, RB) == 0)
		r(f, 'b');
	else if (ft_strcmp(cmd, RR) == 0)
		dr(f);
	else if (ft_strcmp(cmd, RRA) == 0)
		rr(f, 'a');
	else if (ft_strcmp(cmd, RRB) == 0)
		rr(f, 'b');
	else if (ft_strcmp(cmd, RRR) == 0)
		drr(f);
}

t_stack	*run_cmdslst(t_stack *sa, t_cmds *c)
{
	t_frame	f;

	f.st_a = sa;
	f.a_to_sort = ft_lstsize(sa);
	f.st_b = NULL;
	f.b_to_sort = 0;
	while (c)
	{
		run_cmd((char *)c->content, &f);
		c = c->next;
	}
	if (f.st_b)
		ft_lstclear(&f.st_b, &free);
	sa = f.st_a;
	return (sa);
}
