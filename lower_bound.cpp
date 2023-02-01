
#include <stdio.h>
 
// Recursive implementation of
// lower_bound
int lower_bound(int arr[], int low,
                int high, int X)
{
 
    // Base Case
    if (low > high) {
        return low;
    }
 
    // Find the middle index
    int mid = low + (high - low) / 2;
 
    // If arr[mid] is greater than
    // or equal to X then search
    // in left subarray
    if (arr[mid] >= X) {
        return lower_bound(arr, low,
                           mid - 1, X);
    }
 
    // If arr[mid] is less than X
    // then search in right subarray
    return lower_bound(arr, mid + 1,
                       high, X);
}
 
// Recursive implementation of
// upper_bound
int upper_bound(int arr[], int low,
                int high, int X)
{
 
    // Base Case
    if (low > high)
        return low;
 
    // Find the middle index
    int mid = low + (high - low) / 2;
 
    // If arr[mid] is less than
    // or equal to X search in
    // right subarray
    if (arr[mid] <= X) {
        return upper_bound(arr, mid + 1,
                           high, X);
    }
 
    // If arr[mid] is greater than X
    // then search in left subarray
    return upper_bound(arr, low,
                       mid - 1, X);
}
 
// Function to implement lower_bound
// and upper_bound of X
void printBound(int arr[], int N, int X)
{
    int idx;
 
    // If lower_bound doesn't exists
    if (lower_bound(arr, 0, N, X) == N) {
        printf("Lower bound doesn't exist");
    }
    else {
 
        // Find lower_bound
        idx = lower_bound(arr, 0, N, X);
        printf("Lower bound of %d "
               "is %d at index %d\n",
               X, arr[idx], idx);
    }
 
    // If upper_bound doesn't exists
    if (upper_bound(arr, 0, N, X) == N) {
        printf("Upper bound doesn't exist");
    }
    else {
 
        // Find upper_bound
        idx = upper_bound(arr, 0, N, X);
        printf("Upper bound of %d is"
               "% d at index % d\n ",
               X,
               arr[idx], idx);
    }
}
 
// Driver Code
int main()
{
    // Given array
    int arr[] = { 4, 6, 10, 12, 18, 20 };
    int N = sizeof(arr) / sizeof(arr[0]);
 
    // Element whose lower bound and
    // upper bound to be found
    int X = 6;
 
    // Function Call
    printBound(arr, N, X);
    return 0;
}
