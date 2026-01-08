#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int hasCycle(struct Node* head) {
    struct Node *slow = head, *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return 1;
    }
    return 0;
}

int main() {
    struct Node *head = malloc(sizeof(struct Node));
    struct Node *second = malloc(sizeof(struct Node));
    struct Node *third = malloc(sizeof(struct Node));

    head->data = 1;
    second->data = 2;
    third->data = 3;

    head->next = second;
    second->next = third;
    third->next = second; // cycle

    if (hasCycle(head))
        printf("Cycle detected\n");
    else
        printf("No cycle\n");

    return 0;
}
