/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:08:37 by rjaada            #+#    #+#             */
/*   Updated: 2025/01/28 14:28:46 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_special_char(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

int	process_quote_content(char *input, int *i, char quote)
{
	char	*expanded;

	while (input[*i] && input[*i] != quote)
	{
		if (input[*i] == '$')
		{
			expanded = expand_variable(&input[*i]);
			if (expanded)
			{
				printf("Token: %s\n", expanded);
				free(expanded);
			}
			*i += ft_strlen(&input[*i]);
		}
		else
			(*i)++;
	}
	if (input[*i] != quote)
	{
		error_input(quote);
		return (0);
	}
	return (1);
}

int	process_token(char *input, int i)
{
	char	*token_start;

	if (input[i] == '"' || input[i] == '\'')
		return (process_quoted_string(input, i));
	if (input[i] == '$')
		return (handle_variable(input, i));
	if (input[i] && input[i] != ' ')
	{
		token_start = &input[i];
		while (input[i] && input[i] != ' ')
			i++;
		if (input[i])
			input[i++] = '\0';
		printf("Token: %s\n", token_start);
		return (i);
	}
	return (i + 1);
}

void	checker_input(char *input, int *i)
{
	while (input[*i])
	{
		if (input[*i] == ' ')
		{
			(*i)++;
			continue ;
		}
		if (is_special_char(input[*i]))
		{
			*i = handle_redirection(input, *i);
			continue ;
		}
		if (input[*i] == '$')
		{
			*i = handle_variable(input, *i);
			continue ;
		}
		if (input[*i] == '\'' || input[*i] == '\"')
		{
			*i = handle_quotes(input, *i);
			continue ;
		}
		break ;
	}
}
/*
int	process_quoted_string(char *input, int i)
{
	char	quote;
	char	*token_start;
	char	*expanded;

	quote = input[i++];
	token_start = &input[i];
	while (input[i] && input[i] != quote)
		i++;
	if (input[i] != quote)
	{
		error_input(quote);
		return (i);
	}
	input[i] = '\0';
	if (quote == '"')
		expanded = expand_variable(token_start);
	else
		expanded = ft_strdup(token_start);
	if (expanded)
	{
		printf("Token: %s\n", expanded);
		free(expanded);
	}
	return (i + 1);
}
*/