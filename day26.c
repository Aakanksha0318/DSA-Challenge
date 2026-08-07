/*Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the linked list elements in forward order, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50

Explanation:
Each node has data, next, prev. Insert nodes sequentially, traverse from head using next pointer.*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL) printf(" ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, value;

struct Node *list1 = NULL;
struct Node *tail = NULL;
struct Node *temp = NULL;

    scanf("%d", &n);
for (int i = 0; i < n; i++) {
    scanf("%d", &value);
    struct Node* newNode = createNode(value);

    if (list1 == NULL) {
        list1 = newNode;
        tail = newNode;
        temp = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
        newNode->prev = temp;
        temp = newNode;
    }
}

    printList(list1);
    
    return 0;
}