/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:02:40 by kmoundir          #+#    #+#             */
/*   Updated: 2025/01/29 12:37:02 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libraries/libft/libft.h"
# include "builtins.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# define RESET "\033[0m"
# define BLACK "\033[30m"              /* Black */
# define RED "\033[31m"                /* Red */
# define GREEN "\033[32m"              /* Green */
# define YELLOW "\033[33m"             /* Yellow */
# define BLUE "\033[34m"               /* Blue */
# define MAGENTA "\033[35m"            /* Magenta */
# define CYAN "\033[36m"               /* Cyan */
# define WHITE "\033[37m"              /* White */
# define BOLDBLACK "\033[1m\033[30m"   /* Bold Black */
# define BOLDRED "\033[1m\033[31m"     /* Bold Red */
# define BOLDGREEN "\033[1m\033[32m"   /* Bold Green */
# define BOLDYELLOW "\033[1m\033[33m"  /* Bold Yellow */
# define BOLDBLUE "\033[1m\033[34m"    /* Bold Blue */
# define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
# define BOLDCYAN "\033[1m\033[36m"    /* Bold Cyan */
# define BOLDWHITE "\033[1m\033[37m"   /* Bold White */

extern char	**g_env;

// structs

typedef struct s_cmd
{
	char	*cmd;
	char	**args;
	char	*input;
	char	*output;
}			t_cmd;

typedef struct s_data
{
	char *input;
	char **tokens;
	char **env_vars;
	char *old_pwd;
	char *pwd;
	
	t_cmd	*cmd;	
}			t_data;

// utils
int			is_special_char(char c);
void		checker_input(char *input, int *i);
int			process_quoted_string(char *input, int i);
int			process_token(char *input, int i);
int			process_quote_content(char *input, int *i, char quote);

// tokenization
void		tokenization_input(char *input);
int			handle_redirection(char *input, int i);
int			handle_variable(char *input, int i);
int			handle_quotes(char *input, int i);
char		*expand_variable(const char *token);

// error handling
int			error_input(char quote);
int			is_exit(char *input);

// signal handle
void		handle_sigint(int sig);
void		handle_sigquit(int sig);
void		signal_handler();

//ptint banner
void		print_banner(void);

#endif
