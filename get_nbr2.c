/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nbr2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulhenr <paulhenr@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:12:28 by paulhenr          #+#    #+#             */
/*   Updated: 2024/03/20 10:21:38 by paulhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "formatted_string.h"

static int	get_udigit_len(unsigned int nbr)
{
	if (nbr == 0)
		return (1);
	return ((nbr > 9) + get_udigit_len(nbr / 10));
}

static int	get_ludigit_len(unsigned long nbr)
{
	if (nbr == 0)
		return (1);
	return ((nbr > 9) + get_ludigit_len(nbr / 10));
}

char	*get_uintstr(unsigned int nbr)
{
	char	*nbstr;
	size_t	index;

	index = get_udigit_len(nbr);
	nbstr = malloc((index + 1) * sizeof(char));
	if (!nbstr)
		return (NULL);
	nbstr[index] = '\0';
	while (1)
	{
		index--;
		nbstr[index] = (nbr % 10) + '0';
		if (index == 0)
			break ;
		nbr /= 10;
	}
	return (nbstr);
}

char	*get_luintstr(unsigned long nbr)
{
	char	*nbstr;
	size_t	index;

	index = get_ludigit_len(nbr);
	nbstr = malloc((index + 1) * sizeof(char));
	if (!nbstr)
		return (NULL);
	nbstr[index] = '\0';
	while (1)
	{
		index--;
		nbstr[index] = (nbr % 10) + '0';
		if (index == 0)
			break ;
		nbr /= 10;
	}
	return (nbstr);
}
