/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 10:28:48 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/12 15:11:45 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap_checker.h"

void	ps_final_check(t_puswc *lst)
{
	int ret;

	ret = ft_issort(lst);
	if (lst->visu != 0)
	{
		ft_printf("\n\n le tableaux est ");
		if (ret == 1 && lst->len_b == -1)
			ft_printf("%{T_GREEN} [OK]%{T_EOC}");
		else
			ft_printf("%{T_RED} [KO]%{T_EOC}");
		ft_printf("\n");
	}
	else
	{
		if (ret == 1)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
}

int		ft_issort(t_puswc *lst)
{
	int count;

	count = lst->len_a;
	if (lst->len_b != -1)
		return (0);
	while (count > 0)
	{
		if (!(lst->stack_a[count] < lst->stack_a[count - 1]))
			return (0);
		count--;
	}
	return (1);
}

void	ps_free(t_puswc *lst)
{
	if (lst != NULL)
	{
		if (lst->stack_a != NULL)
			ft_memdel((void**)&(lst->stack_a));
		if (lst->stack_b != NULL)
			ft_memdel((void**)&(lst->stack_b));
		if (lst->tri != NULL)
			ft_memdel((void**)&(lst->tri));
		ft_memdel((void**)&(lst));
	}
}

void	ps_error(t_puswc *lst)
{
	ps_free(lst);
	ft_printf("%1@", "error", "push_swapp_checker", strerror(errno));
}
