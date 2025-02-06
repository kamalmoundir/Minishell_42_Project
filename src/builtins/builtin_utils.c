/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:09:56 by rjaada            #+#    #+#             */
/*   Updated: 2025/02/05 21:27:53 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "minishell.h"

int	is_builtin(char *cmd)
{
	return (!ft_strcmp(cmd, "echo") || !ft_strcmp(cmd, "cd") || !ft_strcmp(cmd,
			"pwd") || !ft_strcmp(cmd, "env") || !ft_strcmp(cmd, "unset")
		|| !ft_strcmp(cmd, "exit"));
}

static int	count_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

int	execute_builtin(char **args, char **env)
{
	if (!args || !args[0])
		return (1);
	if (!ft_strcmp(args[0], "echo"))
		return (echo(count_args(args) - 1, args + 1, 1));
	if (!ft_strcmp(args[0], "cd"))
		return (ft_cd(args[1]));
	if (!ft_strcmp(args[0], "pwd"))
		return (pwd(count_args(args) - 1));
	if (!ft_strcmp(args[0], "env"))
		return (ft_env(env, 1, env)); // Pass env instead of environ
	if (!ft_strcmp(args[0], "unset") && args[1])
		ft_unset(args[1], env); // Already using env parameter
	if (!ft_strcmp(args[0], "exit"))
		return (is_exit(args[0]));
	return (1);
}
