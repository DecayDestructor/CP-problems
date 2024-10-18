#include <bits/stdc++.h>
using namespace std;
void solve()
{
    bool flag = true;
    int n, m;
    cin >> n >> m;
    string s, x;
    cin >> x >> s;
    int count = 6;

    for (int i = 0; i < 6; i++)
    {
        size_t found = x.find(s);
        if (found != string::npos)
        {
            cout << i << "\n";
            flag = false;
            break;
        }
        x = x + x;
    }
    if (flag)
    {
        cout << "-1\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}