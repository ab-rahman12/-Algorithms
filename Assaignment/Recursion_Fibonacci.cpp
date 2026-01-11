#include <bits/stdc++.h>
using namespace std;

// Recursive function to find nth Fibonacci number
int fibonacci(int n)
{
    // Base case: first two Fibonacci numbers
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    // Recursive case
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n ;
    cin>>n;
    int ans=fibonacci(n);   //Function call
    cout << ans << endl;

    return 0;
}

