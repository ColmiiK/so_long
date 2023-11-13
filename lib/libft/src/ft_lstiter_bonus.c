/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:11:27 by alvega-g          #+#    #+#             */
/*   Updated: 2023/11/13 14:19:34 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

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
// 	ft_lstiter(head, f);
// 	temp = head;
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