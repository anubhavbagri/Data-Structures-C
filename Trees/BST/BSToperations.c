#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node * create(int item)
{
    struct Node * node = (struct Node*) malloc(sizeof(struct Node*));
    node->data = item;
    node->left = node->right = NULL;
    return node;
}
void preorder(struct Node *root)
{
    if(root == NULL)
    {
        return;
    }
    printf("-->%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct Node *root)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("-->%d ", root->data);
    inorder(root->right);
}
void postorder(struct Node *root)
{
    if(root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("-->%d ",root->data);
}
struct Node * insertion(struct Node *root, int item)
{
    if(root == NULL)
    {
        return create(item);
    }
    if(item < root->data)
    {
        root->left = insertion(root->left, item);
    }
    else if (item > root->data)
    {
        root->right = insertion(root->right, item);
    }
    else
    {
        return root;     //requirement for compiler to avoid missing return statement.
    }
}
struct Node* search(struct Node* root, int item)
{
    if (root == NULL || root->data == item)
        return root;
    if (root->data < item)
        return search(root->right, item);
    return search(root->left, item);
}
//find the in-order successor
struct Node *findInorderSuccessor(struct Node *node )
{
    struct Node *current = node;
    //Find the leftmost leaf
    while(current && current->left != NULL)
    {
        current = current->left;
    }

    return current;
}
struct Node * deleteNode(struct Node *root, int key)
{
    if(root == NULL)
    {
        return root;
    }
    if(key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if(key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        //if the node is with one child or no child
        if(root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        //If the node has two children
        struct Node *temp = findInorderSuccessor(root->right);
        //place the in-order successor in position of the node to be deleted
        root->data = temp->data;
        //Delete the in-order successor.
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
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
        printf("\nPress 4 to Preorder traversal.");
        printf("\nPress 5 to In-order traversal.");
        printf("\nPress 6 to Postorder traversal.");
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
            preorder(root);
            break;
        }
        case 5:
        {
            inorder(root);
            break;
        }
        case 6:
        {
            postorder(root);
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
