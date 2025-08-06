/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:34:12 by fbaras            #+#    #+#             */
/*   Updated: 2025/08/05 19:45:42 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>
# include "./libft/libft.h"

int	ft_printf(const char *, ...);
int	ft_putnbr_base_fd(unsigned int nbr, const char *base, int fd);
int	ft_putnbr_fdi(int n, int i, int fd);
int ft_putunbr_fd(unsigned int nbr, int fd);
int ft_putptr_fd(void *ptr, int fd);
int ft_putstr_fdi(char *s, int fd);
int	ft_putchar_fdi(char c, int fd);

#endif