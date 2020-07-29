/*
 * Author: Derek Calzadillas
 * Purpose: To demonstrate knowledge of linked lists
 */
#ifndef __func_h__
#define __func_h__

struct Stack
{
  int size;
  int top;
  int *s;
};

void display(struct Stack);
void push(struct Stack *, int);
int pop(struct Stack *);
int stackTop(struct Stack);
int isEmpty(struct Stack);
int isFull(struct Stack);
int peek(struct Stack, int);
int reprompt(int);
int tryagain();
int menuloop();
void displayMenu(struct Stack);
void isFullMenu(struct Stack);
void isEmptyMenu(struct Stack);
void popMenu(struct Stack *);
void pushMenu(struct Stack *);
void stackTopMenu(struct Stack);
void peekMenu(struct Stack);

#endif
