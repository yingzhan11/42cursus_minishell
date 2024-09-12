/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envlist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:21:36 by likong            #+#    #+#             */
/*   Updated: 2024/09/12 19:00:52 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*new_env(char *key, char *value)
{
	t_env	*res;

	res = (t_env *)malloc(sizeof(t_env));
	if (!res)
		return (NULL);
	res->key = key;
	res->value = value;
	return (res);
}

char	*get_env(char *key)
{
	t_env	*tmp;
	t_list	*curr;

	if (key[0] == '$')
		key++;
	curr = ms()->env_list;
	while (curr)
	{
		tmp = (t_env *)curr->content;
		if (!ft_strcmp(tmp->key, key))
			return (ft_strdup(tmp->value));
		curr = curr->next;
	}
	return (ft_strdup(""));
}

t_env	*find_env(t_list *envs, char *key)
{
	t_list	*curr;
	t_env	*env;

	if (!envs)
		return (NULL);
	curr = envs;
	while (curr)
	{
		env = (t_env *)curr->content;
		if (!ft_strcmp(env->key, key))
			return (env);
		curr = curr->next;
	}
	return (NULL);
}

// void	update_env(void)
// {
// 	char	*res;

// 	delete_matrix(ms()->path);
// 	delete_matrix(ms()->envp);
// 	res = get_env("PATH");
// }

void	print_env(void)
{
	int	i;

	i = -1;
	while (ms()->envp[++i])
		printf("%s\n", ms()->envp[i]);
}
