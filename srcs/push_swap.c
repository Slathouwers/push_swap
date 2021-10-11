/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 09:57:09 by slathouw          #+#    #+#             */
/*   Updated: 2021/10/11 12:22:33 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_is_args_num(int argc, char **args)
{
	//TODO: implement
	(void) argc, (void) args;
	return (1);
}

int	split_len(char **split)
{
	int len;

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
	if(el)
		ft_printf("num: %12i\thash: %i\n",
			TO_EL_PTR(el)->number, TO_EL_PTR(el)->hash);
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
	if(!check_is_args_num(argc, args))
		return(NULL);
	while(*args && argc-- > 0)
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
	int i;

	i = -1;
	while (++i < n)
		ft_printf("%i: %i\n", i, arr[i]);
}

void	hash_el_to_index(t_stack *s)
{
	int 	*numbers;
	t_list *iter_ptr;
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

t_cmdlist	*sort(t_stack *stack_a)
{
	//TODO: implement
	hash_el_to_index(stack_a);
	(void) stack_a;
	return (NULL);
}

void	free_stack(t_stack *s)
{
	//TODO: free stack
	(void) s;
}

void	free_cmdlist(t_cmdlist *c)
{
	//TODO: free cmdlist
	(void) c;
}

int	main(int argc, char **argv)
{
	t_stack	*input_stack;
	t_cmdlist *cmds;
	
	if (argc == 2)
		input_stack = parse_string(argv[1]);
	if (argc > 2)
		input_stack = parse_args(argc - 1, ++argv);
	if(!input_stack)
		return (1);
	if (has_duplicates(input_stack))
	{
		ft_printf("ERROR: Duplicate numbers not allowed!\n");
		free_stack(input_stack);
		return (1);
	}
 	cmds = sort(input_stack);
	print_stack(input_stack);
	if(!cmds)
		return(1);
	ft_printf("%s", cmds->cmd_str);
	free_stack(input_stack);
	free_cmdlist(cmds);
	return (0);
}
