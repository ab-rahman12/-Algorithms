#include <bits/stdc++.h>
using namespace std;


int binarySearch(vector<int>& arr, int target)
{
    int low = 0;                     // Left index
    int high = arr.size() - 1;       // Right index

    while (low <= high)
    {
        // Calculate middle index (prevents overflow)
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
        {
            return mid;              // Target found, return index
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;           // Target is in the right half
        }
        else
        {
            high = mid - 1;          // Target is in the left half
        }
    }

    return -1;                       // Target not found
}

int main()
{
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13}; // Sorted array
    int target = 7;                           // Value to search

    int index = binarySearch(arr, target);

    if (index != -1)
        cout << "Found at index: " << index << endl;
    else
        cout << "Not Found" << endl;

    return 0;
}
