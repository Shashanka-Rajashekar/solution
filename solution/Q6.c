#include <stdio.h>

int main() {
    int n = 100,m=50;
    int sum = n * (n + 1) / 2;
    int sum_even = m* (m + 1);
    int sum_odd = m * m;
    
    printf("Sum of numbers from 1 to 100: %d\n", sum);
    printf("Sum of even numbers from 1 to 100: %d\n", sum_even);
    printf("Sum of odd numbers from 1 to 100: %d\n", sum_odd);
    
    return 0;
}
