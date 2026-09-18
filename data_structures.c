#include <stdio.h>
#include <stdlib.h>

// struct TreeNode {
//     int value;
//     struct TreeNode *left;
//     struct TreeNode *right;
// };

// struct TreeNode *insert(struct TreeNode *root, int value)
// {
//     if (root == NULL) {
//         struct TreeNode *node = malloc(sizeof(struct TreeNode));
//         node->value = value;
//         node->left = node->right = NULL;
//         return node;
//     }
//     if (value < root->value)
//         root->left = insert(root->left, value);
//     else
//         root->right = insert(root->right, value);
//     return root;
// }

// void inorder(struct TreeNode *root)
// {
//     if (root == NULL)
//         return;
//     inorder(root->left);
//     printf("%d ", root->value);
//     inorder(root->right);
// }

// int main(void)
// {
//     struct TreeNode *root = NULL;
//     int values[] = {5, 3, 8, 1, 4, 7, 9};

//     for (int i = 0; i < 7; i++)
//         root = insert(root, values[i]);

//     inorder(root);   /* prints sorted: 1 3 4 5 7 8 9 */
//     printf("\n");

//     return 0;
// }

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
    return new_node;        
}

void print_list(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
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

    print_list(head);  

    free_list(head);

    return 0;
}