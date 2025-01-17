/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:06:21 by rjaada            #+#    #+#             */
/*   Updated: 2025/01/17 10:34:25 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tokenization_input(char *input)
{
	int		i;
	char	*token_start;
	char	quote;
	char	*expanded;
4
	token_start = NULL;
	i = 0;
	while (input[i])
	{
		if (input[i] == ' ')
		{
			i++;
			continue ;
		}
		if (is_special_char(input[i]))
		{
			if (input[i] == '>' && input[i + 1] == '>')
			{
				printf("token: >>\n");
				i += 2;
				continue ;
			}
			printf("token: %c\n", input[i]);
			i++;
			continue ;
		}
		if (input[i] == '$')
		{
			token_start = &input[i];
			expanded = expand_variable(token_start);
			printf("Expanded Variable: %s\n", expanded);
			free(expanded);
			i += ft_strlen(token_start);
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

char	*expand_variable(const char *token)
{
	char	*var_name;
	char	*value;

	if (token[0] == '$')
	{
		var_name = ft_strdup(token + 1);
		value = getenv(var_name);
		free(var_name);
		if (value)
			return (ft_strdup(value));
		else
			return (ft_strdup(""));
	}
	return (ft_strdup(token));
}
