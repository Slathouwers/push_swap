/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 09:25:00 by slathouw          #+#    #+#             */
/*   Updated: 2021/10/19 07:01:19 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libftprintf/includes/ft_printf_bonus.h"

# define TO_EL_PTR(el)	((t_stack_el *)el)

# define S_EL_HASH(el)		((t_stack_el *)el->content)->hash
# define S_EL_NUMBER(el)		((t_stack_el *)el->content)->number

/*ARRAY STRUCT AND FUNCTIONS*/

typedef struct s_stack_el
{
	int	number;
	int	hash;
}		t_stack_el;

typedef t_list	t_stack;

typedef struct s_frame
{
	t_stack		*st_a;
	int			a_to_sort;
	t_stack		*st_b;
	int			b_to_sort;
}				t_frame;

/*PARSING FUNCTIONS*/
int			check_is_args_num(int argc, char **args);
int			split_len(char **split);
t_stack_el	*new_stack_el(int number);
t_stack		*parse_args(int argc, char **args);
t_stack		*parse_string(char *args);

/*PARSING UTILS*/
int			ft_isnbr(char *str);
int			ft_isint(const char *str);

/*PUSH_SWAP COMMANDS*/
	/*ROTATION*/
t_stack		*rotate(t_stack *s);
void		r(t_frame *f, char c);
t_stack		*rev_rotate(t_stack *s);
void		rr(t_frame *f, char c);
	/*PUSH*/
void		push(t_stack **from, t_stack **to);
void		p(t_frame *f, char c);

/*SORTING FUNCTIONS*/
void		radix_sort(t_frame *f);

/* RADIX_SORT*/
int			is_stack_bit_sorted(t_frame *f, int hash_bit);
void		radix_sort_el(t_frame *f, char from_stack, int hash_bit);
int			max_hash_bit(int max_hash);

/*RADIX UTILS*/
int			get_bit(int number, int significance);
void		swap(int *a, int *b);
void		selection_sort(int *arr, int n);
int			idx_from_arr(int *arr, int n, int to_find);
void		hash_el_to_index(t_stack *s);

/*PRINTING FUNCTIONS*/
void		print_stack_el(void *el);
void		print_stack(t_stack *s);
void		print_arr(int *arr, int n);
void		print_stacks(t_frame *f);

#endif
