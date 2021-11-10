/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 06:39:37 by slathouw          #+#    #+#             */
/*   Updated: 2021/11/10 11:54:19 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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

int	ft_isnbr(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

int	ft_isint(const char *str)
{
	int			sign;
	int			i;
	long long	num;

	if (!str)
		return (0);
	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return ((num * sign) <= 2147483647 && (num * sign) >= -2147483648);
}

int	is_sorted(t_stack *s)
{
	while (s && s->next)
	{
		if (s_el_hash(s) > s_el_hash(s->next))
			return (0);
		s = s->next;
	}
	return (1);
}