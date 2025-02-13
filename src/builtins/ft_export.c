/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:20:00 by rjaada            #+#    #+#             */
/*   Updated: 2025/02/13 15:51:32 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_valid_identifier(const char *str)
{
	int	i;

	if (!str || !*str || (!ft_isalpha(*str) && *str != '_'))
		return (0);
	i = 1;
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

static int	update_env_var(char **env, char *arg, int var_index)
{
	if (var_index >= 0)
	{
		free(env[var_index]);
		env[var_index] = ft_strdup(arg);
	}
	else
	{
		var_index = 0;
		while (env[var_index])
			var_index++;
		env[var_index] = ft_strdup(arg);
		env[var_index + 1] = NULL;
	}
	return (1);
}

static int	export_variable(char *arg, char **env)
{
	char	*eq_pos;
	char	*name;
	int		var_index;

	if (!is_valid_identifier(arg))
	{
		ft_putstr_fd(RED "export: not a valid identifier\n" RESET, 2);
		return (0);
	}
	eq_pos = ft_strchr(arg, '=');
	if (!eq_pos)
		return (1);
	name = ft_substr(arg, 0, eq_pos - arg);
	var_index = find_env_var(env, name);
	free(name);
	return (update_env_var(env, arg, var_index));
}

int	ft_export(char **args, char **env)
{
	int	i;
	int	status;

	status = 1;
	if (!args[1])
	{
		i = 0;
		while (env[i])
		{
			ft_putstr_fd("declare -x ", 1);
			ft_putendl_fd(env[i], 1);
			i++;
		}
		return (status);
	}
	i = 1;
	while (args[i])
	{
		status &= export_variable(args[i], env);
		i++;
	}
	return (status);
}
