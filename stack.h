#include <stdio.h>
#define ElementType int
#define STACK_CAPACITY 1024

typedef struct _STACK{
	int top;
	ElementType stack[STACK_CAPACITY];
} STACK;

int isEmpty(STACK* s){
	return s->top == -1;
}

int isFull(STACK* s){
	return s->top == STACK_CAPACITY - 1;
}

ElementType Top(STACK* s){
	if(isEmpty(s)){
		printf("Error: Stack is empty!\n");
		return '\0'; //return NULL
	}

	return s->stack[s->top];
}

void Pop(STACK* s){
	if(isEmpty(s)){
		printf("Error: Stack is empty!\n");
		return;
	}

	(s->top)--;
}

void Push(STACK* s, ElementType data){
	if(isFull(s)){
		printf("Error: Stack is Full!\n");
		return;
	}

	s->stack[++(s->top)] = data;
}
