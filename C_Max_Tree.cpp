#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define loop(s, n, inc) for (ll i = s; i < n; i += inc)
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
#define vvi vector<vi>
#define pi pair<int, int>
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
int n;
set<int> stt;
vi larger;
int ceil_div(int a, int b) { return (a + b - 1) / b; }
int dfs(int node, int par, vector<vector<vi>> &adj, vi &answer) {
    int more = 0;  // how many numbers should be more than that number below that subtree
    for (auto &it : adj[node]) {
        if (it[0] != par) {
            more += dfs(it[0], node, adj, answer);
            if (it[1] >= it[2] && node < it[0]) {  // x > y => u should be larger than v
                // cout << node << " : " << it[0] << nl;
                more++;
            } else if (it[1] < it[2] && it[0] < node) {
                // cout << node << " : " << it[0] << nl;
                more++;
            }
        }
    }
    // cout << more << " at " << node << nl;
    return larger[node] = more;
}
void solve() {
    cin >> n;
    vector<vector<vi>> adj(n + 1);
    vi answer(n + 1, -1);
    larger.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) stt.insert(i);
    for (int i = 0; i < n - 1; i++) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        adj[u].push_back({v, x, y});
        adj[v].push_back({u, x, y});
    }
    dfs(1, -1, adj, answer);
    answer[1] = 1 + larger[1];
    stt.erase(answer[1]);
    // cout << answer[1] << nl;
    queue<int> q;
    q.push(1);
    while (q.size()) {
        int node = q.front();
        q.pop();
        // cout << "starting with " << node << nl;
        for (auto &it : adj[node]) {
            if (answer[it[0]] == -1) {
                if (it[1] >= it[2]) {  // x > y => u should get higher value ( u is the smaller node)
                    if (it[0] < node) {
                        answer[it[0]] = *stt.upper_bound(answer[node]);
                    } else {
                        answer[it[0]] = *prev(stt.lower_bound(answer[node]));
                    }
                } else {
                    // y>x => u should get smaller value
                    if (it[0] > node) {
                        answer[it[0]] = *stt.upper_bound(answer[node]);
                    } else {
                        answer[it[0]] = *prev(stt.lower_bound(answer[node]));
                    }
                }
                q.push(it[0]);
                // cout << "assigning " << answer[it[0]] << " to " << it[0] << nl;
                // if (it[0] == 4) return;
                stt.erase(answer[it[0]]);
            }
        }
    }

    for (int i = 1; i <= n; i++) cout << answer[i] << " ";
    cout << nl;
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