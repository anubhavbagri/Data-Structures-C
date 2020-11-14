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
