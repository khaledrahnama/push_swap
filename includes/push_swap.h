#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int	*data;
	int	size;
}	t_stack;

int main(int argc, char **argv);

void	stack_init(t_stack *stack, int capacity);
void	stack_free(t_stack *stack);
void	stack_print(t_stack *stack, char name);

void	parse_args(int argc, char **argv, t_stack *a);

int		ft_isdigit(char c);
int		ft_strlen(const char *s);
void	ft_putnbr_fd(long n, int fd);
void	ft_putstr_fd(const char *s, int fd);

void	op_sa(t_stack *a, int print);
void	op_sb(t_stack *b, int print);
void	op_ss(t_stack *a, t_stack *b, int print);
void	op_pa(t_stack *a, t_stack *b, int print);
void	op_pb(t_stack *a, t_stack *b, int print);
void	op_ra(t_stack *a, int print);
void	op_rb(t_stack *b, int print);
void	op_rr(t_stack *a, t_stack *b, int print);
void	op_rra(t_stack *a, int print);
void	op_rrb(t_stack *b, int print);
void	op_rrr(t_stack *a, t_stack *b, int print);

void	sort_simple(t_stack *a, t_stack *b);

#endif