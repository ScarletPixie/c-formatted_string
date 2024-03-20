/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatted_string.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulhenr <paulhenr@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:55:12 by paulhenr          #+#    #+#             */
/*   Updated: 2024/03/20 11:15:24 by paulhenr         ###   ########.fr       */
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
char	*get_int_str(int nbr);
char	*get_long_str(long nbr);
char	*get_uint_str(unsigned int nbr);
char	*get_ulong_str(unsigned long nbr);
char	*get_base_int_str(int nbr, const char *base, int base_len);
char	*get_base_long_str(long nbr, const char *base, int base_len);
char	*get_base_ulong_str(unsigned long nbr, const char *base, int base_len);
char	*get_base_uint_str(unsigned int nbr, const char *base, int base_len);

#endif
