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
