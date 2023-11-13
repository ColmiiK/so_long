/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 10:46:58 by alvega-g          #+#    #+#             */
/*   Updated: 2023/09/17 11:06:36 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
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

// 	int size = ft_lstsize(head);

// 	printf("%i\n", size);

// 	t_list *temp;
// 	while (head)
// 	{
// 		temp = head;
// 		head = head->next;
// 		free(temp);
// 	}
// }