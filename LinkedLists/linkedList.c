#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node* next;
};

void printLinkedList(struct node* head);
void printLinkedListArrowNotation(struct node* head);

int main () {

    printf("==========================================\n");
    struct node* head; // node pointer to head of linked list
    struct node n1 = {1, NULL}; // node n1
    struct node n2 = {2, NULL}; // node n2
    struct node n3 = {3, NULL}; // node n3
    head = &n1; // head pointer is assigned to the address of n1
    n1.next = &n2; 
    n2.next = &n3;
    printLinkedListArrowNotation(head);
    printf("==========================================\n");
    return 0;
}

void printLinkedList(struct node* head) {
    struct node* curr = head;
    printf("[ ");
    while((*curr).next != NULL) {
        printf("%d, ", (*curr).value);
        curr = (*curr).next;
    }
    printf("%d ]\n", (*curr).value);
}

void printLinkedListArrowNotation(struct node* head) {
    struct node* curr = head;
    while(curr->next != NULL) {
        printf("[%d]->", curr->value);
        curr = curr->next;
    }
    printf("[%d]\n", curr->value);
}

