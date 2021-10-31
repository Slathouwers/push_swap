/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 11:44:17 by slathouw          #+#    #+#             */
/*   Updated: 2021/10/31 06:25:45 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_bit(int number, int significance)
{
	return (number >> significance & 1);
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	selection_sort(int *arr, int n)
{
	int	i;
	int	j;
	int	min_index;

	i = -1;
	while (++i < n - 1)
	{
		min_index = i;
		j = i;
		while (++j < n)
			if (arr[j] < arr[min_index])
				min_index = j;
		ft_swap(&arr[min_index], &arr[i]);
	}
}

int	idx_from_arr(int *arr, int n, int to_find)
{
	int	i;

	i = -1;
	while (++i < n && arr[i] != to_find)
		;
	return (i);
}

void	hash_el_to_index(t_stack *s)
{
	int		*numbers;
	t_list	*iter_ptr;
	int		n;
	int		i;

	iter_ptr = s;
	i = 0;
	n = ft_lstsize(s);
	numbers = ft_calloc(sizeof(int), n);
	if (!numbers)
		return ;
	while (iter_ptr)
	{
		numbers[i++] = s_el_number(iter_ptr);
		iter_ptr = iter_ptr->next;
	}
	selection_sort(numbers, n);
	iter_ptr = s;
	while (iter_ptr)
	{
		((t_stack_el *)iter_ptr->content)->hash
			= idx_from_arr(numbers, n, s_el_number(iter_ptr));
		iter_ptr = iter_ptr->next;
	}
	free(numbers);
}
