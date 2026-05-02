/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tphuwian <tphuwian@student.42bangkok.com>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-05-02 16:55:32 by tphuwian          #+#    #+#             */
/*   Updated: 2026-05-02 16:55:32 by tphuwian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	ans;

	i = 0;
	sign = 1;
	ans = 0;
	while (str[i] >= 9 && str[i] <= 13)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ans = ans * 10 + (str[i] - '0');
		i++;
	}
	return (ans * sign);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	send_char(int server_pid, char c)
{
	int	i;
	int	bits;

	i = 7;
	while (i >= 0)
	{
		bits = (c >> i) & 1;
		if (bits == 1)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		usleep(200);
		i--;
	}
}

void	send_message(int server_pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_char(server_pid, str[i]);
		i++;
	}
	send_char(server_pid, '\0');
}

int	main(int ac, char **av)
{
	int	server_pid;

	if (ac == 3)
	{
		server_pid = ft_atoi(av[1]);
		if (server_pid <= 0)
		{
			ft_putstr("Wrong pid. Please try again :(\n");
			return (1);
		}
		send_message(server_pid, av[2]);
	}
	else
		ft_putstr("Please try again :(\n");
}
