/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tphuwian <tphuwian@student.42bangkok.com>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-05-02 16:55:37 by tphuwian          #+#    #+#             */
/*   Updated: 2026-05-02 16:55:37 by tphuwian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

void	putnbr(int nb)
{
	if (nb > 9)
	{
		putnbr(nb / 10);
		putnbr(nb % 10);
	}
	else
		write(1, &"0123456789"[nb % 10], 1);
}

void	receive(int signal)
{
	static int	bits;
	static char	current_c;

	if (signal == SIGUSR2)
		current_c = (current_c << 1) | 1;
	else if (signal == SIGUSR1)
		current_c = (current_c << 1);
	bits++;
	if (bits == 8)
	{
		write(1, &current_c, 1);
		if (current_c == '\0')
			write(1, "\n", 1);
		bits = 0;
		current_c = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	putnbr(pid);
	write(1, "\n", 1);
	signal(SIGUSR1, receive);
	signal(SIGUSR2, receive);
	while (1)
		pause();
	return (0);
}
