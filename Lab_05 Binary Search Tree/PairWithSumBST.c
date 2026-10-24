/*
Lab 5 - Cat C: Check if two distinct BST nodes sum to a target using in-order traversal
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if(root == NULL) {
        return createNode(data);
    }

    if(data < root->data) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }

    return root;
}

void inorder(struct Node* root, int arr[], int *count) {
    if (root == NULL) return;
    inorder(root->left, arr, count);
    arr[(*count)++] = root->data;
    inorder(root->right, arr, count);
}

int findPairInorder(struct Node* root, int target) {
    int arr[1000];
    int count = 0;
    inorder(root, arr, &count);

    int left = 0;
    int right = count - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            return 1;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    return 0;
}

int main() {
    struct Node* root = NULL;
    int n, value, target;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter node values:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Enter target: ");
    scanf("%d", &target);

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    int found = findPairInorder(root, target);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    if(found)
        printf("True\n");
    else
        printf("False\n");

    printf("Execution Time = %f Seconds\n", cpu_time_used);

    return 0;
}