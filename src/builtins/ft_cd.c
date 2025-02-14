/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:50:37 by kmoundir          #+#    #+#             */
/*   Updated: 2025/02/14 13:58:33 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
//todo
we can take different inputs in theman unset future
we  use  getcwd, chdir, and make our (setenv) function
*/

static void	update_env(void)
{
	char	*oldpwd;
	char	cwd[1024];

	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("getcwd");
		return ;
	}
	oldpwd = getenv("PWD");
	if (oldpwd != NULL)
	{
		setenv("OLDPWD", oldpwd, 1);
	}
	setenv("PWD", cwd, 1);
}

int	ft_cd(char *path)
{
	if (!path)
	{
		ft_putstr_fd("error: cd: bad arguments\n", 2);
		g_exit_status = 1;
		return (1);
	}
	else if (chdir(path) != 0)
	{
		ft_putstr_fd("error: cd: cannot change directory to ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd("\n", 2);
		g_exit_status = 1;
		return (1);
	}
	update_env();
	g_exit_status = 0;
	return (0);
}
