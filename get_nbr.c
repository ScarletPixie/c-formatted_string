/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulhenr <paulhenr@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:11:21 by paulhenr          #+#    #+#             */
/*   Updated: 2024/03/20 11:12:35 by paulhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "formatted_string.h"

static int	get_digit_len(int nbr)
{
	if (nbr == 0)
		return (1);
	return ((nbr > 9 || nbr < -9) + get_digit_len(nbr / 10));
}

static int	get_ldigit_len(long nbr)
{
	if (nbr == 0)
		return (1);
	return ((nbr > 9 || nbr < -9) + get_ldigit_len(nbr / 10));
}

char	*get_long_str(long nbr)
{
	long	rem;
	char	*nbstr;
	size_t	index;

	index = get_ldigit_len(nbr);
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
		rem = nbr % 10;
		if (rem < 0)
			rem = -rem;
		nbstr[index] = rem + '0';
		if (&nbstr[index] == nbstr || index == 1 && *nbstr == '-')
			break ;
		nbr /= 10;
	}
	return (nbstr);
}

char	*get_int_str(int nbr)
{
	int		rem;
	char	*nbstr;
	size_t	index;

	index = get_digit_len(nbr);
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
		rem = nbr % 10;
		if (rem < 0)
			rem = -rem;
		nbstr[index] = rem + '0';
		if (&nbstr[index] == nbstr || index == 1 && *nbstr == '-')
			break ;
		nbr /= 10;
	}
	return (nbstr);
}
