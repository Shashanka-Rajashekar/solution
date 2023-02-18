#include <stdio.h>

int binarySearch(int *arr, int n, int x) {
   int l = 0, r = n - 1;
   while (l <= r) {
      int mid = l + (r - l) / 2;
      if (arr[mid] == x)
         return mid;
      if (arr[mid] < x)
         l = mid + 1;
      else
         r = mid - 1;
   }
   return -1;
}

int main() {
   int arr[] = { 2, 5, 7, 10, 13, 17, 20 };
   int n = sizeof(arr) / sizeof(arr[0]);
   int x = 10;
   int result = binarySearch(arr, n, x);
   if (result == -1)
      printf("Element not found.");
   else
      printf("Element found at index %d.", result);
   return 0;
}
