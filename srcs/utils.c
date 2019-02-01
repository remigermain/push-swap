/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 10:28:48 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/01 14:49:10 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

int ft_issort(int *stack_a, int len)
{
	int count;

	count = 0;
	while (count < (len - 1))
	{
		if (stack_a[count] < stack_a[count + 1])
			count++;
		else
			return (-1);
	}
	return (1);
}

void	ps_free(t_pusw *lst)
{
	if (lst != NULL)
	{
		if (lst->stack_a != NULL)
			free(lst->stack_a);
		if (lst->stack_b != NULL)
			free(lst->stack_b);
		free(lst);
	}	
}

void	ps_error(t_pusw *lst)
{
	ps_free(lst);
	ft_printf("%1@", "error", "push_swapp", strerror(errno));
}
