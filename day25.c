/*Problem: Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of nodes)
- Second line: n space-separated integers (linked list elements)
- Third line: integer key (element to be counted)

Output:
- Print the number of times the key appears in the linked list

Example:
Input:
6
10 20 30 20 40 20
20

Output:
3

Explanation:
Traverse the linked list from head to end. Each time a node's 
data matches the given key, increment a counter. After traversal, print the final count.*/

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

int countNode(struct Node* head, int num){

    if(head == NULL) return 0;

    struct Node* temp = head;
    int count;

    while(temp->next!= NULL){

        if(temp->data == num){
            count++;
        }

        temp = temp->next;
    }

    return count;
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
    int count=countNode(list1, m);
    printf("%d",count);
    
    return 0;
}