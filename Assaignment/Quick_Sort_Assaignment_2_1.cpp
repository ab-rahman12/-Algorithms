#include <bits/stdc++.h>
using namespace std;


int partition(vector<int>& arr, int low, int high)
{
    // Partition function that places the pivot element

    int pivot = arr[high];   // Choose the last element as pivot
    int i = low - 1;         // Index of smaller element

    // Move elements smaller than pivot to the left side
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]); // Place smaller element before pivot
        }
    }

    // Place pivot after all smaller elements
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high)
{
    if (low < high)// low = starting index, high = ending index
    {
        int pi = partition(arr, low, high);//pi=pivot

        // Recursively sort elements before pivot
        quickSort(arr, low, pi - 1);

        // Recursively sort elements after pivot
        quickSort(arr, pi + 1, high);
    }
}

int main()
{

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n); // Declare vector of size n

    cout << "Enter the elements ot the array: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    // Call the quick sort function
    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;

}

