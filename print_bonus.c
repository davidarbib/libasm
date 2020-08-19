/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 01:26:32 by darbib            #+#    #+#             */
/*   Updated: 2020/08/19 19:45:46 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

typedef struct				s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

int main(int ac, char **av)
{

	(void)ac;

	extern void ft_list_push_front(t_list **begin_list, void *data);
	t_list *node = calloc(1, sizeof(t_list));
	node->data = strdup(" ,ca marche !");
	node->next = NULL;
	void *data = (void *)strdup("ok");
	printf("node ptr : %p\n", &node);
	printf("data ptr : %p\n", data);
	ft_list_push_front(&node, data); 
	void *data2 = (void *)strdup("test");
	ft_list_push_front(&node, data2); 
	t_list *head = node;
	while (node)
	{
		printf("%s\n", (char *)node->data);
		node = node->next;
	}

	extern int ft_list_size(t_list *begin_list);
	printf("nb elem : %d\n", ft_list_size(head)); //expected size : 3
	void *data3 = (void *)strdup("un");
	ft_list_push_front(&head, data3); 
	printf("nb elem : %d\n", ft_list_size(head)); //expected size : 3
}
