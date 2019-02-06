/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct_init.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 10:35:20 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/06 12:49:08 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_putmin_max(t_pusw *lst)
{
	int		*tmp;
	size_t	count;

	count = -1;
	lst->min = lst->stack_a[0];
	lst->max = lst->stack_a[0];
	ft_sort_integer_table(lst->stack_b, lst->len_a + 1);
	lst->max = lst->stack_b[0];
	lst->med = lst->stack_b[(lst->len_a + 1) / 2];
	lst->min = lst->stack_b[lst->len_a];
	lst->len_b = -1;
}

t_pusw	*ps_struct_init(int argc, char **argv)
{
	t_pusw	*lst;
	size_t	count;

	count = 0;
	if (!(lst = (t_pusw*)malloc(sizeof(t_pusw))))
		ps_error(lst);
	lst->visu = 0;
	lst->instruction = 0;
	lst->med = 0;
	lst->len_a = argc - 2;
	lst->len_b = -1;
	if (!(lst->stack_a = (int*)malloc(sizeof(int) * argc - 1)))
		ps_error(lst);
	if (!(lst->stack_b = (int*)malloc(sizeof(int) * argc - 1)))
		ps_error(lst);
	while (--argc > 0)
	{
		lst->stack_a[count] = ft_atoi(argv[argc]);
		lst->stack_b[count] = lst->stack_a[count];
		count++;
	}
	ps_putmin_max(lst);
	return (lst);
}
