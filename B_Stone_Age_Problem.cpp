#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define loop(n) for (ll i = 0; i < n; i++)
#define py cout << "YES"
#define pn cout << "NO"
#define print(ans) cout << ans << nl
#define isEven(n) if (n % 2 == 0)
#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define vvll vector<vector<ll>>
#define vvch vector<vector<char>>
#define vch vector<char>
template <typename T1, typename T2>
using vpp = vector<pair<T1, T2>>;
ll lcm(ll a, ll b) { return (a / __gcd(a, b)) * b; }
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
bool RSORT(ll a, ll b)
{
    return a > b;
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
// Sieve of Eratosthenes
vector<ll> sieveOfEratosthenes(int n)
{
    vector<ll> sieve(n + 1, 1);
    sieve[0] = sieve[1] = 0; // 0 and 1 are not primes
    for (int i = 2; i * i <= n; i++)
    {
        if (sieve[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                sieve[j] = 0; // Mark multiples of i as non-prime
            }
        }
    }
    return sieve; // Return the sieve vector
}
// Sum of first n natural numbers
ll sumOfNaturalNumbers(ll n)
{
    return (n * (n + 1)) / 2; // Formula to calculate the sum
}
// DFS Traversal Validation
bool isValidDfsTraversal(ll row, ll col, ll m, ll n, vector<vll> &visited)
{
    return row < n && col < m && row >= 0 && col >= 0 && !visited[row][col];
}
// Binary Exponentiation
ll binpow(ll a, ll b, ll m)
{
    a %= m;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
void solve()
{
    ll n, q;
    cin >> n >> q;
    // map<ll, ll> arr;
    vll arr(n);
    ll sum = 0;
    ll all = -1;
    set<ll> alter;
    loop(n)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    loop(q)
    {
        ll choice;
        cin >> choice;
        if (choice == 1)
        {
            ll pos, val;
            cin >> pos >> val;

            if (!alter.count(pos) && all != -1)
            {
                alter.insert(pos);
                sum += (val - all);
                arr[pos - 1] = val;
            }
            else
            {
                sum += (val - arr[pos - 1]);
                arr[pos - 1] = val;
            }
        }
        else
        {
            ll val;
            cin >> val;
            sum = (n * val);
            all = val;
            alter.clear();
        }
        cout << sum << nl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}