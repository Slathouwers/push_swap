/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 09:57:09 by slathouw          #+#    #+#             */
/*   Updated: 2021/10/15 11:48:29 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_is_args_num(int argc, char **args)
{
	//TODO: implementP
	(void) argc, (void) args;
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
	if (c == 'a')
		c = 'b';
	else
		c = 'a';
	ft_printf("p%c\n", c);
}

int	is_stack_bit_sorted(t_frame *f, int hash_bit)
{
	int		remaining;
	t_stack	*s;
	int		curr_bit;

	s = f->st_a;
	remaining = f->a_to_sort;
	while (s && remaining-- > 0)
	{
		curr_bit = get_bit(S_EL_HASH(s), hash_bit);
		if (curr_bit != 0)
			return (0);
		if (s->next)
			s = s->next;
		else
			break ;
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
	if (bit == 0 && !is_stack_bit_sorted(f, hash_bit))
		p(f, from_stack);
	else if (bit == 1 && ft_lstsize(f->st_a) > 1)
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

t_stack	*sort(t_stack *stack_a)
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
		while (f.a_to_sort > 0)
		{
			radix_sort_el(&f, 'a', hash_bit);
			f.a_to_sort--;
		}
		f.b_to_sort = ft_lstsize(f.st_b);
		while (f.b_to_sort-- > 0)
			p(&f, 'b');
		hash_bit++;
		f.a_to_sort = ft_lstsize(f.st_a);
	}
	return (f.st_a);
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
		ft_lstclear(&input_stack, &free);
		return (1);
	}
	if (!is_sorted(input_stack))
		input_stack = sort(input_stack);
	ft_lstclear(&input_stack, &free);
	return (0);
}
