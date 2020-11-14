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
    int choice, item;
    do{
        printf("\nEnter the item which you want to insert : ");
        scanf("%d", &item);
        root = insertion(root, item);
        printf("\nPress 1 to insert more tree and 0 to exit : ");
        scanf("%d", &choice);
    }while(choice);
    printf("\n Displaying the tree : ");
    inorder(root);
	return 0;
}
