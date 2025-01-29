/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:20:16 by rjaada            #+#    #+#             */
/*   Updated: 2025/01/23 15:05:26 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	error_input(char quote)
{
	printf("Erorr: Unmatched %c\n", quote);
	return (-1);
}

int	is_exit(char *input)
{
	char	*str;

	str = ft_strtrim(input, " ");
	if (ft_strcmp(str, "exit") == 0)
		return (free(str), 1);
	return (free(str), 0);
}
