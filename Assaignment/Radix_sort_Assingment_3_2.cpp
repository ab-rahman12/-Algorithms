#include <bits/stdc++.h>
using namespace std;

int getMax(vector<int>& arr, int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > mx)
            mx = arr[i];
    }
    return mx;
}

// A function to do counting sort of array according to the digit represented by exp
void countSort(vector<int>& arr, int n, int exp)
{
    vector<int> output(n);    // Output array
    int count[10] = {0};      // Count array for digits 0–9

    // Count occurrences of digits
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] contains actual position of this digit
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array (stable sort: process from right to left)
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy output[] to arry
    for (int i = 0; i < n; i++)arr[i] = output[i];
}

// The main function to sort array using Radix Sort
void radixSort(vector<int>& arr, int n)
{
    // Find maximum number to know number of digits
    int m = getMax(arr, n);

    /*counting sort for every digit
    exp = 1, 10, 100...*/
    for (int exp = 1; m / exp > 0; exp *= 10)countSort(arr, n, exp);

}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    // function Call
    radixSort(arr, n);

    // Print sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)cout << arr[i] << " ";
    cout << endl;

    return 0;

}

