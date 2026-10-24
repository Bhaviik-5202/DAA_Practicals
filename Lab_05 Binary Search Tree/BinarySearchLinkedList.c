/*
Lab 5 - Cat B: Binary search algorithm using linked list and recursive method
Time Complexity: O(n)
Space Complexity: O(log n)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(struct Node **head, int data) {
    struct Node *newNode = createNode(data);

    if(*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

struct Node* findMiddle(struct Node *start, struct Node *last) {
    if(start == NULL)
        return NULL;

    struct Node *slow = start;
    struct Node *fast = start->next;

    while(fast != last)
    {
        fast = fast->next;

        if(fast != last)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    return slow;
}

struct Node* binarySearch(struct Node *start, struct Node *last, int key) {
    if(start == last)
        return NULL;

    struct Node *mid = findMiddle(start, last);

    if(mid == NULL)
        return NULL;

    if(mid->data == key)
        return mid;

    if(key < mid->data)
        return binarySearch(start, mid, key);

    return binarySearch(mid->next, last, key);
}

int main() {
    struct Node *head = NULL;
    struct Node *result;
    int n, i, value, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter sorted elements:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &value);
        insert(&head, value);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    clock_t start = clock();
    result = binarySearch(head, NULL, key);
    clock_t end = clock();

    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    if(result != NULL)
        printf("Element Found\n");
    else
        printf("Element Not Found\n");

    printf("Execution Time = %f Seconds\n", cpu_time_used);

    return 0;
}