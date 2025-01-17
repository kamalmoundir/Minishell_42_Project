/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:29:05 by rjaada            #+#    #+#             */
/*   Updated: 2025/01/16 14:57:16 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int	main(void)
{
	char	*input;

	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
	while (1)
	{
		input = readline("Minishell> ");
		if (input == NULL)
			break ;
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

/*
int main(void)
{
	pwd(0);

	return 0;
}*/


int	main(int ac, char **av)
{
	
	if (ac >= 1)
	{
		echo(ac - 1, (av + 1), 1);
	}
	else
		ft_putchar_fd('\n', 1);
	return (0);
}
