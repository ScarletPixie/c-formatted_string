/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatted_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulhenr <paulhenr@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:56:54 by paulhenr          #+#    #+#             */
/*   Updated: 2024/03/19 17:07:18 by paulhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "formatted_string.h"

char	*get_format_string(char *format, ...)
{
	char	*buffer;
	size_t	index;
	va_list	ap;

	if (!format)
		return (NULL);
	index = 0;
	while (format[index])
	{
		
		if (format[index])
			index++;
	}
}