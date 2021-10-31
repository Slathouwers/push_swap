/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 11:03:58 by slathouw          #+#    #+#             */
/*   Updated: 2021/10/31 06:26:35 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack_el(void *el)
{
	int	hash;

	hash = to_el_ptr(el)->hash;
	if (el)
		ft_printf("num: %12i\thash: %3i\tBinary:%i%i%i%i\n",
			to_el_ptr(el)->number, to_el_ptr(el)->hash,
			get_bit(hash, 3), get_bit(hash, 2),
			get_bit(hash, 1), get_bit(hash, 0));
}

void	print_stack(t_stack *s)
{
	ft_lstiter(s, &print_stack_el);
}

void	print_stacks(t_frame *f)
{
	ft_printf("----STACK A-----\n");
	print_stack(f->st_a);
	ft_printf("----STACK B-----\n");
	print_stack(f->st_b);
}

void	print_arr(int *arr, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		ft_printf("%i: %i\n", i, arr[i]);
}
