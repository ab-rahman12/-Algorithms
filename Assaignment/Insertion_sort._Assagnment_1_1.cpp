#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n)
{
    // Start from the 2nd element.because assume the 1st element is already "sorted"
    for (int i = 1; i < n; ++i)
    {
        int key = arr[i];   // Current element to be inserted
        int j = i - 1;      // Index of the previous element

        // Shift elements that are greater than key and index >=0
        // one position to the right to make space for key
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j]; // Move element one step ahead
            j--;         // Move to the previous element
        }

        // Place the key in its correct position
        arr[j + 1] = key;
    }
}

int main()
{
    int n;//array size
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];//array

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Call insertion sort function
    insertionSort(arr, n);

    // Print sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}



