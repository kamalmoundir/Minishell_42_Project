/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:20:57 by kmoundir          #+#    #+#             */
/*   Updated: 2025/01/29 16:38:43 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

/*
** check if the input is exit
//to do      i have to ignore the spaces caracters after exit word

*/
int	is_exit(char *input)
{
	char	*str;

	str = ft_strtrim(input, " ");
	if (ft_strcmp(str, "exit") == 0)
		return (free(str), 1);
	return (free(str), 0);
}
