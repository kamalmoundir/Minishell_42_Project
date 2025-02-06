/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:14:06 by rjaada            #+#    #+#             */
/*   Updated: 2025/02/04 17:33:25 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	syntax_error_checker(const char *input)
{
	if (has_unclosed_quotes(input))
	{
		ft_putstr_fd("Syntax error: unclosed quote\n", STDERR_FILENO);
		return (1);
	}
	if (has_invalid_redirections(input))
	{
		ft_putstr_fd("Syntax error: invalid redirection\n", STDERR_FILENO);
		return (1);
	}
	if (has_misplaced_operators(input))
	{
		ft_putstr_fd("Syntax error: misplaced operator\n", STDERR_FILENO);
		return (1);
	}
	if (has_logical_operators(input))
	{
		ft_putstr_fd("Error: Logical operators '&&' and '||' are not supported.\n",
			STDERR_FILENO);
		return (1);
	}
	return (0);
}

void	update_quote_counts(char c, int *s_q, int *d_q)
{
	if (c == '\'')
		(*s_q)++;
	else if (c == '\"')
		(*d_q)++;
}

int	is_invalid_operator(const char **input)
{
	if (*(*input + 1) == '<' || *(*input + 1) == '>')
	{
		if (*(*input + 2) == '<' || *(*input + 2) == '>')
			return (1);
		*input += 2;
	}
	else
		(*input)++;
	return (0);
}
