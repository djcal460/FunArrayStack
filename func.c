#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "func.h"

extern struct stack st;

//just pass as local stack since we're not changing anything
void display(struct Stack st)
{
    //display from top of stack (end of array)
    for (int i = st.top; i >= 0; i--)
        printf("%d ", st.s[i]); //s ptr is pts to array and arrays are addr
    printf("\n");
}

//need a ptr because we are changing the stack
void push(struct Stack *st, int x)
{
    if (st->top == st->size - 1)
        printf("The Stack is Full");
    else
    {
        st->top++;          //increase top ptr
        st->s[st->top] = x; //add x to top of stack
    }
}

//need a ptr because we are changing the stack
int pop(struct Stack *st)
{
    int x = -1;
    if (st->top == -1)
        printf("The Stack is Empty");
    else
    {
        x = st->s[st->top]; // save top var
        st->top--;          //decrease top ptr
    }
    return x;
}

int stackTop(struct Stack st)
{
    if (st.top == -1)
        return -1;
    else
        return st.s[st.top];
}

int isEmpty(struct Stack st)
{
    if (st.top == -1)
        return 1;
    else
        return 0;
}

int isFull(struct Stack st)
{
    if (st.top == st.size - 1)
        return 1;
    else
        return 0;
}

//peek down into stack
int peek(struct Stack st, int pos)
{

    int x = -1;
    if (st.top - pos + 1 < 0) //from top peak down to pos
        printf("Invalid Position\n");
    else
        x = st.s[st.top - pos + 1];
    return x;
}

int reprompt(int flag)
{
    int fixin, input, ret = 0;
    if (flag == 1)
    { //check valid size
        while (ret != 1 || input > INT_MAX || input < 1)
        {
            printf("Enter a valid size: ");
            while ((fixin = getchar()) != EOF && fixin != '\n')
                ; // fix stdin
            fflush(stdin);
            ret = scanf("%d", &input);
        }
    }
    else if (flag == 2)
    { // check valid int
        while (ret != 1 || input > INT_MAX || input < INT_MIN)
        {
            printf("Enter a valid integer: ");
            while ((fixin = getchar()) != EOF && fixin != '\n')
                ; // fix stdin
            fflush(stdin);
            ret = scanf("%d", &input);
        }
    }
    else if (flag == 4)
    { // check valid option 1-2
        while (ret != 1 || input > 2 || input < 1)
        {
            printf("Enter a valid option 1,2: ");
            while ((fixin = getchar()) != EOF && fixin != '\n')
                ; // fix stdin
            fflush(stdin);
            ret = scanf("%d", &input);
        }
    }
    else if (flag == 5)
    { // check valid option 1-8
        while (ret != 1 || input > 8 || input < 1)
        {
            printf("Enter a valid option 1-8: ");
            while ((fixin = getchar()) != EOF && fixin != '\n')
                ; // fix stdin
            fflush(stdin);
            ret = scanf("%d", &input);
        }
    }
    return input;
}

int tryagain()
{
    int prompt, ret;
    printf("Press [Any Key][Enter] to Repeat or [1] to Return to Menu: ");
    ret = scanf("%d", &prompt);
    if (prompt != 1 || ret != 1)
        return 0;
    return 1; //if 1, continue loop
}

int menuloop()
{
    int prompt, ret;
    printf("Press [Any Key][Enter] for New Menu Item or [1] to Exit Program: ");
    ret = scanf("%d", &prompt);
    if (prompt != 1 || ret != 1)
        return 0;
    return 1; //if 1, continue loop
}
