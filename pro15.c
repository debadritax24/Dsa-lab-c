//! write a program in c to implement stack and quue using linked list//


#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL;
void push()
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("Stack Overflow");
    }
    else
    {
        printf("Enter element: ");
        scanf("%d", &newnode->data);

        newnode->next = top;
        top = newnode;

        printf("Element inserted successfully\n");
    }
}
void pop()
{
    struct node *temp;
    if(top == NULL)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        temp = top;
        printf("Deleted element = %d\n", top->data);

        top = top->next;
        free(temp);
    }
}
void display()
{
    struct node *temp;
    if(top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        temp = top;

        printf("Stack elements are:\n");

        while(temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
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
