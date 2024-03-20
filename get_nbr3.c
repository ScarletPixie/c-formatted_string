/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nbr3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulhenr <paulhenr@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:23:13 by paulhenr          #+#    #+#             */
/*   Updated: 2024/03/20 10:39:20 by paulhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "formatted_string.h"

static int	get_digit_len(int nbr, int b)
{
	if (nbr == 0)
		return (1);
	return ((nbr > (b - 1) || nbr < -(b - 1) + get_digit_len(nbr / b, b)));
}

static int	get_ldigit_len(long nbr, int b)
{
	if (nbr == 0)
		return (1);
	return ((nbr > (b - 1) || nbr < -(b - 1)) + get_ldigit_len(nbr / b, b));
}

char	*get_bintstr(int nbr, const char *base, int base_len)
{
	int		rem;
	char	*nbstr;
	size_t	index;

	index = get_digit_len(nbr, base_len);
	nbstr = malloc((index + 1 + (nbr < 0)) * sizeof(char));
	if (!nbstr)
		return (NULL);
	index += (nbr < 0);
	nbstr[index] = '\0';
	if (nbr < 0)
		*nbstr = '-';
	while (1)
	{
		index--;
		rem = nbr % base_len;
		if (rem < 0)
			rem = -rem;
		nbstr[index] = base[rem];
		if (&nbstr[index] == nbstr || index == 1 && *nbstr == '-')
			break ;
		nbr /= base_len;
	}
	return (nbstr);
}

char	*get_blongstr(long nbr, const char *base, int base_len)
{
	long	rem;
	char	*nbstr;
	size_t	index;

	index = get_ldigit_len(nbr, base_len);
	nbstr = malloc((index + 1 + (nbr < 0)) * sizeof(char));
	if (!nbstr)
		return (NULL);
	index += (nbr < 0);
	nbstr[index] = '\0';
	if (nbr < 0)
		*nbstr = '-';
	while (1)
	{
		index--;
		rem = nbr % base_len;
		if (rem < 0)
			rem = -rem;
		nbstr[index] = base[rem];
		if (&nbstr[index] == nbstr || index == 1 && *nbstr == '-')
			break ;
		nbr /= base_len;
	}
	return (nbstr);
}
