#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;                     // Read two input strings

    int n = s1.size();                   // Length of first string
    int m = s2.size();                   // Length of second string

    // dp[i][j] will store the LCS length of
    // first i characters of s1 and first j characters of s2
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Build the dp table
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // If characters match
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            // If characters do not match
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[n][m] << endl;             // Print length of LCS

    return 0;
}

