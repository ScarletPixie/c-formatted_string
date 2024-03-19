/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatted_string.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulhenr <paulhenr@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:55:12 by paulhenr          #+#    #+#             */
/*   Updated: 2024/03/19 16:56:17 by paulhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMATTED_STRING_H
# define FORMATTED_STRING_H

# include <stdarg.h>
# include <stdlib.h>

char	*get_format_string(char *format, ...);

#endif