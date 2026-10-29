#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *push(struct Node *head, int value)
{
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = head;
    return new_node;   /* new node becomes the new head */
}

void print_list(struct Node *head)
{
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void free_list(struct Node *head)
{
    struct Node *tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main(void)
{
    struct Node *head = NULL;
    head = push(head, 3);
    head = push(head, 2);
    head = push(head, 1);

    print_list(head);   /* 1 -> 2 -> 3 -> NULL */

    free_list(head);
    return 0;
}