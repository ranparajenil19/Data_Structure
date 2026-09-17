```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Returns height of tree
// Returns -1 if tree is not balanced
int checkHeight(struct Node* root) {

    // Empty tree has height 0
    if (root == NULL)
        return 0;

    // Find height of left subtree
    int leftHeight = checkHeight(root->left);

    // If left subtree is unbalanced
    if (leftHeight == -1)
        return -1;

    // Find height of right subtree
    int rightHeight = checkHeight(root->right);

    // If right subtree is unbalanced
    if (rightHeight == -1)
        return -1;

    // Check difference between left and right heights
    if (abs(leftHeight - rightHeight) > 1)
        return -1;

    // Return height of current node
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Check whether tree is height-balanced
int isBalanced(struct Node* root) {
    return checkHeight(root) != -1;
}

int main() {

    // Example 1:
    //
    //          3
    //         / \
    //        9   20
    //           /  \
    //          15   7
    //
    struct Node* root1 = createNode(3);

    root1->left = createNode(9);
    root1->right = createNode(20);

    root1->right->left = createNode(15);
    root1->right->right = createNode(7);

    if (isBalanced(root1))
        printf("TRUE\n");
    else
        printf("FALSE\n");


    // Example 2:
    //
    //          1
    //         / \
    //        2   2
    //       / \
    //      3   3
    //     / \
    //    4   4
    //
    struct Node* root2 = createNode(1);

    root2->left = createNode(2);
    root2->right = createNode(2);

    root2->left->left = createNode(3);
    root2->left->right = createNode(3);

    root2->left->left->left = createNode(4);
    root2->left->left->right = createNode(4);

    if (isBalanced(root2))
        printf("TRUE\n");
    else
        printf("FALSE\n");

    return 0;
}
```
