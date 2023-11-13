/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 10:41:21 by alvega-g          #+#    #+#             */
/*   Updated: 2023/11/13 14:19:27 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
// int	main(void)
// {
// 	t_list *head = malloc(sizeof(t_list));
// 	t_list *new = malloc(sizeof(t_list));

// 	head->content = "lorem";
// 	head->next = 0;
// 	new->content = "ipsum";
// 	new->next = 0;

// 	ft_lstadd_front(&head, new);

// 	t_list *actual = head;

// 	while (actual)
// 	{
// 		printf("%s\n", actual->content);
// 		actual = actual->next;
// 	}
// 	t_list *temp;
// 	while (head)
// 	{
// 		temp = head;
// 		head = head->next;
// 		free(temp);
// 	}
// }