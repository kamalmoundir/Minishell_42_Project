/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:06:21 by rjaada            #+#    #+#             */
/*   Updated: 2025/01/20 14:13:06 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tokenization_input(char *input)
{
	int		i;
	char	*token_start;

	i = 0;
	while (input[i])
	{
		checker_input(input, &i);
		if (input[i] && input[i] != ' ')
		{
			token_start = &input[i];
			while (input[i] && input[i] != ' ')
				i++;
			if (input[i])
				input[i++] = '\0';
			printf("Token: %s\n", token_start);
		}
	}
}

//convert tokens to matrice of tokens
char **array_tokens(char *input)
{
	char **array;
	if(input == NULL)
		return NULL;
	array = ft_split(input, ' ');
	if(array == NULL)
		return NULL;
	return array;
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
		printf("Expanded Variable: %s\n", expanded);
		free(expanded);
	}
	else
		printf("token: %s (undefined variable)\n", token_start);
	return (i + ft_strlen(token_start));
}

int	handle_quotes(char *input, int i)
{
	char	quote;
	char	*token_start;

	quote = input[i];
	token_start = &input[++i];
	while (input[i] && input[i] != quote)
		i++;
	if (input[i] != quote)
	{
		error_input(quote);
		return (i);
	}
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
		value = getenv(var_name);
		free(var_name);
		if (value)
			return (ft_strdup(value));
		else
			return (ft_strdup(""));
	}
	return (ft_strdup(token));
}
