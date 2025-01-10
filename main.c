/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:29:05 by rjaada            #+#    #+#             */
/*   Updated: 2025/01/10 17:07:49 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char	*input;

	while (1)
	{
		input = readline("Minishell> ");
		if (input == NULL)
		{
			printf("exit\n");
			break ;
		}
		if (input && *input)
			add_history(input);
		if (ft_strcmp(input, "exit") == 0)
		{
			free(input);
			break ;
		}
		tokenization_input(input);
		free(input);
	}
	return (0);
}
