#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "func.h"

int main()
{

    //welcome to this prog
    struct Stack st;
    int input, ret;
    printf("\nWelcome to Fun Fun Stack Arrays. Demonstrating Knowledge of Stack Arrays.\n");
    printf("To start, let's create a stack array.\n");

    //prompt user
    printf("\nEnter max size of the stack: ");
    ret = scanf("%d", &st.size);
    if (st.size < 1 || st.size > INT_MAX || ret != 1)
    {
        st.size = reprompt(1); //flag#1 for sizes
    }
    st.s = (int *)malloc(st.size * sizeof(int));
    st.top = -1;
    printf("Enter an integer for each element of stack.\n");
    for (int i = 0; i < st.size; i++)
    {
        printf("Please enter an integer: ");
        ret = scanf("%d", &input);
        if (ret != 1 || input > INT_MAX)
        {
            input = reprompt(2); //2 flag for int only
        }
        push(&st, input);
        printf("Pushed %d to the top of the stack.\n", input);
    }

    printf("Final stack: ");
    display(st);

    //prompt user for what they would like to do with the linked list
    do
    {
        printf("\nWhat Do You Want to Do with the Stack Array?\n");
        printf("1.  Display\n");
        printf("2.  Check if Full.\n");
        printf("3.  Check if Empty\n");
        printf("4.  Pop an item off the stack\n");
        printf("5.  Push an item on the stack\n");
        printf("6.  Peek at the top of the stack\n");
        printf("7.  Peek under the stack\n");
        printf("8.  Exit Program.\n");
        printf("\nEnter your choice: ");
        ret = scanf("%d", &input);
        if (ret != 1 || input > 8 || input < 1)
        {
            input = reprompt(5); //flag#5 for 1-8 choices
        }
        switch (input)
        {
        case 1:
            printf("Display");
            displayMenu(st);
            break;
        case 2:
            printf("Is Full?");
            isFullMenu(st);
            break;
        case 3:
            printf("Is Empty?");
            isEmptyMenu(st);
            break;
        case 4:
            printf("Pop an item Off");
            popMenu(&st);
            break;
        case 5:
            printf("Push Onto");
            pushMenu(&st);
            break;
        case 6:
            printf("Peek at the Top");
            stackTopMenu(st);
            break;
        case 7:
            printf("Peek Under");
            peekMenu(st);
            break;
        case 8:
            printf("Exiting Program...\n");
            exit(0);
            break;
        default:
            printf("Invalid option.\n");
        }
    } while (input != 8);
    exit(0);
}
