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

// #include <stdio.h>
// #include <stdlib.h>

// struct Node {
//     int data;
//     struct Node *next;
// };

// struct Node *push(struct Node *head, int value)
// {
//     struct Node *new_node = malloc(sizeof(struct Node));
//     new_node->data = value;
//     new_node->next = head;   
//     return new_node;        
// }

// void print_list(struct Node *head)
// {
//     struct Node *current = head;
//     while (current != NULL) {
//         printf("%d -> ", current->data);
//         current = current->next;
//     }
//     printf("NULL\n");
// }

// void free_list(struct Node *head)
// {
//     struct Node *tmp;
//     while (head != NULL) {
//         tmp = head;
//         head = head->next;
//         free(tmp);
//     }
// }

// int main(void)
// {
//     struct Node *head = NULL;

//     head = push(head, 3);
//     head = push(head, 2);
//     head = push(head, 1);

//     print_list(head);  

//     free_list(head);

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10


struct AdjNode {
    int vertex;
    struct AdjNode *next;
};

struct Graph {
    struct AdjNode *adjLists[MAX_VERTICES];   
    int numVertices;
};

struct Graph *createGraph(int vertices)
{
    struct Graph *g = malloc(sizeof(struct Graph));
    g->numVertices = vertices;
    for (int i = 0; i < vertices; i++)
        g->adjLists[i] = NULL;   
    return g;
}

void addEdge(struct Graph *g, int src, int dest)
{
    
    struct AdjNode *newNode = malloc(sizeof(struct AdjNode));
    newNode->vertex = dest;
    newNode->next = g->adjLists[src];
    g->adjLists[src] = newNode;

    
    newNode = malloc(sizeof(struct AdjNode));
    newNode->vertex = src;
    newNode->next = g->adjLists[dest];
    g->adjLists[dest] = newNode;
}

void printGraph(struct Graph *g)
{
    for (int v = 0; v < g->numVertices; v++) {
        struct AdjNode *temp = g->adjLists[v];
        printf("Vertex %d: ", v);
        while (temp != NULL) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}


void bfs(struct Graph *g, int startVertex)
{
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    printf("BFS from %d: ", startVertex);
    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        struct AdjNode *temp = g->adjLists[current];
        while (temp != NULL) {
            if (!visited[temp->vertex]) {
                visited[temp->vertex] = 1;
                queue[rear++] = temp->vertex;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

void freeGraph(struct Graph *g)
{
    for (int v = 0; v < g->numVertices; v++) {
        struct AdjNode *temp = g->adjLists[v];
        while (temp != NULL) {
            struct AdjNode *toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(g);
}

int main(void)
{
    struct Graph *g = createGraph(5);

    addEdge(g, 0, 1);
    addEdge(g, 0, 4);
    addEdge(g, 1, 2);
    addEdge(g, 1, 3);
    addEdge(g, 1, 4);
    addEdge(g, 2, 3);
    addEdge(g, 3, 4);

    printGraph(g);
    bfs(g, 0);

    freeGraph(g);
    return 0;
}