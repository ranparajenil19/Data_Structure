#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value){

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}
int isMirror(struct Node* root1 , struct Node* root2){
    if(root1==NULL && root2==NULL){
        return 1;
    }
    if(root1==NULL || root2==NULL){
        return 0;
    }
    if(root1->data!=root2->data){
        return 0;
    }

    return isMirror(root1->left , root2->right) && isMirror(root1->right,root2->left);
}
int twoPart(struct Node* root){
    if(root==NULL){
        return 1;
    }
    return isMirror(root->left , root->right);
}
int main() {
    struct Node* root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(2);
    root1->left->left = createNode(3);
    root1->left->right = createNode(4);
    root1->right->left = createNode(4);
    root1->right->right = createNode(3);

    printf("Tree 1: ");
    if (twoPart(root1)) {
        printf("Symmetric (Mirror of itself)\n");
    } else {
        printf("Not Symmetric\n");
    }

    struct Node* root2 = createNode(1);
    root2->left = createNode(2);
    root2->right = createNode(2);
    root2->left->right = createNode(3);
    root2->right->right = createNode(3);

    printf("Tree 2: ");
    if (twoPart(root2)) {
        printf("Symmetric (Mirror of itself)\n");
    } else {
        printf("Not Symmetric\n");
    }

    return 0;
}