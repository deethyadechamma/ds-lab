#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at the end
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to display the linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// 1. Sort the linked list (Ascending order)
void sortList(struct Node* head) {
    if (head == NULL) return;
    struct Node *i, *j;
    int temp;
    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

// 2. Reverse the linked list
void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

// 3. Concatenate two linked lists
struct Node* concatenateLists(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct Node* temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
    return head1;
}

int main() {
    printf("DEETHYA DECHAMMA M V//17-11-26\n");
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // Populate List 1
    insertEnd(&list1, 30);
    insertEnd(&list1, 10);
    insertEnd(&list1, 20);

    // Populate List 2
    insertEnd(&list2, 50);
    insertEnd(&list2, 40);

    printf("Original List 1: ");
    display(list1);

    sortList(list1);
    printf("Sorted List 1:   ");
    display(list1);

    reverseList(&list1);
    printf("Reversed List 1: ");
    display(list1);

    printf("List 2:          ");
    display(list2);

    list1 = concatenateLists(list1, list2);
    printf("Concatenated:    ");
    display(list1);

    return 0;
}
