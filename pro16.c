//!write a program in c to create a binary tree and perform the preorder,inorder,and postorder traversal using recursive function//

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node* create()
{
    int val;
    struct node *newnode;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &val);
    if(val == -1)
        return NULL;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    printf("Enter left child of %d\n", val  );
    newnode->left = create();
    printf("Enter right child of %d\n", val);
    newnode->right = create();
    return newnode;
}
void preorder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void postorder(struct node *root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
int main()
{
    struct node *root = NULL;
    printf("Create Binary Tree:\n");
    root = create();
    printf("\nPreorder Traversal: ");
    preorder(root);
    printf("\nInorder Traversal: ");
    inorder(root);
    printf("\nPostorder Traversal: ");
    postorder(root);
    return 0;
}
