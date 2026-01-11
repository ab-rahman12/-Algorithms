#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;                     // Read the number of elements

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];            // Read each element of the array
    }

    int currentSum = arr[0];      // Stores the sum of the current subarray
    int maxSum = arr[0];          // Stores the maximum subarray sum found so far

    // Traverse the array starting from the second element
    for (int i = 1; i < n; i++)
    {
        // Decide whether to start a new subarray
        // or continue the previous subarray
        currentSum = max(arr[i], currentSum + arr[i]);

        // Update the maximum subarray sum if needed
        maxSum = max(maxSum, currentSum);
    }

    cout << maxSum << endl;       // Print the maximum subarray sum

    return 0;                     // End of program
}
