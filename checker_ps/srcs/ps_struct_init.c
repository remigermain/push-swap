/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 09:33:11 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/18 13:46:53 by rgermain    ###    #+. /#+    ###.fr     */
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
	lst->tri = NULL;
	lst->len_a = argc - 2;
	lst->len_b = -1;
	if (!(lst->stack_a = (int*)malloc(sizeof(int) * argc)))
		ps_error(lst);
	if (!(lst->stack_b = (int*)malloc(sizeof(int) * argc)))
		ps_error(lst);
	if (!(lst->tri = (int*)malloc(sizeof(int) * argc)))
		ps_error(lst);
	while (--argc > 0)
	{
		lst->stack_a[count] = ft_atoi(argv[argc]);
		lst->tri[count++] = ft_atoi(argv[argc]);
	}
	ft_sort_integer_table(lst->tri, lst->len_a + 1);
	return (lst);
}
