/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 01:26:32 by darbib            #+#    #+#             */
/*   Updated: 2020/08/19 01:33:21 by darbib           ###   ########.fr       */
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
	while (node)
	{
		printf("%s\n", (char *)node->data);
		node = node->next;
	}
}
