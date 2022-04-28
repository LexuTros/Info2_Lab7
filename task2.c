/****************************************************************************
 * University of Zurich, Informatics II, Spring Semester 2022               *
 * Exercise 7 - Task 2                                                      *
 *                                                                          *
 * @author LexuTros                                                         *
 ****************************************************************************/
# include <stdio.h>	
# include <stdlib.h>

#define ERROR_VALUE -1


typedef struct Stack {  
	unsigned int capacity; // positive int (with 0)
	int* items; // points to first elemtent of array
  	int top; // idx of first free element of stack
} Stack;

Stack* create(unsigned int cap){
	Stack* S = malloc(sizeof(Stack));
	S->items = malloc(sizeof(int)*cap);
	S->capacity = cap;
	S->top = 0;
	return S;
}

void delete(Stack* S){
	free(S->items);
	free(S);
}

int is_empty(Stack* S){
	if(S->top == 0) {return 1;}
	else {return 0;}
}

int is_full(Stack* S){
	if(S->top == S->capacity) {return 1;}
	else {return 0;}
}

int get_capacity(Stack* S){
	return S->capacity;
}

int num_items(Stack* S){
	return S->top;
}

void push(Stack* S, int x){
	if(is_full(S))
	{
		printf("Error: Can't push the stack is allready Full\n");
	}
	else
	{
	S->items[S->top] = x;
	S->top++;
	}
}

int pop(Stack* S){
	if (is_empty(S))
	{	
		printf("Error: Can't pop, the stack is empty\n");
		return ERROR_VALUE;
	}
	else
	{
		S->top--;
		return S->items[S->top];
	}
}

int peek(Stack* S){
	if (is_empty(S))
	{
		printf("Error: Can't peek an empty stack\n");
		return ERROR_VALUE;
	}
	else
	{
		return S->items[S->top-1];
	}
}

void print(Stack* S){
	if (is_empty(S))
	{
		printf("The stack is empty\n");
	}
	else
	{
		printf("Stack:\n");
		for (int i = S->top-1; i >= 0; i--)
		{
			printf("%d\n", S->items[i]);
		}
	}
}

int is_equal(Stack* S1, Stack* S2){
	if (S1->top != S2->top)
	{
		return 0;
	}
	else
	{
		for (int i = 0; i < S1->top; i++)
		{
			if (S1->items[i] != S2->items[i])
			{
				return 0;
			}
		}
		return 1;
	}
}

void reverse(Stack* S){
	int A[S->capacity];
	int temp = S->top; // idx of top at beginning

	if (is_empty(S)) {return;}

	for (int i = 0; is_empty(S) == 0; i++)
	{
		A[i] = pop(S);
	}
	for (int i = 0; i < temp; i++)
	{
		push(S, A[i]);
	}	
}

int main() {
	Stack* s1 = create(6);
	Stack* s2 = create(6);
	push(s1, 1);
	push(s1, 3);
	push(s1, 5);
	push(s1, 7);
	push(s1, 42);
	push(s1, 17);
	print(s1);
	print(s2);
	printf("Check whether s1 is full: %d\n", is_full(s1));
	printf("Check whether s2 is full: %d\n", is_full(s2));
	printf("Number of elements in s1: %d\n", num_items(s1));
	printf("Number of elements in s2: %d\n", num_items(s2));
	printf("Overflow test... ");
	push(s1, 99);
	printf("Element popped from s1: %d\n", pop(s1));
	printf("Element popped from s1: %d\n", pop(s1));
	printf("Element peeked from s1: %d\n", peek(s1));
	for (int i = 0; i < 4; i++) {
		push(s2, i + i + 1);
	}
	print(s1);
	print(s2);
	printf("Comparison of s1 with s2: %d\n", is_equal(s1, s2));
	printf("Element popped from s2: %d\n", pop(s2));
	printf("Comparison of s1 with s2: %d\n", is_equal(s1, s2));
	for (int i = 0; i < 4; i++) {
		pop(s1);
	}
	print(s1);
	print(s2);
	printf("Check whether s1 is empty: %d\n", is_empty(s1));
	printf("Check whether s2 is empty: %d\n", is_empty(s2));
	printf("Underflow test... ");
	pop(s1);
	printf("Underflow test... ");
	peek(s1);
	push(s2, 9);
	push(s2, 8);
	push(s2, 2);
	print(s2);
	reverse(s2);
	print(s2);
	reverse(s2);
	print(s2);
	reverse(s2);
	print(s2);
	delete(s1);
	delete(s2);

  return 0;
}
