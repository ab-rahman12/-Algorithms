#include <bits/stdc++.h>
using namespace std;

// Function to merge two subarrays of arr[]
// First subarray: arr[left..mid]
// Second subarray: arr[mid+1..right]
void merge(vector<int>& arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;   // n1 =Size of left subarray
    int n2 = right - mid;      //n2 =Size of right subarray

    // Create temporary arrays
    vector<int> L(n1), R(n2);

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0;     // Initial index of L[]
    int j = 0;     // Initial index of R[]
    int k = left;  // Initial index of merged subarray

    // Merge the two arrays back into arr[left..right]
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of L[] if any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of R[] if any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(vector<int>& arr, int left, int right) // left = starting index, right = ending index
{
    if (left >= right) return; // Base case (1 element is already sorted)

    int mid = left + (right - left) / 2;

    // Recursively sort first half
    mergeSort(arr, left, mid);

    // Recursively sort second half
    mergeSort(arr, mid + 1, right);

    // Merge the two sorted halves
    merge(arr, left, mid, right);
}

int main()
{
    int n;//n=array size
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // Input array elements
    }

    // Call merge sort
    mergeSort(arr, 0, n - 1);

    // Print sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

