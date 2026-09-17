#include <stdio.h>

#define MAX 100

struct Interval {
    int start;
    int end;
};

struct Interval stack[MAX];
int top = -1;

void push(struct Interval val) {
    if (top < MAX - 1) {
        stack[++top] = val;
    }
}

void pop() {
    if (top >= 0) {
        top--;
    }
}

struct Interval peek() {
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

void sortIntervals(struct Interval arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].start > arr[j + 1].start) {
                struct Interval temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void mergeIntervals(struct Interval arr[], int n) {
    if (n <= 0) return;

    top = -1; 

  
    sortIntervals(arr, n);

   
    push(arr[0]);

    for (int i = 1; i < n; i++) {
        struct Interval current = arr[i];
        struct Interval top_item = peek();

     
        if (current.start <= top_item.end) {
           
            if (current.end > top_item.end) {
                top_item.end = current.end;
            }
            pop();
            push(top_item);
        } else {
            push(current);
        }
    }


    printf("Output: {");
    for (int i = 0; i <= top; i++) {
        printf("{%d, %d}", stack[i].start, stack[i].end);
        if (i < top) printf(", ");
    }
    printf("}\n");
}

int main() {

    struct Interval ex1[] = {{1, 3}, {2, 4}, {6, 8}, {9, 10}};
    int n1 = sizeof(ex1) / sizeof(ex1[0]);
    printf("Sample Example-1:\n");
    mergeIntervals(ex1, n1);

    struct Interval ex2[] = {{6, 8}, {1, 9}, {2, 4}, {4, 7}};
    int n2 = sizeof(ex2) / sizeof(ex2[0]);
    printf("\nSample Example-2:\n");
    mergeIntervals(ex2, n2);

    return 0;
}