/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct_init.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 10:35:20 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/01 11:43:10 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_putmin_max(t_pusw *lst)
{
	size_t count;

	count = -1;
	lst->min = lst->stack_a[0];
	lst->max = lst->stack_a[0];
	while (++count < lst->len_a)
	{
		if (lst->max < lst->stack_a[count])
			lst->max = lst->stack_a[count];
		if (lst->min > lst->stack_a[count])
			lst->min = lst->stack_a[count];
	}
	ps_debug(lst);
}

t_pusw	*ps_struct_init(int argc, char **argv)
{
	t_pusw	*lst;

	if (!(lst = (t_pusw*)malloc(sizeof(t_pusw))))
		ps_error(lst);
	lst->len_a = argc - 1;
	lst->len_b = 0;
	if (!(lst->stack_a = (int*)malloc(sizeof(int) * argc - 1)))
		ps_error(lst);
	if (!(lst->stack_b = (int*)malloc(sizeof(int) * argc - 1)))
		ps_error(lst);
	while (--argc > 0)
		lst->stack_a[argc - 1] = ft_atoi(argv[argc]);
	ps_putmin_max(lst);
	return (lst);
}
