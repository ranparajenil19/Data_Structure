```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int search(int postorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (postorder[i] == value)
            return i;
    }

    return -1;
}

struct Node* buildTree(int preorder[], int postorder[],
                       int preStart, int preEnd,
                       int postStart, int postEnd) {

    if (preStart > preEnd || postStart > postEnd)
        return NULL;

    struct Node* root = createNode(preorder[preStart]);

    if (preStart == preEnd)
        return root;

    int leftRoot = preorder[preStart + 1];

    int index = search(postorder, postStart, postEnd, leftRoot);

    int leftSize = index - postStart + 1;

    root->left = buildTree(
        preorder, postorder,
        preStart + 1,
        preStart + leftSize,
        postStart,
        index
    );

    root->right = buildTree(
        preorder, postorder,
        preStart + leftSize + 1,
        preEnd,
        index + 1,
        postEnd - 1
    );

    return root;
}

void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {

    int preorder[] = {1, 2, 4, 5, 3, 6, 7};
    int postorder[] = {4, 5, 2, 6, 7, 3, 1};

    int n = 7;

    struct Node* root = buildTree(
        preorder,
        postorder,
        0,
        n - 1,
        0,
        n - 1
    );

    printf("Inorder Traversal: ");
    inorder(root);

    return 0;
}
```
