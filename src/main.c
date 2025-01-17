/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:29:05 by rjaada            #+#    #+#             */
/*   Updated: 2025/01/17 13:47:21 by kmoundir         ###   ########.fr       */
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
		if (is_exit(input) == 1)
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

/*
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
*/
/*
#include <stdio.h>

int	main(void)
{
	int	file;

	int i=0;
	file = open("file.txt", O_RDONLY);
	if (file < 0)
	{
		perror("Error opening file");
		return (1);
	}
	char **map=array_map(file);
	while(map[i])
	{
		printf("%s\n",map[i]);
		free(map[i]);
		i++;
	}
	free(map);
	close(file);
	return (0);
}
*/