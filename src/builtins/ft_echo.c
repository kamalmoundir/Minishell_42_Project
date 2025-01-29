/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjaada <rjaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:28:03 by kmoundir          #+#    #+#             */
/*   Updated: 2025/01/29 16:38:23 by rjaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_flag_echo(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' && str[1] == 'n')
	{
		i = 2;
		while (str[i] == 'n')
			i++;
		if (str[i] == '\0')
			return (1);
	}
	return (0);
}

int	echo(int ac, char **av, int fd)
{
	int	i;

	i = 0;
	if (ac == 0)
		return (ft_putchar_fd('\n', fd), 0);
	while (av[i] && (is_flag_echo(av[i]) || !ft_strcmp(av[i], "-")))
		i++;
	while (i < ac - 1)
	{
		ft_putstr_fd(av[i], fd);
		if (av[i + 1])
			ft_putstr_fd(" ", fd);
		i++;
	}
	if (i != ac)
		ft_putstr_fd(av[i], fd);
	if (!is_flag_echo(av[0]))
		ft_putchar_fd('\n', fd);
	return (0);
}
/*
int	main(int ac, char **av)
{
	if (ac >= 1)
	{
		echo(ac, (av + 1), 1);
	}
	else
		ft_putchar_fd('\n', 1);
	return (0);
}
*/