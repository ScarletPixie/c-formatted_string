/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatted_string.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulhenr <paulhenr@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:55:12 by paulhenr          #+#    #+#             */
/*   Updated: 2024/03/20 10:22:38 by paulhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMATTED_STRING_H
# define FORMATTED_STRING_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

char	*get_fstring(const char *format, ...);
char	*get_fstringb(const char *format, ...);
char	*ft_sprintf(char *buffer, const char *format, ...);

// get_nbr*.c
char	*get_intstr(int nbr);
char	*get_longstr(long nbr);
char	*get_uintstr(unsigned int nbr);
char	*get_luintstr(unsigned long nbr);


#endif
