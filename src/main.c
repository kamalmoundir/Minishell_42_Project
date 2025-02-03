/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:29:05 by rjaada            #+#    #+#             */
/*   Updated: 2025/02/03 13:15:58 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "minishell.h"

int			g_exit_status;

static int	process_input(char *input)
{
	t_list	*tokens;

	if (ft_strcmp(input, "exit") == 0)
		return (1);
	tokens = tokenize_input(input);
	if (!tokens)
		return (0);
	print_token_list(tokens);
	ft_lstclear(&tokens, (void *)token_free);
	return (0);
}

int	main(void)
{
	char	*input;

	print_banner();
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
	g_exit_status = 0;
	while (1)
	{
		input = readline("minishell> ");
		if (!input)
			break ;
		if (input && *input)
			add_history(input);
		if (process_input(input))
		{
			free(input);
			break ;
		}
		free(input);
	}
	return (g_exit_status);
}

/*
int	main(void)
{
	char	*input;
	char	*path;

	print_banner();
	signal_handler();
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
}*/
/*extern char **environ;
int	main(int ac, char **av)
{
	(void)ac;
	//ft_env(env);
	//printf("%s", av[1]);
	environ = av;
	ft_cd(av[1]);
	printf("%d\n", ft_cd(av[1]));
	return (0);
}*/
/*int main(int ac, char **av)
{
	(void)ac;
	//ft_env(env);
	//printf("%s", av[1]);
	//ft_cd(av[1]);
	path = av[1];
	printf("%s\n", path);
	chdir(path);
	return (0);
}
*/
/*
int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	ft_env(env);
	return (0);
}
*/
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
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void		ft_unset(char *var, char **env);

void	print_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
	printf("-----------\n");
}
*/
/*int main()
{
	// Simulating environment variables
	char *env[] = {
		strdup("USER=kamal"),
		strdup("PATH=/usr/bin:/bin"),
		strdup("SHELL=/bin/bash"),
		strdup("HOME=/home/kamal"),
		NULL
	};

	printf("Before unset:\n");
	print_env(env);

	ft_unset("PATH", env);

	printf("After unset:\n");
	print_env(env);

		//Free allocated memory (important to prevent leaks)
	for (int i = 0; env[i]; i++)
		free(env[i]);

	return (0);
}*/
