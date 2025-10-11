#include <stdio.h>
#include <stdlib.h>

struct TreeNode 
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int data) 
{
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* insert(struct TreeNode* root, int data) 
{
    if (root == NULL) 
    {
        return createNode(data);
    }
    if (data < root->data) 
    {
        root->left = insert(root->left, data);
    } 
    else if (data > root->data) 
    {
        root->right = insert(root->right, data);
    }
    return root;
}

void inorderTraversal(struct TreeNode* root) 
{
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void preorderTraversal(struct TreeNode* root) 
{
    if (root == NULL) 
    {
        return;
    }
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(struct TreeNode* root) 
{
    if (root == NULL) 
    {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

int main() 
{
    struct TreeNode* root = NULL;
    int choice, data;
    restart:
    printf("\nPress 1 to Insert a node\n");
    printf("Press 2 to In-order Traversal\n");
    printf("Press 3 to Pre-order Traversal\n");
    printf("Press 4 to Post-order Traversal\n");
    printf("Press 5 to Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) 
    {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            root = insert(root, data);
            goto restart;
        case 2:
            printf("In-order Traversal: ");
            inorderTraversal(root);
            printf("\n");
            goto restart;
        case 3:
            printf("Pre-order Traversal: ");
            preorderTraversal(root);
            printf("\n");
            goto restart;
        case 4:
            printf("Post-order Traversal: ");
            postorderTraversal(root);
            printf("\n");
            goto restart;
        case 5:
            printf("Exit.\n");
            break;
        default:
            printf("Wrong Choice\n");
            goto restart;
    }
    system("PAUSE");
    return 0;
}
