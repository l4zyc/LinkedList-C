#include <stdlib.h>
#include <stdio.h>

struct Node {
    struct Node* next;
    int value;
} *head = NULL, *tail = NULL;

struct Node* newNode(int value) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->next = NULL;
    node->value = value;
    return node;
}

void pushHead(int value) {
    struct Node* node = newNode(value);
    if(head == NULL && tail == NULL) {
        head = tail = node;
        return;
    }

    node->next = head;
    head = node;   
}

void pushTail(int value) {
    struct Node* node = newNode(value);

    if(head == NULL && tail == NULL) {
        head = tail = node;
    }

    tail->next = node;
    tail = node;
}

void pushMid(int value) {
    struct Node* node = newNode(value);

    if(head == NULL && tail == NULL) {
        head = tail = node;
    } else if(value < head->value) {
        pushHead(value);
    } else if(value > tail->value) {
        pushTail(value);
    } else {
        struct Node* curr = head;
        
        while(curr->next != NULL && value > curr->next->value) {
            curr = curr->next;
        }

        node->next= curr->next;
        curr->next = node;
    }
}

void popHead() {
    if(head == NULL && tail == NULL) {
        printf("Linked List is empty\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);
    temp = NULL;
}

void popTail() {
    if(head == NULL && tail == NULL) {
        printf("Linked list is empty\n");
        return;
    }
 
    struct Node* temp = head;

    while(temp->next != tail) {
        temp = temp->next;
    }

    tail = temp;
    free(temp->next);
    temp->next = NULL;
}

void popMid(int target) {
    if(head == NULL && tail == NULL) {
        print("Linked list is empty\n");
        return;
    } else if(head->value == target) {
        popHead();
    } else if(tail->value == target) {
        popTail();
    } else {
        struct Node* curr = head;

        while(curr != tail && curr->next->value != target) {
            curr = curr->next;
        }

        struct Node* temp = curr->next;
        curr->next = curr->next->next;
        free(temp);
        temp = NULL;
    }
}

void displayList() {
    struct Node* curr = head;
    while(curr != NULL) {
        printf("%d -> ",curr->value);
        curr = curr->next;
    }

    printf("NULL");
}

int main() {
    pushHead(10);
    pushMid(9);
    pushTail(12);
    popHead();
    popTail();
    displayList();
    return 0;
}