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