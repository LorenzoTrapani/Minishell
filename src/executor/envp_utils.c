#include "minishell.h"

void	add_node_env(t_list **envp, char *str)
{
	t_list	*new_node;
	t_list	*tmp;
	
	tmp = *envp;
	new_node = ft_lstnew(str);
	if (!new_node)
		return ;
	ft_lstadd_back(&tmp, new_node);
}

t_list	*change_env_variable(t_list *envp, char *var, char *new)
{
	t_list	*tmp;
	int		len_var;
	int		len_new;

	tmp = envp;
	len_var = ft_strlen(var);
	len_new = ft_strlen(new);
	while (tmp)
	{
		if (ft_strncmp(tmp->content, var, len_var) == 0)
		{
			free(tmp->content);
			tmp->content = malloc(sizeof(char) * (len_var + len_new + 1));
			ft_strlcpy(tmp->content, var, len_var + 1);
			ft_strlcpy(tmp->content + len_var, new, len_new + 1);
			return (envp);
		}
		tmp = tmp->next;
	}
	return (envp);
}

char	*find_word_in_env(t_list *envp, char *word)
{
	char *str;

	while (envp)
	{
		str = (char *)envp->content;
		if (ft_strncmp(str, word, ft_strlen(word)) == 0)
			return (str + ft_strlen(word));
		envp = envp->next;
	}
	return (NULL);
}

t_list	*find_node_in_env(t_list *envp, char *word, int len)
{
	char *str;

	while (envp)
	{
		str = (char *)envp->content;
		if (ft_strncmp(str, word, len) == 0)
			return (envp);
		envp = envp->next;
	}
	return (NULL);
}
