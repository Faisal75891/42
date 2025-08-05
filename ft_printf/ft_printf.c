/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:33:55 by fbaras            #+#    #+#             */
/*   Updated: 2025/08/05 19:52:30 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

static int	num_of_args(char *s)
{
	/*
	TODO:

	Counts how many '%' are present
	and returns that number.
	Ignores consecutive '%'
	*/
	return (0);
}

static void	ft_putnbr_hex_fd(int n, int fd)
{
	char	*hex = "0123456789ABCDEF";
	long	num;

	num = n;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num = -num;
	}
	if (num >= 16)
		ft_putnbr_hex_fd(num / 16, fd);
	ft_putchar_fd(hex[num % 16], fd);
}

static int	print_padding(int width, int len, char c)
{
	int count = 0;
	while (len < width)
	{
		count += ft_putchar(c);
		len++;
	}
	return (count);
}

static void	init_flags(t_flags *flags)
{
	flags->has_minus = 0;
	flags->has_dot = 0;
	flags->has_zero = 0;
	flags->has_hash = 0;
	flags->has_plus = 0;
	flags->has_space = 0;
	flags->width = 0;
}

static void	set_variables(const char *specifier, t_flags *flags)
{
	init_flags(flags);
	specifier++;

	while (*specifier == '-' || *specifier == '.' || *specifier == '0' ||
		   *specifier == '#' || *specifier == '+' || *specifier == ' ')
	{
		if (*specifier == '-')
			flags->has_minus = 1;
		else if (*specifier == '.')
			flags->has_dot = 1;
		else if (*specifier == '0')
			flags->has_zero = 1;
		else if (*specifier == '#')
			flags->has_hash = 1;
		else if (*specifier == '+')
			flags->has_plus = 1;
		else if (*specifier == ' ')
			flags->has_space = 1;

		specifier++;
	}
}

static int	handle_format(const char *s, va_list ap)
{
	int		i;
	t_flags	flags;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			set_variables(s, &flags);
			if (flags.has_minus)
				flags.has_zero = 0;
			if (flags.has_plus)
				flags.has_space = 0;
			
			// TODO: HANDLE FLAGS
			if (s[i] == 'd' || s[i] == 'u' || s[i] == 'i')
				ft_putnbr_fd(va_arg(ap, int), 1);
			else if (s[i] == 'x' || s[i] == 'X' || s[i] == 'p')
				ft_putnbr_hex_fd(va_arg(ap, int), 1);
			else if (s[i] == 's')
				ft_putstr_fd(va_arg(ap, char *), 1);
			else if (s[i] == 'c')
				ft_putchar_fd(va_arg(ap, int), 1);
			else if (s[i] == '%')
				ft_putchar_fd('%', 1);
		}
		else
			ft_putchar_fd(s[i], 1);
		i++;
	}
	return (1);
}

int ft_printf(const char *s, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, s);
	count = 0;
	while (*s)
	{
		if (*s == '%')
			count += handle_format(s, ap);
		else
			ft_putchar_fd(*s, 1);
		s++;
	}
	va_end(ap);
	return (count);
}

int	main(void)
{
	ft_printf("SD;FHSADFL SDLKFAS %SDJFHSDLKJ %s %d %c %%", "hellow word", 12354523, 'c');
}



//the standard order of elements in a format string after %:

// %[flags][width][.precision][length][specifier]