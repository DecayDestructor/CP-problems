#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define loop(s, n) for (ll i = s; i < n; i++)
#define all(a) a.begin(), a.end()
#define py cout << "YES" << nl
#define pn cout << "NO" << nl
#define print(ans) cout << ans << nl
#define isEven(n) if (n % 2 == 0)
#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define vvll vector<vector<ll>>
#define vvch vector<vector<char>>
#define vch vector<char>
template <typename T1, typename T2>
#define int long long
using vpp = vector<pair<T1, T2>>;
ll lcm(ll a, ll b) { return (a / __gcd(a, b)) * b; }
bool RSORT(ll a, ll b) {
    return a > b;
}
template <typename T>
vector<T> factorization(int n) {
    vector<T> factors;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            factors.push_back(i);
            if (i * i != n) {
                factors.push_back(n / i);
            }
        }
    }
    return factors;
}
// Prime Factorization
void primeFactorisation(ll n, map<ll, ll> &mpp) {
    for (ll i = 2; i <= sqrt(n); i++) {
        while (n % i == 0) {
            mpp[i]++;
            n = n / i;
        }
    }
    if (n != 1)
        mpp[n]++;
}
// Sieve of Eratosthenes
vector<ll> sieveOfEratosthenes(int n) {
    vector<ll> sieve(n + 1, 1);
    sieve[0] = sieve[1] = 0;  // 0 and 1 are not primes
    for (int i = 2; i * i <= n; i++) {
        if (sieve[i]) {
            for (int j = i * i; j <= n; j += i) {
                sieve[j] = 0;  // Mark multiples of i as non-prime
            }
        }
    }
    return sieve;  // Return the sieve vector
}
// Sum of first n natural numbers
ll sumOfNaturalNumbers(ll n) {
    return (n * (n + 1)) / 2;  // Formula to calculate the sum
}
// DFS Traversal Validation
bool isValidDfsTraversal(ll row, ll col, ll m, ll n, vector<vll> &visited) {
    return row < n && col < m && row >= 0 && col >= 0 && !visited[row][col];
}
// Binary Exponentiation
ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
void solve() {
    int m, n;
    cin >> n >> m;
    vvch arr(n, vch(m));
    vpp<ll, ll> coordinates;
    // cout << "new testcase" << nl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == '?') {
                coordinates.push_back({i, j});
            }
        }
    }
    queue<pair<ll, ll>> q;
    vvll visited(n, vll(m, 0));
    for (int i = 0; i < m; i++) {
        if (arr[0][i] == 'U') {
            q.push({0, i});
        }
    }
    for (int i = 0; i < m; i++) {
        if (arr[n - 1][i] == 'D') {
            q.push({n - 1, i});
        }
    }
    for (int i = 0; i < n; i++) {
        if (arr[i][m - 1] == 'R') {
            q.push({i, m - 1});
        }
    }
    for (int i = 0; i < n; i++) {
        if (arr[i][0] == 'L') {
            q.push({i, 0});
        }
    }
    set<pair<ll, ll>> illegal;
    while (!q.empty()) {
        auto it = q.front();
        int x = it.first;
        int y = it.second;
        q.pop();
        illegal.insert(it);
        if (x - 1 >= 0 && arr[x - 1][y] == 'D') {
            q.push({x - 1, y});
            illegal.insert({x - 1, y});
        }
        if (y - 1 >= 0 && arr[x][y - 1] == 'R') {
            q.push({x, y - 1});
            illegal.insert({x, y - 1});
        }
        if (x + 1 < n && arr[x + 1][y] == 'U') {
            q.push({x + 1, y});
            illegal.insert({x + 1, y});
        }
        if (y + 1 < m && arr[x][y + 1] == 'L') {
            q.push({x, y + 1});
            illegal.insert({x, y + 1});
        }
    }
    int ans = n * m - (ll)illegal.size();
    for (auto &it : coordinates) {
        int x = it.first;
        int y = it.second;
        if (x + 1 < n) {
            if (!illegal.count({x + 1, y})) {
                continue;
            }
        }
        if (x - 1 >= 0 && !illegal.count({x - 1, y}))
            continue;
        if (y - 1 >= 0 && !illegal.count({x, y - 1}))
            continue;
        if (y + 1 < m && !illegal.count({x, y + 1}))
            continue;
        ans -= 1;
    }
    cout << ans << nl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}