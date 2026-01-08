#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* detectCycleStart(struct Node* head) {
    struct Node *slow = head, *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }

    if (!fast || !fast->next)
        return NULL;

    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

int main() {
    struct Node *a = malloc(sizeof(struct Node));
    struct Node *b = malloc(sizeof(struct Node));
    struct Node *c = malloc(sizeof(struct Node));
    struct Node *d = malloc(sizeof(struct Node));

    a->data = 1; b->data = 2; c->data = 3; d->data = 4;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = b; // cycle start at b

    struct Node* start = detectCycleStart(a);
    if (start)
        printf("Cycle starts at node with value: %d\n", start->data);
    else
        printf("No cycle\n");

    return 0;
}
