/*Problem: Create and Traverse Singly Linked List

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the result

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

int main(){
    int n,i=0,num;
    scanf("%d", &n);
    Node* head=(Node* )malloc(sizeof(Node));
    scanf("%d", &num);
    head->data=num;
    head->next=NULL;
    Node* previous=head;

    while(i<n-1){
    Node* newnode=(Node* )malloc(sizeof(Node));
    scanf("%d", &num);
    newnode->data=num;
    newnode->next=NULL;
    previous->next=newnode;
    previous=newnode;
    i++;
    }
    
    Node* temp=head;

    while(temp!=NULL){
        printf("%d ", temp->data);
        temp=temp->next;
    }

    return 0;
}