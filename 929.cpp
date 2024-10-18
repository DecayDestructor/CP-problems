#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        int *arr = new int[n];
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            cin >> arr[j];
            sum = sum + abs(arr[j]);
        }
        cout << sum << endl;
    }
    return 0;
}