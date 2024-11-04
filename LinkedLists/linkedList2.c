#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int value;
    struct node* next;
};

struct MyLinkedList {
    struct node* head;
};

void printLinkedList(struct node* head);
void printLinkedListArrowNotation(struct node* head);
struct node* makeNode(int val);
struct MyLinkedList* myLinkedListCreate();
int myLinkedListGet(struct MyLinkedList* obj, int index);
void myLinkedListAddAtHead(struct MyLinkedList* obj, int val);
void myLinkedListAddAtTail(struct MyLinkedList* obj, int val);
void myLinkedListAddAtIndex(struct MyLinkedList* obj, int index, int val);
void myLinkedListDeleteAtIndex(struct MyLinkedList* obj, int index);
void myLinkedListFree(struct MyLinkedList* obj);
bool hasCycle(struct node *head);
struct node *detectCycle(struct node *head);

int main () {

    printf("==========================================\n");    
    // declare nodes and linkedList
    struct node* n1 = makeNode(1); // node n1
    struct node* n2 = makeNode(2); // node n2
    struct node* n3 = makeNode(3); // node n3
    struct node* n4 = makeNode(4); // node n4
    struct MyLinkedList* obj = myLinkedListCreate();
    if(!obj) { // check for NULL PTR
        printf("myLinkedListCreate() failed.\n");
        exit(1);
    }
    struct MyLinkedList* obj2 = myLinkedListCreate();
    if(!obj2) { // check for NULL PTR
        printf("myLinkedListCreate() failed.\n");
        exit(1);
    }
    // add at head with function
    int val = 0;
    myLinkedListAddAtHead(obj, val); 
    printLinkedListArrowNotation((*obj).head);
    obj->head->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    printLinkedListArrowNotation((*obj).head);
    // get value of node from an index
    int index = 0;
    int zeroIndexOfLinkedList = myLinkedListGet(obj, index);
    printf("zeroIndexOfLinkedList: %d\n", zeroIndexOfLinkedList);
    //add at head with function
    val = 6;
    myLinkedListAddAtHead(obj, val); 
    printLinkedListArrowNotation((*obj).head); 
    //add at tail
    myLinkedListAddAtTail(obj, 8);  
    printLinkedListArrowNotation((*obj).head); 
    myLinkedListAddAtTail(obj, 12);  
    printLinkedListArrowNotation((*obj).head); 
    // add at index
    myLinkedListAddAtIndex(obj, 3, 13);  
    printLinkedListArrowNotation((*obj).head); 
    myLinkedListAddAtIndex(obj, 6, 14);  
    printLinkedListArrowNotation((*obj).head); 
    myLinkedListDeleteAtIndex(obj, 6);
    printLinkedListArrowNotation((*obj).head); 
    myLinkedListDeleteAtIndex(obj, 2);
    printLinkedListArrowNotation((*obj).head); 
    myLinkedListDeleteAtIndex(obj, 0);
    printLinkedListArrowNotation((*obj).head); 
    myLinkedListAddAtIndex(obj, 7, 5);
    printLinkedListArrowNotation((*obj).head); 
    // look for cycle in obj linked list
    bool cycleInLinkedList = hasCycle((*obj).head);
    // print results of hasCycle() function
    if(cycleInLinkedList) {
        printf("The linked list has a cycle.\n");
    } else {
        printf("The linked list does not have a cycle.\n");
    }
    // create new nodes and linked list with a cycle
    struct node* n12 = makeNode(12); // node n1
    struct node* n22 = makeNode(22); // node n2
    struct node* n32 = makeNode(32); // node n3
    struct node* n42 = makeNode(42); // node n4
    obj2->head = n42;
    n42->next = n32;
    n32->next = n22;
    n22->next = n12;
    n12->next = n32;
    // look for cycle in obj2 linked list
    cycleInLinkedList = hasCycle((*obj2).head);
    // print results of hasCycle() function
    if(cycleInLinkedList) {
        printf("The linked list has a cycle.\n");
    } else {
        printf("The linked list does not have a cycle.\n");
    }
    printLinkedListArrowNotation((*obj2).head); 
    // search for the start of the cycle in the obj2 linked list 
    struct node* cycleFoundIndex = detectCycle((*obj2).head);
    printf("Cycle start found at node: %d\n", cycleFoundIndex->value);
    n12->next = NULL; // remove the cycle from the obj2 linked list
    printLinkedListArrowNotation((*obj2).head); 
    myLinkedListFree(obj);
    myLinkedListFree(obj2);
    printf("==========================================\n");
    return 0;
}

bool hasCycle(struct node* head) {
    if(!head) {
        return false;
    }
    struct node* fastPointer = head;
    struct node* slowPointer = head;

    bool moveBoth = false;
    while(fastPointer->next != NULL) {
        if(moveBoth) {
            slowPointer = slowPointer->next;
            moveBoth = false;
        } else {
            moveBoth = true;
        }
        fastPointer = fastPointer->next;
        if(fastPointer == slowPointer) {
            return true;
        }
    }
    return false;
}

struct node *detectCycle(struct node *head) {
    if(!head) {
        return NULL;
    }
    bool cycleDetected = hasCycle(head);
    if(!cycleDetected) {
        return NULL;
    }
    struct node* fastPointer = head;
    struct node* slowPointer = head;
    struct node* checkPointer = head; 
    bool cycleStartNotFound = true; // bool is not actually used logically in this function, just as a means to clarify what while loop is looking for. Alternative is `while(true){}`
    while(cycleStartNotFound) {
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next->next;
        if(slowPointer == checkPointer) {
            cycleStartNotFound = false; // bool variable is not actually used to break out of while loop, return statement below suffices
            return checkPointer;
        }
        if(slowPointer == fastPointer) {
            checkPointer = checkPointer->next;
            slowPointer = checkPointer->next;
            fastPointer = checkPointer->next;
        }
    }
    return NULL;
}

struct node* makeNode(int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode) {
        newNode->value = val;
        newNode->next = NULL;
        return newNode;
    }
    printf("makeNode() function failed\n");
    return NULL;
}

struct MyLinkedList* myLinkedListCreate() {
    struct MyLinkedList* myLinkedList = (struct MyLinkedList*)malloc(sizeof(struct MyLinkedList));
    if(myLinkedList) {
        myLinkedList->head = NULL;
        return myLinkedList;
    }
    printf("myLinkedListCreate() function failed\n");
    return NULL;
}

int myLinkedListGet(struct MyLinkedList* obj, int index) {
    if(!obj || index < 0) { // check for a NULL pointer or an invalid index being passed in 
        printf("NULL obj or invalid index passed into myLinkedListGet() function\n");
        return -1;
    }
    struct node* curr = obj->head;
    for(int i = 0; i < index; i++) {
        if(curr->next == NULL) {
            printf("index passed to myLinkedListGet() function was not valid\n");
            return -1;
        }
        curr = curr->next;
    }
    return curr->value;
}

void myLinkedListAddAtHead(struct MyLinkedList* obj, int val) {
    if(!obj) {
        printf("NULL obj passed into myLinkedListAddAtHead() function\n");
        return;
    }
    struct node* currHead = obj->head;
    struct node* newNode = makeNode(val);
    if(!newNode) {
        printf("makeNode() function failed in myLinkedListAddAtHead() function\n");
        return;
    }
    newNode->next = currHead;
    obj->head = newNode;
}

void myLinkedListAddAtTail(struct MyLinkedList* obj, int val) {
    struct node* curr = obj->head;
    struct node* newNode = makeNode(val);
    if(!newNode) {
        printf("makeNode() function failed in myLinkedListAddAtTail() function\n");
        return;
    }
    while(curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newNode;
}

void myLinkedListAddAtIndex(struct MyLinkedList* obj, int index, int val) {
    if(!obj || index < 0) { // check for a NULL pointer or an invalid index being passed in 
        printf("myLinkedListAddAtIndex() failed because of NULL obj pointer or invalid index.\n");
        return;
    }
    struct node* curr = obj->head;
    struct node* newNode = makeNode(val);
    if(!newNode) {
        printf("makeNode() function failed in myLinkedListAddAtIndex() function\n");
        return;
    }
    for(int i = 0; i < index-1; i++) {
        if(curr->next == NULL) {
            printf("myLinkedListAddAtIndex() failed because index parameter was out of range.\n");
            return;
        }
        curr = curr->next;
    }
    newNode->next = curr->next;
    curr->next = newNode;
}

void myLinkedListDeleteAtIndex(struct MyLinkedList* obj, int index) {
    if(!obj || index < 0) { // check for a NULL pointer or an invalid index being passed in 
        printf("myLinkedListDeleteAtIndex() failed because of NULL obj pointer or invalid index.\n");
        return;
    }
    struct node* curr = obj->head;
    for(int i = 0; i < index - 1; i++) {
        if(curr->next == NULL) {
            printf("myLinkedListDeleteAtIndex() failed because index parameter was out of range.\n");
            return;
        }
        curr = curr->next;
    }
    curr->next = curr->next->next;
}

void myLinkedListFreeHelper(struct node* head) {
    struct node* curr;
    while(head->next) {
        curr = head;
        head = head->next;
        free(curr);
        printLinkedListArrowNotation(head);
    }
    free(head);
    printf("[]\n");
}

void myLinkedListFree(struct MyLinkedList* obj) {
    myLinkedListFreeHelper(obj->head);
    free(obj);
}

void printLinkedListArrowNotation(struct node* head) {
    struct node* curr = head;
    int count = 0;
    while(curr->next != NULL && count < 25) {
        printf("[%d]->", curr->value);
        curr = curr->next;
        count++;
    }
    printf("[%d]\n", curr->value);
}

