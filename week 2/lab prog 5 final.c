#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void insert()
{
    int x;

    if ((rear + 1) % MAX == front)
    {
        printf("Queue Overflow\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &x);

    if (front == -1)
        front = 0;

    rear = (rear + 1) % MAX;
    queue[rear] = x;

    printf("Inserted successfully\n");
}

void delete()
{
    if (front == -1)
    {
        printf("Queue Empty\n");
        return;
    }

    printf("Deleted: %d\n", queue[front]);

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("Queue Empty\n");
        return;
    }

    printf("Queue: ");

    i = front;

    while (1)
    {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert();
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
