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
bool greaterSort(pair<ll, ll> &a, pair<ll, ll> &b)
{
    if (a.first > b.first)
        return true;
    return false;
}
// DFS Traversal Validation
bool isValidDfsTraversal(ll row, ll col, ll m, ll n, vector<vll> &visited)
{
    return row < m && col < n && row >= 0 && col >= 0 && !visited[row][col];
}
void solve()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> arr(3 * n);
    // int visited[3] = {0, 0, 0};
    // int days[3] = {0, 0, 0};
    unordered_set<ll> visited;
    unordered_set<ll> days;
    // int check[3] = {1, 1, 1};
    for (int i = 0; i < 3 * n; i++)
    {
        int a;
        cin >> a;
        arr[i] = {a, i};
    }
    sort(arr.begin(), arr.end(), greaterSort);
    for (auto it : arr)
    {
        cout << it.first << " : " << it.second << nl;
    }
    cout << nl;

    ll sum = arr[0].first;
    visited.insert(arr[0].second % n);
    days.insert(arr[0].second / n);
    ll index = 1;
    while (index < 3 * n && visited.size() != 3)
    {

        // cout << arr[index].first << " : " << arr[index].second % n << " : " << visited[arr[index].second % n] << nl;
        if (!(visited.count(arr[index].second % n)) && !(days.count(arr[index].second / n)))
        {
            visited.insert(arr[index].second % n);
            days.insert(arr[index].second / n);
            sum += arr[index].first;
        }
        index++;
    }
    cout << sum << nl;
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