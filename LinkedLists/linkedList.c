#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node* next;
};

void printLinkedList(struct node* head);

int main () {

    printf("==========================================\n");
    struct node* head; 
    struct node n1 = {1, NULL};
    struct node n2 = {2, NULL};
    struct node n3 = {3, NULL};
    head = &n1;
    n1.next = &n2;
    n2.next = &n3;
    printLinkedList(head);
    printf("==========================================\n");
    
    return 0;
}

void printLinkedList(struct node* head) {
    struct node* curr = head;
    printf("[ ");
    while(curr->next != NULL) {
        printf("%d, ", curr->value);
        curr = curr->next;
    }
    printf("%d ]\n", curr->value);
}