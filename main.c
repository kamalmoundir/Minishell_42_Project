/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:54:59 by rjaada            #+#    #+#             */
/*   Updated: 2024/11/18 17:47:14 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	int		i;
	char	*input;
	char	**args;

	i = 0;
	while (1)
	{
		input = readline("minishell$ ");
		if (!input)
		{
			printf("Exiting minishell...\n");
			break ;
		}
		args = split_input(input);
		while (args[i])
		{
			printf("Arg[%d]: %s\n", i, args[i]);
			i++;
		}
		free(input);
		free(args);
	}
	return (0);
}
