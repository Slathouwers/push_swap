/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 11:49:48 by slathouw          #+#    #+#             */
/*   Updated: 2021/10/19 06:58:19 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_is_args_int(int argc, char **args)
{
	while (argc-- > 0)
	{
		if (!ft_isnbr(*args) || !ft_isint(*args))
			return (0);
		args++;
	}
	return (1);
}

int	split_len(char **split)
{
	int	len;

	len = 0;
	if (!split)
		return (len);
	while (*split++)
		len++;
	return (len);
}

t_stack_el	*new_stack_el(int number)
{
	t_stack_el	*el;

	el = (t_stack_el *) ft_calloc(sizeof(t_stack_el), 1);
	if (!el)
		return (NULL);
	el->number = number;
	return (el);
}

t_stack	*parse_args(int argc, char **args)
{
	t_stack		*stack;
	int			number;

	stack = NULL;
	if (!check_is_args_int(argc, args))
		return (NULL);
	while (*args && argc-- > 0)
	{
		number = ft_atoi(*args++);
		ft_lstadd_back(&stack, ft_lstnew(new_stack_el(number)));
	}
	return (stack);
}

t_stack	*parse_string(char *args)
{
	char	**numbers;
	char	**curr_number_ptr;
	int		len;
	t_stack	*stack;

	stack = NULL;
	numbers = ft_split(args, ' ');
	if (!numbers)
		return (NULL);
	len = split_len(numbers);
	stack = parse_args(len, numbers);
	curr_number_ptr = numbers;
	while (*curr_number_ptr)
	{
		free(*curr_number_ptr);
		curr_number_ptr++;
	}
	free(numbers);
	return (stack);
}
