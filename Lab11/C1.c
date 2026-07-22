#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int expo;
    struct Node* next;
};

struct Node* insertTerm(struct Node* head, int c, int e) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->coeff = c;
    new_node->expo = e;
    new_node->next = NULL;

    if (head == NULL) {
        return new_node;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    return head;
}

struct Node* addPolynomials(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->expo > p2->expo) {
            result = insertTerm(result, p1->coeff, p1->expo);
            p1 = p1->next;
        } else if (p1->expo < p2->expo) {
            result = insertTerm(result, p2->coeff, p2->expo);
            p2 = p2->next;
        } else {
            int sum_coeff = p1->coeff + p2->coeff;
            if (sum_coeff != 0) {
                result = insertTerm(result, sum_coeff, p1->expo);
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        result = insertTerm(result, p1->coeff, p1->expo);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        result = insertTerm(result, p2->coeff, p2->expo);
        p2 = p2->next;
    }

    return result;
}

void displayPoly(struct Node* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->expo);
        temp = temp->next;
        if (temp != NULL && temp->coeff >= 0) {
            printf(" + ");
        } else if (temp != NULL) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* polySum = NULL;

    poly1 = insertTerm(poly1, 5, 4);
    poly1 = insertTerm(poly1, 3, 2);
    poly1 = insertTerm(poly1, 2, 0);

    poly2 = insertTerm(poly2, 4, 3);
    poly2 = insertTerm(poly2, 6, 2);
    poly2 = insertTerm(poly2, 1, 1);

    printf("Polynomial 1: ");
    displayPoly(poly1);

    printf("Polynomial 2: ");
    displayPoly(poly2);

    polySum = addPolynomials(poly1, poly2);

    printf("Sum Result:   ");
    displayPoly(polySum);

    return 0;
}