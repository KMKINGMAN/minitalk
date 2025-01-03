/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:06:52 by mkurkar           #+#    #+#             */
/*   Updated: 2024/12/27 16:57:01 by mkurkar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minitalk.h"

static int	g_sending;

void	set_sending(int signal)
{
	if (signal == SIGUSR1)
		g_sending = TRUE;
}

void	send_bit(int pid, char bit)
{
	unsigned char	temp;
	int				i_bit;

	i_bit = 8;
	temp = (unsigned char)bit;
	while (i_bit--)
	{
		g_sending = 0;
		temp = (bit >> i_bit);
		if (temp % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (!g_sending)
			;
	}
}

void	send_message(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_bit(pid, str[i]);
		i++;
	}
	send_bit(pid, '\0');
}

void	sig_handler(void)
{
	struct sigaction	sa;

	sa.sa_handler = &set_sending;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		(write(1, "Error\n", 6));
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		(write(1, "Error\n", 6));
}

int	main(int argc, char **argv)
{
	int	pid;

	ft_args_checker(argc, argv);
	pid = ft_atoi(argv[1]);
	if (pid < 0)
	{
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	sig_handler();
	if (argv[2][0] == '\0')
		send_message(pid, "\0");
	send_message(pid, argv[2]);
	return (0);
}
