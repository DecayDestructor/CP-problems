#include <bits/stdc++.h>
using namespace std;
int n;
void solve()
{
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (arr[0] != 1)
        cout << "No\n";
    else
        cout << "Yes\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        solve();
    }
    return 0;
}