/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nbr4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulhenr <paulhenr@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:40:30 by paulhenr          #+#    #+#             */
/*   Updated: 2024/03/20 11:15:02 by paulhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "formatted_string.h"

static int	get_udigit_len(unsigned int nbr, int b)
{
	if (nbr == 0)
		return (1);
	return ((nbr >= b) + get_udigit_len(nbr / b, b));
}

static int	get_ludigit_len(unsigned long nbr, int b)
{
	if (nbr == 0)
		return (1);
	return ((nbr >= b) + get_ludigit_len(nbr / b, b));
}

char	*get_base_uint_str(unsigned int nbr, const char *base, int base_len)
{
	char	*nbstr;
	size_t	index;

	index = get_udigit_len(nbr, base_len);
	nbstr = malloc((index + 1) * sizeof(char));
	if (!nbstr)
		return (NULL);
	nbstr[index] = '\0';
	while (1)
	{
		index--;
		nbstr[index] = (base[nbr % base_len]);
		if (index == 0)
			break ;
		nbr /= base_len;
	}
	return (nbstr);
}

char	*get_base_ulong_str(unsigned long nbr, const char *base, int base_len)
{
	char	*nbstr;
	size_t	index;

	index = get_ludigit_len(nbr, base_len);
	nbstr = malloc((index + 1) * sizeof(char));
	if (!nbstr)
		return (NULL);
	nbstr[index] = '\0';
	while (1)
	{
		index--;
		nbstr[index] = (base[nbr % base_len]);
		if (index == 0)
			break ;
		nbr /= base_len;
	}
	return (nbstr);
}

#include <limits.h>
int	main(void)
{
	char	*str = get_bulongstr(ULONG_MAX, "01f", 2);
	printf("%s\n", str);
	free(str);
}