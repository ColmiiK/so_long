/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:24:43 by alvega-g          #+#    #+#             */
/*   Updated: 2023/11/13 14:19:41 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*aux;
	t_list	*node;
	t_list	*actual;

	if (!lst || !f || !del)
		return (0);
	aux = 0;
	actual = lst;
	while (actual)
	{
		node = ft_lstnew(f(actual->content));
		if (!node)
		{
			ft_lstclear(&aux, del);
			return (0);
		}
		ft_lstadd_back(&aux, node);
		actual = actual->next;
	}
	return (aux);
}

// void	del(void *content)
// {
// 	free(content);
// }

// void	f(void *str)
// {
// 	char	*s;
// 	int		i;

// 	s = (char *)str;
// 	i = 0;
// 	while (s[i])
// 	{
// 		s[i] = s[i] + 1;
// 		i++;
// 	}
// }

// int	main(void)
// {
// 	t_list	*head;
// 	t_list	*temp;

// 	head = malloc(sizeof(t_list));
// 	head->content = ft_strdup("lorem");
// 	head->next = malloc(sizeof(t_list));
// 	head->next->content = ft_strdup("ipsum");
// 	head->next->next = malloc(sizeof(t_list));
// 	head->next->next->content = ft_strdup("dolor");
// 	head->next->next->next = 0;
// 	temp = ft_lstmap(head, (void *)f, del);
// 	while (temp)
// 	{
// 		printf("%s\n", temp->content);
// 		temp = temp->next;
// 	}
// 	while (head)
// 	{
// 		temp = head;
// 		head = head->next;
// 		free(temp->content);
// 		free(temp);
// 	}
// }