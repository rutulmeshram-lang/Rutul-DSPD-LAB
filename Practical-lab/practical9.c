//9	Assume that you have a seven-slot closed hash table (the slots are numbered o through 6) Write program  to final hash table that would result if you used the hash function h(k) - k mod 7.
#include <stdio.h>
#define SIZE 7 
int hash(int key) {
    return key % SIZE;
}
void insert(int hashTable[], int key) {
    int index = hash(key);
    int originalIndex = index;
    int i = 0;
    while (hashTable[index] != -1) {
        index = (originalIndex + ++i) % SIZE;
        if (index == originalIndex) {
            printf("Hash table is full! Cannot insert %d\n", key);
            return;
        }
    }
    hashTable[index] = key;
    printf("Inserted %d at index %d\n", key, index);
}
void display(int hashTable[]) {
    printf("\nFinal Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != -1)
            printf("Slot %d --> %d\n", i, hashTable[i]);
        else
            printf("Slot %d --> Empty\n", i);
    }
}
int main() {
    int hashTable[SIZE];
    int n, key;
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
    printf("Enter number of elements to insert: ");
    scanf("%d", &n);
    printf("Enter %d keys:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(hashTable, key);
    }
    display(hashTable);
    return 0;
}
