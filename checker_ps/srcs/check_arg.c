/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_instruction.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 09:46:13 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/12 14:11:02 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap_checker.h"

static int	ft_atol(char *str)
{
	size_t	count;
	long	nb;
	int		neg;

	count = 0;
	nb = 0;
	neg = 1;
	while (str[count] == ' ' || (str[count] >= 9 && str[count] <= 13))
		count++;
	if (str[count] == '+' || str[count] == '-')
	{
		if (str[count] == '-')
			neg = -1;
		count++;
	}
	while (str[count] >= '0' && str[count] <= '9' && nb <= 2147483648)
		nb = ((nb * 10) + (str[count++] - '0'));
	nb *= neg;
	if (nb < -2147483648 || nb > 2147483647)
		return (0);
	return (1);
}

static int	check_doublon(char **argv)
{
	size_t	count;
	size_t	count2;
	int		tmp;

	count = 0;
	while (argv[++count] != NULL)
	{
		tmp = ft_atoi(argv[count]);
		count2 = count;
		while (argv[++count2] != NULL)
		{
			if (ft_atoi(argv[count2]) == tmp)
				return (0);
		}
	}
	return (1);
}

int			check_arg(char **argv)
{
	size_t	count;
	MINT	sign;

	count = 0;
	while (argv[++count] != NULL)
	{
		sign = 0;
		if (argv[count][0] == '-' || argv[count][0] == '+')
			sign = 1;
		if (ft_strlen(argv[count] + sign) == 0 ||
				!ft_atol(argv[count]) ||
				!ft_str_is_numeric(argv[count] + sign))
			return (0);
	}
	return (check_doublon(argv));
}
