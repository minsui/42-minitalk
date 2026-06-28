/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim2 <mkim2@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 12:50:46 by mkim2             #+#    #+#             */
/*   Updated: 2026/06/08 13:20:08 by mkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

int	ft_atoi(const char *str)
{
	int	result;
	int	n;

	result = 0;
	n = 0;
	while (str[n] >= '0' && str[n] <= '9')
	{
		result = result * 10 + (str[n] - '0');
		n++;
	}
	return (result);
}

void	send_char(pid_t pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(400);
		i--;
	}
}

int	main(int ac, char **av)
{
	pid_t		pid;
	char		*message;
	int			i;

	i = 0;
	if (ac != 3)
		return (-1);
	pid = (pid_t)ft_atoi(av[1]);
	message = av[2];
	while (message[i])
	{
		send_char(pid, message[i]);
		i++;
	}
	return (0);
}
