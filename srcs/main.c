/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 09:33:11 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/11 11:22:24 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

static t_pusw	*ps_struct_init(int argc, char **argv)
{
	t_pusw	*lst;
	size_t	count;

	count = 0;
	lst = NULL;
	if (!(lst = (t_pusw*)malloc(sizeof(t_pusw))))
		ps_error(lst);
	ft_bzero(lst, sizeof(t_pusw));
	lst->len_a = argc - 2;
	lst->len_b = -1;
	if (!(lst->stack_a = (int*)malloc(sizeof(int) * argc)))
		ps_error(lst);
	if (!(lst->stack_b = (int*)malloc(sizeof(int) * argc)))
		ps_error(lst);
	while (--argc > 0)
		lst->stack_a[count++] = ft_atoi(argv[argc]);
	return (lst);
}

static int		main_manager(int argc, char **argv)
{
	t_pusw	*lst;

	if (!check_arg(argv))
		return (0);
	lst = ps_struct_init(argc, argv);
	ps_algo(lst);
	ps_free(lst);
	return (1);
}

int				main(int argc, char **argv)
{
	if (argc > 1)
		if (!main_manager(argc, argv))
			ft_dprintf(2, "Error\n");
	return (0);
}
