//2. Design, Develop and Implement a menu driven Program in C for the following operations on STACK of Integers (Array Implementation of Stack with maximum size MAX) 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
int stack[MAX];
int top = -1;
int isFull() {
    return top == MAX - 1;
}
int isEmpty() {
    return top == -1;
}
void push(int element) {
    if (isFull()) {
        printf("Stack Overflow! Cannot push %d\n", element);
        return;
    }
    stack[++top] = element;
    printf("%d pushed onto stack.\n", element);
}
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Cannot pop.\n");
        return -1;
    }
    int popped = stack[top--];
    printf("%d popped from stack.\n", popped);
    return popped;
}
void display() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Current Stack elements (top to bottom):\n");
    for (int i = top; i >= 0; i--)
        printf("%d\n", stack[i]);
}
void checkPalindrome() {
    char str[100];
    printf("Enter a string or number to check palindrome: ");
    scanf("%s", str);
    int len = strlen(str);
    top = -1; 
    for (int i = 0; i < len; i++)
        push(str[i]);
    int flag = 1;
    for (int i = 0; i < len; i++) {
        if (pop() != str[i]) {
            flag = 0;
            break;
        }
    }
    if (flag)
        printf("The given string/number is a Palindrome.\n");
    else
        printf("The given string/number is NOT a Palindrome.\n");
}
int main() {
    int choice, element;

    while (1) {
        printf("\n");
        printf("1. Push an Element onto Stack\n");
        printf("2. Pop an Element from Stack\n");
        printf("3. Check Palindrome using Stack\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &element);
                push(element);
                break;
            case 2:
                pop();
                break;
            case 3:
                checkPalindrome();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}