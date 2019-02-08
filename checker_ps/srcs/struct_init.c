/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct_init.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 10:35:20 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/08 10:22:02 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap_checker.h"

t_puswc	*ps_struct_init(int argc, char **argv)
{
	t_puswc	*lst;
	size_t	count;

	count = 0;
	lst = NULL;
	if (!(lst = (t_puswc*)malloc(sizeof(t_puswc))))
		ps_error(lst);
	lst->stack_a = NULL;
	lst->stack_b = NULL;
	lst->instruction = 0;
	lst->len_a = argc - 2;
	lst->len_b = -1;
	if (!(lst->stack_a = (int*)malloc(sizeof(int) * argc - 1)))
		ps_error(lst);
	if (!(lst->stack_b = (int*)malloc(sizeof(int) * argc - 1)))
		ps_error(lst);
	while (--argc > 0)
		lst->stack_a[count++] = ft_atoi(argv[argc]);
	return (lst);
}
