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
        string s;
        cin >> s;
        int left = 0;
        int right = 0;
        int sum = 0;
        int maxi = INT_MIN;
        int counter = 0;
        while (right < n)
        {
            if (s[right] == '.')
            {
                counter++;
            }
            if (s[right] == '#')
            {
                maxi = max(maxi, right - left);
                left = right + 1;
            }
            right++;
        }
        maxi = max(maxi, right - left);
        maxi > 2 ? cout << "2" << endl : cout << counter << endl;
    }
    return 0;
}