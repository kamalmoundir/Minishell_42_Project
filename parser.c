/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:06:21 by rjaada            #+#    #+#             */
/*   Updated: 2024/12/23 16:44:04 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <string.h>

void	tokenization_input(char *input)
{
	int		i;
	char	*token_start;
	char	quote;

	token_start = NULL;
	i = 0;
	while (input[i])
	{
		if (input[i] == ' ')
		{
			i++;
			continue ;
		}
		if (input[i] == '\'' || input[i] == '\"')
		{
			quote = input[i];
			token_start = &input[++i];
			while (input[i] && input[i] != quote)
				i++;
			if (input[i] != quote)
			{
				error_input(quote);
				return ;
			}
			input[i++] = '\0';
			printf("Token: %s\n", token_start);
			continue ;
		}
		token_start = &input[i];
		while (input[i] && input[i] != ' ')
			i++;
		if (input[i])
			input[i++] = '\0';
		printf("Token: %s\n", token_start);
	}
}
