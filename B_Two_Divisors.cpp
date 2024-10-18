#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define loop(n) for (int i = 0; i < n; i++)
#define py cout << "YES" << nl
#define pn cout << "NO" << nl
#define print(ans) cout << ans << nl
#define isEven(n) if (n % 2 == 0)
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<char> vch;
template <typename T1, typename T2>
using vpp = vector<pair<T1, T2>>;
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
// Template functions for input and output
template <typename T>
void inputArray(vector<T> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

template <typename T>
void outputArray(vector<T> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << nl;
    }
}
template <typename T>
vector<T> factorization(int n)
{
    vector<T> factors;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            factors.push_back(i);
            if (i * i != n)
            {
                factors.push_back(n / i);
            }
        }
    }
    return factors;
}
// DFS Traversal Validation
bool isValidDfsTraversal(ll row, ll col, ll m, ll n, vector<vll> &visited)
{
    return row < m && col < n && row >= 0 && col >= 0 && !visited[row][col];
}
void solve()
{
    ll a, b;
    cin >> a >> b;
    ll ans = lcm(a, b);
    if (ans == b)
    {
        cout << b * b / a << nl;
    }
    else
        cout << ans << nl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}