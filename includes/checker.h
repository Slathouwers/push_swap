/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slathouw <slathouw@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:01:02 by slathouw          #+#    #+#             */
/*   Updated: 2021/11/12 09:30:24 by slathouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libftprintf/includes/ft_printf_bonus.h"

# define SA "sa\n"
# define SB "sb\n"
# define SS "ss\n"
# define PA "pa\n"
# define PB "pb\n"
# define RA "ra\n"
# define RB "rb\n"
# define RR "rr\n"
# define RRA "rra\n"
# define RRB "rrb\n"
# define RRR "rrr\n"

/*ARRAY STRUCT AND FUNCTIONS*/

typedef struct s_stack_el
{
	int	number;
	int	hash;
}		t_stack_el;

typedef t_list	t_stack;

typedef t_list	t_cmds;

typedef struct s_frame
{
	t_stack		*st_a;
	int			a_to_sort;
	t_stack		*st_b;
	int			b_to_sort;
}				t_frame;

/*COMMANDS*/
void		s(t_frame *f, char c);
void		ss(t_frame *f);
t_stack		*rotate(t_stack *s);
t_stack		*rev_rotate(t_stack *s);
void		r(t_frame *f, char c);
void		rr(t_frame *f, char c);
void		dr(t_frame *f);
void		drr(t_frame *f);
void		p(t_frame *f, char c);

/*PTR_CONVERSIONS*/
t_stack_el	*to_el_ptr(void *el);
int			s_el_hash(t_stack *el);
int			s_el_number(t_stack *el);

/*STACK UTILS*/
int			get_bit(int number, int significance);
void		ft_swap(int *a, int *b);
void		selection_sort(int *arr, int n);
int			idx_from_arr(int *arr, int n, int to_find);
void		hash_el_to_index(t_stack *s);

/*PARSING FUNCTIONS*/
int			check_is_args_num(int argc, char **args);
int			split_len(char **split);
t_stack_el	*new_stack_el(int number);
t_stack		*parse_args(int argc, char **args);
t_stack		*parse_string(char *args);

/*PARSING UTILS*/
int			ft_isnbr(char *str);
int			ft_isint(const char *str);
int			has_duplicates(t_stack *stack);
int			is_sorted(t_stack *s);

/*PRINTING FUNCTIONS*/
void		print_stack_el(void *el);
void		print_stack(t_stack *s);
void		print_arr(int *arr, int n);
void		print_stacks(t_frame *f);
void		print_cmdlist(t_cmds *c);

/*RUN_CMDS*/
void		run_cmd(char *cmd, t_frame *f);
t_stack		*run_cmdslst(t_stack *sa, t_cmds *c);

#endif