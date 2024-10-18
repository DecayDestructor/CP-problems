#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define loop(n) for (int i = 0; i < n; i++)
#define py cout << "YES" << nl
#define pn cout << "NO" << nl
#define print(ans) cout << ans << nl
#define isEven(n) if (n % 2 == 0)
#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define vch vector<char>
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
    ll n, k;
    cin >> n >> k;
    vector<vll> arr(n, vll(n));
    ll left = 0;
    ll right = n - 1;
    if (n == 1)
        py;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    ll counter = 0;
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] != arr[n - i - 1][n - 1 - j])
                counter++;
        }
    }
    if (n % 2 == 1)
    {
        for (int i = 0; i < n / 2; i++)
        {
            if (arr[n / 2][i] != arr[n / 2][n - i - 1])
                counter++;
        }
    }
    if (counter <= k)
    {
        py;
    }
    else
        pn;
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