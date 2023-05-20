#include "stdlib.h"
#include "stdio.h"


typedef struct Node {
  int value;
  struct Node* next;
} Node;

typedef struct Stack {
  int length;
  Node* head;
} Stack;

Stack createStack(){
  Stack stack = { .head = NULL, .length=0 };
  return stack;
}

void push(Stack* stack, int item){
  Node* elem = (Node*) malloc(sizeof(Node));
  Node* prev_head = stack->head;

  stack->length++;
  elem->value = item;
  elem->next = prev_head;

  stack->head = elem;
}

int pop(Stack* stack){

  Node* elem = stack->head;

  stack->head = elem->next;
  stack->length--;

  int value = elem->value;
  free(elem);

  return value;
}

void printStack(Stack* stack){
  printf("Stack of length %d\n", stack->length);
  Node *curr = stack->head;
  while(curr){
    printf("-> %d\n", curr->value);
    curr = curr->next;
  }
}

int main(){

  Stack stack = createStack();

  push(&stack, 1);
  push(&stack, 2);
  push(&stack, 3);
  printStack(&stack);

  printf("pop: %d\n", pop(&stack));
  printf("pop: %d\n", pop(&stack));
  printStack(&stack);

  return 0;
}
