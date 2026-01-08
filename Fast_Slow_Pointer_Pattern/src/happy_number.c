#include <stdio.h>

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

int main() {
    int n = 19;

    if (isHappy(n))
        printf("%d is a Happy Number\n", n);
    else
        printf("%d is NOT a Happy Number\n", n);

    return 0;
}
