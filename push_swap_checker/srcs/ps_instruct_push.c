/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ps_algo.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 11:55:41 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/05 17:42:19 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap_checker.h"

void	push_a(t_puswc *lst)
{
	if (lst->len_b >= 0)
		lst->stack_a[++lst->len_a] = lst->stack_b[lst->len_b--];
	lst->instruction++;
}

void	push_b(t_puswc *lst)
{
	if (lst->len_a >= 0)
		lst->stack_b[++lst->len_b] = lst->stack_a[lst->len_a--];
	lst->instruction++;
}
