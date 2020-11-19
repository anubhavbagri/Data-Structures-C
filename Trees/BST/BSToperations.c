#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node * create(int item){
    struct Node * node = (struct Node*) malloc(sizeof(struct Node*));
    node->data = item;
    node->left = node->right = NULL;
    return node;
}
void inorder(struct Node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf(" %d ", root->data);
    inorder(root->right);
}
struct Node * insertion(struct Node *root, int item){
    if(root == NULL){
        return create(item);
    }
    if(item < root->data){
        root->left = insertion(root->left, item);
    }
    else if (item > root->data){
        root->right = insertion(root->right, item);
    }
    else{
        return root;   //requirement for compiler to avoid missing return statement.
    }
}
int main()
{
    struct Node *root = NULL;
    int choice, item, se;
    do
    {
        printf("\nBST Operations");
        printf("\nPress 1 to insert.");
        printf("\nPress 2 to search.");
        printf("\nPress 3 to delete.");
        printf("\nPress 4 to display.");
        printf("\nPress 0 to exit");
        printf("\nEnter your choice (0, 1, 2, 3, 4) : ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
        {
            printf("\nEnter the item which you want to insert : ");
            scanf("%d", &item);
            root = insertion(root, item);
            break;
        }
        case 2:
        {
            printf("\nEnter the value which you want to search : ");
            scanf("%d", &se);
            if(search(root, se))
                printf("\nElement %d found.",se);
            else
                printf("\nElement %d not found.",se);
        }
        case 3:
        {
            printf("\nEnter the item which you want to delete : ");
            scanf("%d", &item);
            root = deleteNode(root, item);
            break;
        }
        case 4:
        {
            inorder(root);
            break;
        }
        case 0:
        {
            exit(choice);
        }
        default:
        {
            printf("\nWrong option selected.");
        }
        }
    }
    while(1);
    return 0;
}
