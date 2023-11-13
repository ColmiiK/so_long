/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:15:10 by alvega-g          #+#    #+#             */
/*   Updated: 2023/11/13 14:19:37 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
// int main()
// {
// 	t_list *head = malloc(sizeof(t_list));

// 	head->content = "1";
// 	head->next = malloc(sizeof(t_list));
// 	head->next->content = "2";
// 	head->next->next = malloc(sizeof(t_list));
// 	head->next->next->content = "3";
// 	head->next->next->next = 0;

// 	t_list *actual = malloc(sizeof(t_list));

// 	actual = ft_lstlast(head);
// 	printf("%s\n", actual->content);

// 	t_list *temp;
// 	while (head)
// 	{
// 		temp = head;
// 		head = head->next;
// 		free(temp);
// 	}
// }