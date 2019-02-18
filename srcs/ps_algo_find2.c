/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ps_algo.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 11:55:41 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/18 11:10:49 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(int *stack, int len)
{
	int	min;

	min = 2147483647;
	while (len >= 0)
	{
		if (stack[len] < min)
			min = stack[len];
		len--;
	}
	return (min);
}

int	find_max(int *stack, int len)
{
	int	min;

	min = -2147483648;
	while (len >= 0)
	{
		if (stack[len] > min)
			min = stack[len];
		len--;
	}
	return (min);
}

int	find_next_min(int *stack, int len, int tmp)
{
	int	min;

	min = 2147483647;
	while (len >= 0)
	{
		if (stack[len] < min && stack[len] > tmp)
			min = stack[len];
		len--;
	}
	return (min);
}

int	find_next_max(int *stack, int len, int tmp)
{
	int	min;

	min = -2147483648;
	while (len >= 0)
	{
		if (stack[len] > min && stack[len] < tmp)
			min = stack[len];
		len--;
	}
	return (min);
}

int	find_nb(int *stack, int len, int nb)
{
	while (len >= 0)
	{
		if (stack[len] == nb)
			return (len);
		len--;
	}
	return (0);
}
