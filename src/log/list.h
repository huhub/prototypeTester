/*
 * Software Development Kit for Fisilink
 * @file: list.h
 * @description:
 * @note: Copyright (C) 2020 
 *
 * You should have received a copy of the Fisilink License
 * along with this program; if not, write to Fisilink
 */


#ifndef __LOG_LIST_H_
#define __LOG_LIST_H_

typedef struct list_node {
    void *data;
    struct list_node *next;
} list_node;

/* linked list */
list_node* list_create(void *data);
void list_destroy(list_node **list);
list_node* list_insert_after(list_node *node, void *data);
list_node* list_insert_beginning(list_node *list, void *data);
list_node* list_insert_end(list_node *list, void *data);
void list_remove(list_node **list, list_node *node);
void list_remove_by_data(list_node **list, void *data);
list_node* list_find_node(list_node *list, list_node *node);
list_node* list_find_by_data(list_node *list, void *data);
list_node* list_find(list_node *list, int(*func)(list_node*,void*), void *data);

#endif /*!_LIST_H_*/

