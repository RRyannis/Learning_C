# Data Structures & Algorithms in C — Reference Guide

A note before diving in: "all data structures and algorithms" is genuinely
book-sized territory, not a snippet. This covers the fundamentals with
working examples. Several of these (linked lists, stacks/queues built on
them, trees) lean on pointers, structs, and `malloc` — topics still ahead
of you in K&R. Treat this as a preview/reference to come back to once
you've covered those chapters, not something to fully absorb right now.

Each section is a **standalone, independently compilable snippet** — copy
one at a time into its own file to run it (they each have their own `main`).

---

## 1. Array (the data structure you already know)

The foundation everything else builds on — a fixed-size, contiguous block
of same-typed elements, accessed by index in O(1).

```c
#include <stdio.h>

int main(void)
{
    int arr[5] = {10, 20, 30, 40, 50};

    for (int i = 0; i < 5; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
```

Strength: O(1) random access. Weakness: fixed size, O(n) insertion/deletion
in the middle (everything after has to shift).

---

## 2. Linked List (requires structs + pointers + malloc — preview only)

A chain of nodes, each holding a value and a pointer to the next node.
Unlike an array, it can grow dynamically and doesn't need contiguous memory.

```c
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
```

Strength: O(1) insertion at the front, dynamic size. Weakness: O(n) access
to a specific element (no random access), extra memory per node for the
pointer, and every `malloc` needs a matching `free` (or you leak memory).

---

## 3. Stack (Last In, First Out) — array-based version

A stack only allows adding/removing from one end ("the top"). Useful for
undo systems, expression parsing, function call tracking (this is
literally how your program's own call stack works during recursion).

```c
#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value)
{
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = value;
}

int pop(void)
{
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

int main(void)
{
    push(10);
    push(20);
    push(30);

    printf("%d\n", pop());   /* 30 */
    printf("%d\n", pop());   /* 20 */

    return 0;
}
```

---

## 4. Queue (First In, First Out) — array-based version

Opposite discipline from a stack: add at the back, remove from the front.
Used for task scheduling, breadth-first search, buffering.

```c
#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = -1, count = 0;

void enqueue(int value)
{
    if (count == MAX) {
        printf("Queue full\n");
        return;
    }
    rear = (rear + 1) % MAX;
    queue[rear] = value;
    count++;
}

int dequeue(void)
{
    if (count == 0) {
        printf("Queue empty\n");
        return -1;
    }
    int value = queue[front];
    front = (front + 1) % MAX;
    count--;
    return value;
}

int main(void)
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("%d\n", dequeue());   /* 10 */
    printf("%d\n", dequeue());   /* 20 */

    return 0;
}
```

---

## 5. Binary Search Tree (requires structs + pointers + malloc — preview only)

Each node has at most two children; left subtree holds smaller values,
right subtree holds larger ones. Enables O(log n) search/insert on
average (O(n) worst case if the tree becomes unbalanced).

```c
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
```

Note: this leaks memory (no `free` for the tree) — fine for a learning
example, not for real code; freeing a tree needs a recursive post-order
traversal.

---

## 6. Sorting — Bubble Sort (simple, O(n²))

Repeatedly swaps adjacent out-of-order elements until the array is sorted.
Not efficient, but the easiest sort to understand.

```c
#include <stdio.h>

void bubble_sort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(void)
{
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = 6;

    bubble_sort(arr, n);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
```

---

## 7. Sorting — Quicksort (efficient, average O(n log n))

Picks a "pivot," partitions the array so smaller values go left and
larger go right, then recursively sorts each side. This is the algorithm
`qsort()` in `<stdlib.h>` typically implements under the hood.

```c
#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort(int arr[], int low, int high)
{
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main(void)
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = 6;

    quicksort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
```

---

## 8. Searching — Binary Search (O(log n), requires a sorted array)

Repeatedly halves the search range by comparing the target to the middle
element.

```c
#include <stdio.h>

int binary_search(int arr[], int n, int target)
{
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;   /* not found */
}

int main(void)
{
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = 6;

    printf("index: %d\n", binary_search(arr, n, 7));   /* 3 */
    printf("index: %d\n", binary_search(arr, n, 4));   /* -1 */

    return 0;
}
```

---

## Suggested order to actually learn these, given where you are

1. **Array** — already comfortable.
2. **Stack / Queue (array-based)** — approachable now, no pointers required.
3. **Bubble sort, Binary search** — approachable now, just loops + arrays.
4. **Quicksort** — approachable once recursion feels solid (you've already
   done recursive `power()`).
5. **Linked list** — once you're through K&R's pointers and structs
   chapters, and comfortable with `malloc`/`free`.
6. **Binary search tree** — after linked lists click, since it reuses the
   same node/pointer/malloc pattern, just with two links instead of one.

Good next daily-commit candidates from this list right now: stack, queue,
bubble sort, or binary search — all buildable with what you already know.
