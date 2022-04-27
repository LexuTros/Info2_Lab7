/****************************************************************************
 * University of Zurich, Informatics II, Spring Semester 2022               *
 * Exercise 7 - Task 2                                                      *
 *                                                                          *
 * @author LexuTros                                                         *
 ****************************************************************************/
# include <stdio.h>	
# include <stdlib.h>


typedef struct Stack {  
	unsigned int capacity; // positive int (with 0)
	int* items; 
  int top; // idx of first free element of stack
} Stack;

Stack* create(unsigned int cap){
	Stack* S;
	S = malloc(sizeof(Stack));
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



int main() {
	//TODO: your implementation
  return 0;
}
