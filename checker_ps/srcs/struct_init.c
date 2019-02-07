/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct_init.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 10:35:20 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/01 19:22:38 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap_checker.h"

void	ps_putmin_max(t_puswc *lst)
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
	lst->len_b = -1;
}

t_puswc	*ps_struct_init(int argc, char **argv)
{
	t_puswc	*lst;
	size_t	count;

	count = 0;
	if (!(lst = (t_puswc*)malloc(sizeof(t_puswc))))
		ps_error(lst);
	lst->instruction = 0;
	lst->len_a = argc - 2;
	lst->len_b = -1;
	if (!(lst->stack_a = (int*)malloc(sizeof(int) * argc - 1)))
		ps_error(lst);
	if (!(lst->stack_b = (int*)malloc(sizeof(int) * argc - 1)))
		ps_error(lst);
	while (--argc > 0)
		lst->stack_a[count++] = ft_atoi(argv[argc]);
	ps_putmin_max(lst);
	return (lst);
}
