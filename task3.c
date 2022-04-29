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


void get_span(int data[], int num_data, int* spans){
	Stack* S = create(num_data);
	int span = 1;

	for (int i = 0; i < num_data; i++)
	{
		if (i>0)
		{
			if (data[i] >= data[i-1])
			{
				span++;
				while (!is_empty(S) && data[i] >= data[peek(S)])
				{
					span = span + spans[pop(S)];
				}
			}
			else
			{
				push(S, i-1);
				span = 1;
			}
		}
		spans[i] = span;
	}
}

void print_Array(int input[], int size) {
	printf("[");
	for (int i = 0; i < size - 1; i++) {
		printf("%d, ", input[i]);
	}
	printf("%d]\n", input[size - 1]);
}

int main() {
	int A[5] = {6, 3, 4, 2, 7};
	int num_data = 5;
	int* spans = malloc(sizeof(int)*num_data);

	get_span(A, num_data, spans);
	print_Array(spans, num_data);

  return 0;
}
