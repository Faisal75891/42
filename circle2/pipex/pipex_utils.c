/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 22:53:06 by fbaras            #+#    #+#             */
/*   Updated: 2025/09/27 22:53:09 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	count_words(char *arg)
{
	int		i;
	int		word_count;
	char	*trimmed_arg;
	int		in_word;

	i = 0;
	word_count = 0;
	in_word = 0;
	trimmed_arg = ft_strtrim(arg, " ");
	if (!trimmed_arg)
		return (0);
	while (trimmed_arg[i])
	{
		if (trimmed_arg[i] != ' ' && in_word == 0)
		{
			word_count++;
			in_word = 1;
		}
		else if (trimmed_arg[i] == ' ')
			in_word = 0;
		i++;
	}
	free(trimmed_arg);
	return (word_count);
}

static int	word_len(char *arg, int i)
{
	int	len;

	len = 0;
	while (arg[len + i] && arg[len + i] != ' ')
		len++;
	return (len);
}

static char	*free_array(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (NULL);
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (NULL);
}

static char	**parse_arguments(char *arg)
{
	char	**arg_list;
	int		i;
	int		j;
	int		len;

	arg = ft_strtrim(arg, " ");
	arg_list = malloc ((count_words(arg) + 1) * sizeof(char *));
	if (!arg_list)
		return (NULL);
	i = 0;
	len = 0;
	j = 0;
	while (arg[i])
	{
		len = word_len(arg, i);
		arg_list[j] = malloc(len + 1);
		if (!arg_list[j])
			return (free_array(arg_list));
		ft_strlcpy(arg_list[j], &arg[i], len);
		arg_list[j++][len] = '\0';
		i += len;
	}
	arg_list[j] = NULL;
	return (arg_list);
}
