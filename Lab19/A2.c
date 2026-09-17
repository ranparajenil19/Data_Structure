#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

int isSame(struct node* root1, struct node* root2) {
    if (root1 == NULL && root2 == NULL) {
        return 1;
    }

    if (root1 == NULL || root2 == NULL) {
        return 0;
    }

    return (root1->data == root2->data) &&
           isSame(root1->left, root2->left) &&
           isSame(root1->right, root2->right);
}

int main() {
    struct node* root1 = createNode(3);
    root1->left = createNode(2);
    root1->right = createNode(4);
    root1->left->right = createNode(1);

    struct node* root2 = createNode(3);
    root2->left = createNode(2);
    root2->right = createNode(4);
    root2->left->right = createNode(1);

    struct node* root3 = createNode(3);
    root3->left = createNode(2);
    root3->right = createNode(4);
    root3->left->left = createNode(1);

    printf("Comparing Tree 1 and Tree 2:\n");
    if (isSame(root1, root2)) {
        printf("Given trees are same\n");
    } else {
        printf("Given trees are not same\n");
    }

    printf("\nComparing Tree 1 and Tree 3:\n");
    if (isSame(root1, root3)) {
        printf("Given trees are same\n");
    } else {
        printf("Given trees are not same\n");
    }

    return 0;
}