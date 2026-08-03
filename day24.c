/* Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key

Output:
- Print the linked list elements after deletion, space-separated

Example:
Input:
5
10 20 30 40 50
30

Output:
10 20 40 50

Explanation:
Traverse list, find first node with key, remove it by adjusting previous node's next pointer. */

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

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL) printf(" ");
        head = head->next;
    }
    printf("\n");
}

struct Node* deleteNode(struct Node* head, int num){

    if(head == NULL) return NULL;

    if(head->data == num){
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* temp = head;

    while(temp->next != NULL){

        if(temp->next->data == num){
            struct Node* del = temp->next;
            temp->next = del->next;
            free(del);
            break;
        }

        temp = temp->next;
    }

    return head;
}

int main() {
    int n, m, value;

struct Node *list1 = NULL;
struct Node *tail = NULL;
    scanf("%d", &n);
for (int i = 0; i < n; i++) {
    scanf("%d", &value);
    struct Node* newNode = createNode(value);

    if (list1 == NULL) {
        list1 = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}
    scanf("%d", &m);
    struct Node* new_ll = deleteNode(list1, m);
    printList(new_ll);
    
    return 0;
}