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
vector<int> factorization(int n) {
    vector<int> factors;
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
map<int, int> primeFactorisation(ll n) {
    map<int, int> mpp;
    for (ll i = 2; i <= sqrt(n); i++) {
        while (n % i == 0) {
            mpp[i]++;
            n = n / i;
        }
    }
    if (n != 1)
        mpp[n]++;
    return mpp;
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
    return (1LL * n * (n + 1)) / 2;  // Formula to calculate the sum
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
ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
ll mminvprime(ll a, ll m) {
    return binpow(a, m - 2, m);
}
ll mod_add(ll a, ll b, ll m) {
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
ll mod_mul(ll a, ll b, ll m) {
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m) {
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
ll mod_div(ll a, ll b, ll m) {
    a = a % m;
    b = b % m;
    return (mod_mul(a, mminvprime(b, m), m) + m) % m;
}
int ceil_div(int a, int b) { return (a + b - 1) / b; }
vi visited;
int fact[(int)1e5 + 1];
int inv[(int)1e5 + 1];
const int MOD = (int)1e9 + 7;
int nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return mod_mul(fact[n], mod_mul(inv[r], inv[n - r], MOD), MOD);
}
int dfs(int node, vector<vector<pair<int, int>>> &adj, int parent) {
    int sum = 0;
    visited[node] = 1;
    for (auto &it : adj[node]) {
        int v = it.first;
        int e = it.second;
        if (v == parent || e) continue;
        sum = mod_add(sum, dfs(v, adj, node), MOD);
    }
    return (sum + 1) % MOD;
}
void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<pair<int, int>>> adj(n + 1);
    visited.resize(n + 1);
    visited.assign(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        int u, v, e;
        cin >> u >> v >> e;
        adj[u].push_back({v, e});
        adj[v].push_back({u, e});
    }
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            int count = dfs(i, adj, -1);
            answer += binpow(count, k, MOD);
        }
    }
    int all = binpow(n, k, MOD);
    cout << mod_sub(all, answer, MOD) << nl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    fact[0] = 1;
    for (int i = 1; i <= 1e5; i++) {
        fact[i] = mod_mul(i, fact[i - 1], MOD);
    }
    inv[(int)1e5] = mminvprime(fact[(int)1e5], MOD);
    for (int i = 1e5 - 1; i >= 0; i--) {
        inv[i] = mod_mul(i + 1, inv[i + 1], MOD);
    }
    while (t--) {
        solve();
    }
    return 0;
}