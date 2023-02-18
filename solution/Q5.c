#include <stdio.h>
int minJumps(int arr[], int n)
{
    if (n <= 1)
        return 0;

    int jumps = 1, maxReach = arr[0], step = arr[0];
    
    for (int i = 1; i < n; i++) {
        if (i == n - 1)
            return jumps;
            
        maxReach = (maxReach > i + arr[i]) ? maxReach : i + arr[i];
        
        step--;
        
        if (step == 0) {
            jumps++;
            if (i >= maxReach)
                return -1;
            step = maxReach - i;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {2, 3, 1, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Minimum number of jumps to reach end is %d\n", minJumps(arr, n));
    return 0;
}