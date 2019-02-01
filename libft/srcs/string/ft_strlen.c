/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 17:17:10 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/04 10:31:36 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

size_t	ft_strnlen(const char *s, size_t max)
{
	size_t count;

	count = 0;
	while (s[count] != '\0' && count < max)
		count++;
	return (count);
}

size_t	ft_ustrlen(const unsigned char *s)
{
	size_t count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

size_t	ft_ustrnlen(const unsigned char *s, size_t max)
{
	size_t count;

	count = 0;
	while (s[count] != '\0' && count < max)
		count++;
	return (count);
}
