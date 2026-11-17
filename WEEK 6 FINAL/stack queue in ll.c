#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("Empty\n");
        return;
    }
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// --- STACK OPERATIONS (LIFO) ---
void push(struct Node** top, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
    printf("Pushed %d to Stack.\n", data);
}

void pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow!\n");
        return;
    }
    struct Node* temp = *top;
    printf("Popped %d from Stack.\n", temp->data);
    *top = (*top)->next;
    free(temp);
}

// --- QUEUE OPERATIONS (FIFO) ---
void enqueue(struct Node** front, struct Node** rear, int data) {
    struct Node* newNode = createNode(data);
    if (*rear == NULL) {
        *front = *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
    printf("Enqueued %d to Queue.\n", data);
}

void dequeue(struct Node** front, struct Node** rear) {
    if (*front == NULL) {
        printf("Queue Underflow!\n");
        return;
    }
    struct Node* temp = *front;
    printf("Dequeued %d from Queue.\n", temp->data);
    *front = (*front)->next;
    if (*front == NULL) {
        *rear = NULL;
    }
    free(temp);
}

int main() {
    printf("DEETHYA DECHAMMA M V//17-11-26\n");
    struct Node* stackTop = NULL;
    struct Node *queueFront = NULL, *queueRear = NULL;

    printf("--- STACK SIMULATION ---\n");
    push(&stackTop, 10);
    push(&stackTop, 20);
    push(&stackTop, 30);
    printf("Current Stack: ");
    display(stackTop);
    pop(&stackTop);
    printf("Stack after Pop: ");
    display(stackTop);

    printf("\n--- QUEUE SIMULATION ---\n");
    enqueue(&queueFront, &queueRear, 100);
    enqueue(&queueFront, &queueRear, 200);
    enqueue(&queueFront, &queueRear, 300);
    printf("Current Queue: ");
    display(queueFront);
    dequeue(&queueFront, &queueRear);
    printf("Queue after Dequeue: ");
    display(queueFront);

    return 0;
}
