#include <bits/stdc++.h>
using namespace std;


void bubbleSort(vector<int>& arr,int n)
{
    bool bul;

    for (int i = 0; i < n - 1; i++)
    {
        bul = false;

        // Inner loop for comparing adjacent elements
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap if the element is greater than the next
                swap(arr[j], arr[j + 1]);
                bul = true;
            }
        }

        // If no elements were swapped, array is already sorted
        if (!bul) break;
    }
}

int main()
{

    int n;
    cout << "Enter size of the array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    // Call bubble sort
    bubbleSort(arr,n);

    cout << "sortted array: ";
    for (int i = 0; i < n; i++)cout << arr[i] << " ";
    cout << endl;

    return 0;

}

