/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublerotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 11:58:52 by slathouw          #+#    #+#             */
/*   Updated: 2021/11/11 15:53:43 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	dr(t_frame *f)
{
	f->st_a = rotate(f->st_a);
	f->st_b = rotate(f->st_b);
}

void	drr(t_frame *f)
{
	f->st_a = rev_rotate(f->st_a);
	f->st_b = rev_rotate(f->st_b);
}
