#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *insert(struct TreeNode *root, int value)
{
    if (root == NULL) {
        struct TreeNode *node = malloc(sizeof(struct TreeNode));
        node->value = value;
        node->left = node->right = NULL;
        return node;
    }
    if (value < root->value)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}

void inorder(struct TreeNode *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->value);
    inorder(root->right);
}

int main(void)
{
    struct TreeNode *root = NULL;
    int values[] = {5, 3, 8, 1, 4, 7, 9};

    for (int i = 0; i < 7; i++)
        root = insert(root, values[i]);

    inorder(root);   /* prints sorted: 1 3 4 5 7 8 9 */
    printf("\n");

    return 0;
}