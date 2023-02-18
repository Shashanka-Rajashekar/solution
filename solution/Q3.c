int majorityElement(int *arr, int n) {
    int count = 0;
    int majority = 0;
    for (int i = 0; i < n; i++) {
        if (count == 0) {
            majority = arr[i];
            count = 1;
        } else if (arr[i] == majority) {
            count++;
        } else {
            count--;
        }
    }
    count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == majority) {
            count++;
        }
    }
    if (count > n / 2) {
        return majority;
    }
    return -1;
}



