#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n;//size of the array
    cout<<"Enter the size of the array : ";
    cin>>n;
    vector<int>a(n);//array
    cout<<"Enter the elements ot the array : ";
    for(int i = 0;i <n ;i++)
    {
        cin >> a[i];
    }
    vector<int>freq(n+1,0);

    for(int i =0 ;i <n ; i++)
    {
        freq[a[i]]++;//count the number of the each elements
    }
    cout<<"print the sorted array : ";
    for(int i = 0;i <= n; i++)
    {
        if( freq[i] == 0) continue; //avoid the number which are absent in the array

        for(int j = 0; j <freq[i] ; j++)//second loop for the print the number freq[i] times
        {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
