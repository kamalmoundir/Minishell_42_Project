/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:29:05 by rjaada            #+#    #+#             */
/*   Updated: 2025/01/29 15:50:56 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "minishell.h"

int			g_exit_status;

static void	token_print_wrapper(t_token *token)
{
	ft_putstr_fd("Token: ", 1);
	if (token->type == TOKEN_WORD)
		ft_putstr_fd("WORD", 1);
	else if (token->type == TOKEN_PIPE)
		ft_putstr_fd("PIPE", 1);
	else if (token->type == TOKEN_REDIR_IN)
		ft_putstr_fd("REDIR_IN", 1);
	else if (token->type == TOKEN_REDIR_OUT)
		ft_putstr_fd("REDIR_OUT", 1);
	else if (token->type == TOKEN_HEREDOC)
		ft_putstr_fd("HEREDOC", 1);
	else if (token->type == TOKEN_APPEND)
		ft_putstr_fd("APPEND", 1);
	else if (token->type == TOKEN_EOF)
		ft_putstr_fd("EOF", 1);
	if (token->value)
	{
		ft_putstr_fd(" -> [", 1);
		ft_putstr_fd(token->value, 1);
		ft_putstr_fd("]", 1);
	}
	ft_putstr_fd("\n", 1);
}

static int	process_input(char *input)
{
	t_lexer	*lexer;
	t_token	*token;

	if (ft_strcmp(input, "exit") == 0)
		return (1);
	lexer = lexer_init(input);
	if (!lexer)
		return (0);
	while (1)
	{
		token = lexer_get_next_token(lexer);
		if (!token)
			break ;
		token_print_wrapper(token);
		if (token->type == TOKEN_EOF)
		{
			token_free(token);
			break ;
		}
		token_free(token);
	}
	lexer_free(lexer);
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
/*int main(int ac, char **av)
{
	(void)ac;
	//ft_env(env);
	//printf("%s", av[1]);
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