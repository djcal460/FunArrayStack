/*
 * Author: Derek Calzadillas
 * Purpose: To demonstrate knowledge of linked lists
 */
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "func.h"

extern struct Stack st;

void displayMenu(struct Stack st)
{
    //display
    int ret, input, f = 0;
    while (!f)
    {
        printf("\nDisplay the stack array?\n");
        printf("Enter 1 for yes, 2 for no: ");
        ret = scanf("%d", &input);
        if (ret != 1 || input > 2 || input < 1)
        {
            input = reprompt(4); //4 valid option 1 or 2
        }
        display(st);
        f = tryagain();
    }
}
void isFullMenu(struct Stack st)
{
    //check if full
    int ret, input, f = 0;
    while (!f)
    {
        printf("\nCheck if stack array is full?\n");
        printf("Enter 1 for yes, 2 for no: ");
        ret = scanf("%d", &input);
        if (ret != 1 || input > 2 || input < 1)
        {
            input = reprompt(4); //4 valid option 1 or 2
        }
        int k = isFull(st);
        if (k == 0)
            printf("Stack is not full\n");
        else
            printf("Stack is full\n");
        f = tryagain();
    }
}
void isEmptyMenu(struct Stack st)
{
    //check if empty
    int ret, input, f = 0;
    while (!f)
    {
        printf("\nCheck if stack array is empty?\n");
        printf("Enter 1 for yes, 2 for no: ");
        ret = scanf("%d", &input);
        if (ret != 1 || input > 2 || input < 1)
        {
            input = reprompt(4); //4 valid option 1 or 2
        }
        if (!isFull(st))
        {
        }
        int k = isEmpty(st);
        if (k == 0)
            printf("Stack is not Empty\n");
        else
            printf("Stack is Empty\n");
        f = tryagain();
    }
}

void popMenu(struct Stack *st)
{

    int ret, input, f = 0;
    while (!f)
    {
        printf("\nWould you like to pop the top of the stack?\n");
        printf("Enter 1 for yes, 2 for no: ");
        ret = scanf("%d", &input);
        if (ret != 1 || input > 2 || input < 1)
        {
            input = reprompt(4); //4 valid option 1 or 2
        }
        if (!isEmpty((*st)))
        {
            int k = pop(st);
            printf("Popped: %d\n", k);
            display((*st));
        }
        else
        {
            printf("The stack array is empty. Nothing left to pop.\n");
            break;
        }
        f = tryagain();
    }
}
void pushMenu(struct Stack *st)
{

    int ret, input, f = 0;
    while (!f)
    {
        printf("\nWould you like to push to the top of the stack?\n");
        printf("Enter 1 for yes, 2 for no: ");
        ret = scanf("%d", &input);
        if (ret != 1 || input > 2 || input < 1)
        {
            input = reprompt(4); //Flag#4 option 1 or 2
        }
        printf("Enter an integer to push: ");
        ret = scanf("%d", &input);
        if (ret != 1 || input > INT_MAX || input < INT_MIN)
        {
            input = reprompt(2); //Flag#2 valid int
        }
        if (!isFull((*st)))
        {
            push(st, input);
            printf("Pushed: %d\n", input);
            display((*st));
        }
        else
        {
            printf("Stack is full. No more room to push.\n");
            break;
        }
        f = tryagain();
    }
}

void stackTopMenu(struct Stack st)
{

    int ret, input, f = 0;
    while (!f)
    {
        printf("\nWould you like to peak at the top of the stack?\n");
        printf("Enter 1 for yes, 2 for no: ");
        ret = scanf("%d", &input);
        if (ret != 1 || input > 2 || input < 1)
        {
            input = reprompt(4); //Flag#4 option 1 or 2
        }
        printf("%d is at the top of the stack.\n", stackTop(st));
        f = tryagain();
    }
}

void peekMenu(struct Stack st)
{

    int ret, input, look, f = 0;
    while (!f)
    {
        printf("\nWould you like to peak into stack?\n");
        printf("Enter 1 for yes, 2 for no: ");
        ret = scanf("%d", &input);
        if (ret != 1 || input > 2 || input < 1)
        {
            input = reprompt(4); //Flag#4 option 1 or 2
        }
        printf("Enter how far down you want to peek: ");
        ret = scanf("%d", &look);
        if (ret != 1 || look > INT_MAX || look < 0)
        {
            input = reprompt(1); //Flag#1 size
        }
        if (look > st.size)
        {
            printf("You are trying to peek beyond the floor of the stack.\n");
            printf("Try a smaller number.\n");
        }
        else
        {
            int p = peek(st, look);
            printf("Looking down %d, you can see stack item: %d\n", look, p);
        }

        f = tryagain();
    }
}
