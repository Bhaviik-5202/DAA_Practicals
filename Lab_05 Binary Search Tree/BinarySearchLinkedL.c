/*
Lab 05 - Cat B: Binary Search on Singly Linked List (File Input)
Time Complexity: O(N)
Space Complexity: O(N)
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

struct Node {
    int data;
    struct Node* next;
};

struct Node* head;
struct Node* tail;

void insertAtLast(int n) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = n;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

struct Node* getMiddle(struct Node* start, struct Node* end) {
    if (start == NULL) {
        return NULL;
    }
    struct Node* slow = start;
    struct Node* fast = start->next;

    while (fast != end) {
        fast = fast->next;
        if (fast != end) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    return slow;
}

struct Node* binarySearch(struct Node* head, int value) {
    struct Node* start = head;
    struct Node* end = NULL;

    while (start != end) {
        struct Node* mid = getMiddle(start, end);
        if (mid == NULL) {
            return NULL;
        }

        if (mid->data == value) {
            return mid;
        } else if (mid->data < value) {
            start = mid->next;
        } else {
            end = mid;
        }
    }
    return NULL;
}

int main() {

    FILE *file = fopen("Best_1000.txt", "r");
    // FILE *file = fopen("Best_10000.txt", "r");
    // FILE *file = fopen("Best_100000.txt", "r");

    if (file == NULL) {
        printf("Error Opening Best_1000.txt\n");
        return 1;
    }

    int value;
    while (fscanf(file, "%d", &value) == 1) {
        insertAtLast(value);
    }

    fclose(file);

    int target;
    printf("Enter Element to Find: ");
    scanf("%d", &target);

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    struct Node *result = binarySearch(head, target);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    if (result != NULL) {
        printf("Element %d Found.\n", result->data);
    } else {
        printf("Element Not Found.\n");
    }

    printf("Execution Time = %f Seconds\n", cpu_time_used);

    return 0;
}