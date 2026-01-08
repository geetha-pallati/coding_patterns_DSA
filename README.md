# coding_patterns_DSA

# 1. Fast_Slow_Pointer_Pattern:

    What is Fast–Slow Pointer Pattern?

    You use two pointers:

    Slow pointer → moves 1 step at a time

    Fast pointer → moves 2 steps at a time
    
# They help detect cycles, middle elements, and loop entry points efficiently in O(n) time and O(1) space.When to Use This Pattern?

✅ Detect cycle in linked list
✅ Find middle of linked list
✅ Find start of cycle
✅ Happy Number problem
✅ Find duplicate number in array
✅ Check palindrome in linked list

# Basic Template (Linked List)
slow = head;
fast = head;

while (fast != NULL && fast->next != NULL) {
    slow = slow->next;           // 1 step
    fast = fast->next->next;     // 2 steps
}
# i.Find Middle of Linked List
Logic

When fast reaches end, slow is at middle

struct Node* findMiddle(struct Node* head) {
    struct Node *slow = head, *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
For even length → returns second middle

#  ii. Detect Cycle in Linked List (Floyd’s Algorithm)
Logic
    If fast and slow meet, cycle exists

int hasCycle(struct Node* head) {
    struct Node *slow = head, *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return 1;   // cycle detected
    }
    return 0;
}
# iii. Find Start of Cycle

Logic

    1. Detect cycle
    2.Move one pointer to head
    3.Move both 1 step
    4.Meeting point = cycle start

struct Node* detectCycleStart(struct Node* head) {
    struct Node *slow = head, *fast = head;

    // Step 1: detect cycle
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }

    if (!fast || !fast->next)
        return NULL;  // no cycle

    // Step 2: find entry
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

# iv. Happy Number (Array / Math Example)
Logic

    Convert number → sum of squares of digits
    Cycle → not happy

int squareSum(int n) {
    int sum = 0;
    while (n) {
        int d = n % 10;
        sum += d * d;
        n /= 10;
    }
    return sum;
}

int isHappy(int n) {
    int slow = n, fast = n;

    do {
        slow = squareSum(slow);
        fast = squareSum(squareSum(fast));
    } while (slow != fast);

    return slow == 1;
}
# v. Find Duplicate Number (Array)
Logic
    Numbers: 1..n
    Size: n+1
    One duplicate

int findDuplicate(int* nums, int size) {
    int slow = nums[0];
    int fast = nums[0];

    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    slow = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}
# Fast–Slow Pointer pattern uses two pointers moving at different speeds to detect cycles, find midpoints, or locate repeated elements efficiently.
====================================================================================================================