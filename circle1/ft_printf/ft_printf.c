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
#include "./libft/libft.h"

	#include <stdio.h>

	static int	handle_specifier(const char format, va_list ap)
	{
		if (format == 'd' ||format == 'i')
			return ft_putnbr_fdi(va_arg(ap, signed int), 0, 1);
		else if (format == 'u')
			return ft_putunbr_fd(va_arg(ap, unsigned int), 1);
		else if (format == 'x')
			return ft_putnbr_base_fd(va_arg(ap, unsigned int), "0123456789abcdef", 1);
		else if (format == 'X')
			return ft_putnbr_base_fd(va_arg(ap, unsigned int), "0123456789ABCDEF", 1);
		else if (format == 'p')
    		return ft_putptr_fd(va_arg(ap, void *), 1);
		else if (format == 's')
			return ft_putstr_fdi(va_arg(ap, char *), 1);
		else if (format == 'c')
			return ft_putchar_fdi(va_arg(ap, int), 1);
		else if (format == '%')
			return ft_putchar_fdi('%', 1);
		else
			return ft_putchar_fdi(format, 1);
		return (0);
	}

	int ft_printf(const char *format, ...)
	{
		va_list	ap;
		int		chars_written;

		va_start(ap, format);
		chars_written = 0;
		while (*format)
		{
			if (*format == '%')
				chars_written += handle_specifier(*(++format), ap);
			else
				chars_written += write(1, format, 1);
			format++;
		}
		va_end(ap);
		return (chars_written);
	}

	int	main(void)
	{
		char	*test = "hello";
		int x = 42;
    	void *ptr = &x;
		void *null_ptr = NULL;

		printf("Hello my name is [%s] and I am [%d] years old\n", "faisal", 20);
		ft_printf("Hello my name is [%s] and I am [%d] years old\n", "faisal", 20);

		printf("chars written for printf   : %d\n", printf("Hello my name is [%s] and I am [%d] years old", "faisal", 20));
		ft_printf("chars written for ft_printf: %d\n", ft_printf("Hello my name is [%s] and I am [%d] years old", "faisal", 20));

		printf("%d\n", printf("Hello my name is [] and I am [%d] years old", 20));
		ft_printf("%d\n", ft_printf("Hello my name is [] and I am [%d] years old", 20));

		ft_printf("Simple string\n");
		ft_printf("Char: %c, String: %s\n", 'A', "test");
		ft_printf("Numbers: %d, %i, %u\n", -42, 42, 42);
		ft_printf("Pointer: %p\n", &test);
		printf("Pointer: %p\n", &test);

		ft_printf("Pointer: %p\n", ptr);
   		printf("Pointer: %p\n", ptr);

		ft_printf("NULL pointer: %p\n", null_ptr);
    	printf("NULL pointer: %p\n", null_ptr);

		ft_printf("Invalid: %z\n");
		printf("NULL string: %p\n", NULL);
		ft_printf("NULL string: %p\n", NULL); 
	}



	//the standard order of elements in a format string after %:

	// %[flags][width][.precision][length][specifier]