/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:24:45 by rjaada            #+#    #+#             */
/*   Updated: 2024/11/18 17:47:25 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	**split_input(char *input)
{
	int		i;
	char	**tokens;
	char	*token;

	i = 0;
	tokens = malloc(1024 * sizeof(char *));
	token = strtok(input, " ");
	while (token)
	{
		tokens[i++] = token;
		token = strtok(NULL, " ");
	}
	tokens[i] = NULL;
	return (tokens);
}
