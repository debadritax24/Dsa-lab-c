//! write a program in c to implement stack and queue using array//
 

#include <stdio.h>
#define MAX 5
int stack[MAX];
int top = -1;
void push()
{
    int item;
    if(top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        printf("Enter element: ");
        scanf("%d", &item);

        top++;
        stack[top] = item;
        printf("Element inserted successfully\n");
    }
}
void pop()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("Deleted element = %d\n", stack[top]);
        top--;
    }
}
void display()
{
    int i;

    if(top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements are:\n");

        for(i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}
int main()
{
    int choice;
    do
    {
        printf("\n1. PUSH");
        printf("\n2. POP");
        printf("\n3. DISPLAY");
        printf("\n4. EXIT");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: push();
                    break;

            case 2: pop();
                    break;

            case 3: display();
                    break;

            case 4: printf("Exiting...");
                    break;

            default: printf("Invalid choice");
        }

    } while(choice != 4);
    return 0;
}
