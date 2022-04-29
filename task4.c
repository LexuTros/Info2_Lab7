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

void print_array(int input[], int size) {
	printf("[");
	for (int i = 0; i < size - 1; i++) {
		printf("%d, ", input[i]);
	}
	printf("%d]\n", input[size - 1]);
}

int stack_possibility(int In[], int Out[], int size){
    int j = 0;
    Stack* S = create(size);

    for (int i = 0; i < size; i++)
    {
        while (is_empty(S) || peek(S) != Out[i])
        {
            if (j >= size)
            {
                return 0; // impossible
            }
            push(S, In[j]);
            j++;
        }
        pop(S);
    }
    delete(S);
    return 1; // possible
}

int main() {
    int in1[] = {1, 2, 3, 4, 5};
    int out1[] = {4, 5, 3, 2, 1};
    int size_out1 = sizeof(out1) / sizeof(out1[0]);
    int result1 = stack_possibility(in1, out1, size_out1);
    printf("Result for first two arrays: %d\n", result1);
    int in2[] = {1, 2, 3, 4, 5};
    int out2[] = {4, 3, 5, 1, 2};
    int size_out2 = sizeof(out2) / sizeof(out2[0]);
    int result2 = stack_possibility(in2, out2, size_out2);
    printf("Result for second two arrays: %d\n", result2);

    return 0;
}
