#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int answer = 0;
    int digit;
    for (int i = 1; i <= n; i++)
    {
        int counter = 0;
        for (int i = 1; i <= 3; i++)
        {
            cin >> digit;
            if (digit == 1)
            {
                counter++;
            }
        }
        if (counter >= 2)
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}