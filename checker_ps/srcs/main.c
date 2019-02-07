/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 09:33:11 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/06 09:45:53 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap_checker.h"

static int	main_manager(int argc, char **argv)
{
	t_puswc	*lst;
	int		ret;

	if (!check_arg(argv))
		return (0);
	lst = ps_struct_init(argc, argv);
	ret = ps_checker(lst);
	if (ret == 1)
		ft_printf("OK\n");
	else if (ret == -1)
		ft_printf("KO\n");
	ps_free(lst);
	return (ret);
}

int			main(int argc, char **argv)
{
	int ret;

	if (argc > 1)
		if (!main_manager(argc, argv))
			ft_printf("Error\n");
	return (0);
}
