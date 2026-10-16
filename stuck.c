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