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

int		main(int argc, char **argv);

void	stack_init(t_stack *stack, int capacity);
void	stack_free(t_stack *stack);
void	stack_print(t_stack *stack, char name);

void	parse_args(int argc, char **argv, t_stack *a);

int		ft_isdigit(char c);
int		ft_strlen(const char *s);
void	ft_putnbr_fd(long n, int fd);
void	ft_putstr_fd(const char *s, int fd);

#endif