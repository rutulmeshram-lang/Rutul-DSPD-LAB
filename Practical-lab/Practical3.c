//3.Design, Develop and Implement a menu driven Program in C for the following operations on QUEUE of Characters (Array Implementation of Queue with maximum size MAX)
#include <stdio.h>
#include <stdlib.h>
#define MAX 5
char queue[MAX];
int front = -1, rear = -1;
void insert() {
    char item;
    if (rear == MAX - 1) {
        printf("\nQueue Overflow! Cannot insert element.\n");
        return;
    }
    printf("Enter a character to insert: ");
    scanf(" %c", &item);
    if (front == -1)
        front = 0;
    queue[++rear] = item;
    printf("Inserted '%c' into the queue.\n", item);
}
void delete() {
    if (front == -1 || front > rear) {
        printf("\nQueue Underflow! Cannot delete element.\n");
        return;
    }
    printf("Deleted '%c' from the queue.\n", queue[front]);
    front++;
    if (front > rear)  
        front = rear = -1;
}
void display() {
    if (front == -1) {
        printf("\nQueue is Empty.\n");
        return;
    }
    printf("\nQueue elements: ");
    for (int i = front; i <= rear; i++)
        printf("%c ", queue[i]);
    printf("\n");
}
int main() {
    int choice;
    printf("QUEUE OPERATIONS (Array Implementation)\n");
    while (1) {
        printf("\n");
        printf("1. Insert an Element\n");
        printf("2. Delete an Element\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
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
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}