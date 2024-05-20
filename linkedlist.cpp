#include <stdio.h>
#include <stdlib.h>

struct Node {
	int value;
	struct Node *next;
} *head = NULL, *tail = NULL;

struct Node* createNode(int value) {
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->value = value;
	newNode->next = NULL;
	return newNode;
}

void pushHead(int value) {
	Node* temp = createNode(value);
	if(head == NULL) {
		head = tail = temp;
		return;
	}
	
	temp->next = head;
	head = temp;	
}

void pushTail(int value) {
	Node* temp = createNode(value);
	if(head == NULL) {
		head = tail = temp;
		return;
	}
	
	tail->next = temp;
	tail = temp;
}

void deleteHead() {
	if(head == NULL) {
		return;
	}
	
	Node* temp = head;
	head = head->next;
	temp = NULL;
	free(temp);
}

void deleteTail() {
	if(head == NULL) {
		return;
	}
	
	Node* temp = head;
	
	while(temp->next->next != NULL) {
		temp = temp->next;
	}
	
	tail = temp;
	temp->next = NULL;
	free(temp->next);
}

void deleteNode() {
	
}

void searchNode(int value) {
	if(head == NULL) {
		printf("\nLinked list is empty");
		return;
	}
	
	Node* curr = head;
	int index = 0;
	
	while(curr != NULL) {
		if(curr->value == value) {
			printf("\nValue is at index %d", index);
			return;
		}
		index++;
		curr = curr->next;
	}
	
	printf("\nValue was not found");
}

void displayList() {
	Node* curr = head;
	
	if(head == NULL) {
		printf("Linked list is empty");
	}
	
	while(curr != NULL) {
		printf("%d -> ", curr->value);
		curr = curr->next;
	}
}

int main() {
	pushHead(10);
	pushHead(9);
	pushTail(11);
	displayList();
	searchNode(10);
	return 0;
}
