/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:06:21 by rjaada            #+#    #+#             */
/*   Updated: 2025/01/23 15:02:59 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tokenization_input(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		i = process_token(input, i);
	}
}

int	handle_redirection(char *input, int i)
{
	if (input[i] == '>' && input[i + 1] == '>')
	{
		printf("token: >>\n");
		return (i + 2);
	}
	if (input[i] == '<' && input[i + 1] == '<')
	{
		printf("token: <<\n");
		return (i + 2);
	}
	printf("token: %c\n", input[i]);
	return (i + 1);
}

int	handle_variable(char *input, int i)
{
	char	*token_start;
	char	*expanded;

	token_start = &input[i];
	expanded = expand_variable(token_start);
	if (expanded)
	{
		printf("Token: %s\n", expanded);
		free(expanded);
	}
	else
		printf("Token: %s (undefined variable)\n", token_start);
	return (i + ft_strlen(token_start));
}

int	handle_quotes(char *input, int i)
{
	char	quote;
	char	*token_start;

	quote = input[i];
	token_start = &input[++i];
	if (!process_quote_content(input, &i, quote))
		return (i);
	input[i++] = '\0';
	printf("Token: %s\n", token_start);
	return (i);
}

char	*expand_variable(const char *token)
{
	char	*var_name;
	char	*value;

	if (token[0] == '$')
	{
		var_name = ft_strdup(token + 1);
		if (!var_name)
			return (NULL);
		value = getenv(var_name);
		free(var_name);
		if (value)
			return (ft_strdup(value));
		else
			return (ft_strdup(""));
	}
	return (ft_strdup(token));
}
