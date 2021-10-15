/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 09:57:09 by slathouw          #+#    #+#             */
/*   Updated: 2021/10/15 07:31:09 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_is_args_num(int argc, char **args)
{
	//TODO: implementP
	(void) argc, (void) args;
	return (1);
}

int	get_bit(int number, int significance)
{
	return (number >> significance & 1);
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

void	print_stack_el(void *el)
{
	int	hash;

	hash = TO_EL_PTR(el)->hash;
	if (el)
		ft_printf("num: %12i\thash: %3i\tBinary:%i%i%i%i\n",
			TO_EL_PTR(el)->number, TO_EL_PTR(el)->hash,
			get_bit(hash, 3), get_bit(hash, 2),
			get_bit(hash, 1), get_bit(hash, 0));
}

void	print_stack(t_stack *s)
{
	ft_lstiter(s, &print_stack_el);
}

t_stack	*parse_args(int argc, char **args)
{
	t_stack		*stack;
	int			number;

	stack = NULL;
	if (!check_is_args_num(argc, args))
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
	int		len;
	t_stack	*stack;

	stack = NULL;
	numbers = ft_split(args, ' ');
	if (!numbers)
		return (NULL);
	len = split_len(numbers);
	stack = parse_args(len, numbers);
	ft_free_split(numbers);
	return (stack);
}

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
			if (S_EL_NUMBER(i) == S_EL_NUMBER(j))
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

void	swap(int *a, int *b)
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
		swap(&arr[min_index], &arr[i]);
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

void print_arr(int *arr, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		ft_printf("%i: %i\n", i, arr[i]);
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
		numbers[i++] = S_EL_NUMBER(iter_ptr);
		iter_ptr = iter_ptr->next;
	}
	selection_sort(numbers, n);
	iter_ptr = s;
	while (iter_ptr)
	{
		S_EL_HASH(iter_ptr) = idx_from_arr(numbers, n, S_EL_NUMBER(iter_ptr));
		iter_ptr = iter_ptr->next;
	}
}

int	is_sorted(t_stack *s)
{
	while (s && s->next)
	{
		if (S_EL_HASH(s) > S_EL_HASH(s->next))
			return (0);
		s = s->next;
	}
	return (1);
}

t_stack	*rotate(t_stack *s)
{
	t_stack	*tmp;

	if (!s || !s->next)
		return (s);
	tmp = s;
	s = tmp->next;
	tmp->next = NULL;
	ft_lstlast(s)->next = tmp;
	return (s);
}

void	r(t_frame *f, char c)
{
	if (c == 'a')
		f->st_a = rotate(f->st_a);
	else
		f->st_b = rotate(f->st_b);
	ft_printf("r%c\n", c);
}

t_stack	*rev_rotate(t_stack *s)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*sec_to_last;

	if (!s || !s->next)
		return (s);
	first = s;
	while (s && s->next)
	{
		sec_to_last = s;
		last = s->next;
		s = s->next;
	}
	sec_to_last->next = NULL;
	last->next = first;
	return (last);
}

void	rr(t_frame *f, char c)
{
	if (c == 'a')
		f->st_a = rev_rotate(f->st_a);
	else
		f->st_b = rev_rotate(f->st_b);
	ft_printf("rr%c\n", c);
}

void	push(t_stack **from, t_stack **to)
{
	t_stack	*f;
	t_stack	*t;
	t_stack	*tmp;

	f = (*from)->next;
	tmp = *from;
	tmp->next = *to;
	t = tmp;
	*from = f;
	*to = t;
}

void	p(t_frame *f, char c)
{
	if (c == 'a')
		push(&(f->st_a), &(f->st_b));
	else
		push(&(f->st_b), &(f->st_a));
	ft_printf("p%c\n", c);
}

int	is_stack_bit_sorted(t_frame *f, int bit, int hash_bit)
{
	int		remaining;
	t_stack	*s;
	int		max_bit;
	int		curr_bit;

	if (!f->st_a || !f->st_a->next || f->a_to_sort < 1)
		return (1);
	s = f->st_a->next;
	remaining = f->a_to_sort;
	max_bit = bit;
	while (s && s->next && remaining--)
	{
		curr_bit = get_bit(S_EL_HASH(s), hash_bit);
		if (curr_bit < max_bit)
			return (0);
		else
			max_bit = curr_bit;
		s = s->next;
	}
	return (1);
}

void	radix_sort_el(t_frame *f, char from_stack, int hash_bit)
{
	int		bit;

	if (from_stack == 'a')
		bit = get_bit(S_EL_HASH(f->st_a), hash_bit);
	else
		bit = get_bit(S_EL_HASH(f->st_b), hash_bit);
	if (bit == 0 && !is_stack_bit_sorted(f, bit, hash_bit))
		p(f, from_stack);
	else if (!is_stack_bit_sorted(f, bit, hash_bit))
		r(f, from_stack);
}

int	max_hash_bit(int max_hash)
{
	int	len;

	len = 0;
	while (max_hash)
	{
		max_hash /= 2;
		len++;
	}
	return (len);
}

void	sort(t_stack *stack_a)
{
	t_frame	f;
	int		hash_bit;
	int		max_bit;

	f.st_a = stack_a;
	f.a_to_sort = ft_lstsize(stack_a);
	f.st_b = NULL;
	f.b_to_sort = 0;
	hash_bit = 0;
	max_bit = max_hash_bit(f.a_to_sort);
	hash_el_to_index(stack_a);
	while (hash_bit < max_bit)
	{
		while (f.a_to_sort-- > 0)
			radix_sort_el(&f, 'a', hash_bit);
		f.b_to_sort = ft_lstsize(f.st_b);
		while (f.b_to_sort-- > 0)
			p(&f, 'b');
		hash_bit++;
		f.a_to_sort = ft_lstsize(f.st_a);
	}
/* 	ft_printf("----STACK A-----\n");
	print_stack(f.st_a);
	ft_printf("----STACK B-----\n");
	print_stack(f.st_b); */
}

void	free_stack(t_stack *s)
{
	//TODO: free stack
	(void) s;
}

int	main(int argc, char **argv)
{
	t_stack		*input_stack;

	if (argc == 2)
		input_stack = parse_string(argv[1]);
	if (argc > 2)
		input_stack = parse_args(argc - 1, ++argv);
	if (!input_stack)
		return (1);
	if (has_duplicates(input_stack))
	{
		ft_printf("ERROR: Duplicate numbers not allowed!\n");
		free_stack(input_stack);
		return (1);
	}
	sort(input_stack);
	free_stack(input_stack);
	return (0);
}
