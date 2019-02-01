/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 09:33:11 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/01 18:51:42 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

int	main_manager(int argc, char **argv)
{
	t_pusw	*lst;
	int	interactive;

	interactive = 0;
	if (argv[argc - 1][0] == 'v')
	{
		argv[argc - 1] = NULL;
		interactive = 1;
	}
	if (check_arg(argv) == -1)
		return (-1);
	lst = ps_struct_init(argc - 1, argv);
	if (interactive == 1)
		ps_algo2(lst);
	else
		ps_algo(lst);
	ps_free(lst);
	return (1);
}

int main(int argc, char **argv)
{
	int ret;

	if (argc > 1)
		if (main_manager(argc, argv) == -1)
			ft_dprintf(2, "Error\n");
	return (0);
}
