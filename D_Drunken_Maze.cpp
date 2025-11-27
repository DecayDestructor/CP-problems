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
bool isValidDfsTraversal(ll row, ll col, ll m, ll n, vector<vll>& visited) {
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
int n, m;
pair<int, int> st, t;
int helper(int i, int j, vector<vector<vector<vector<int>>>>& dp, int dir, int rem, vector<string>& arr) {
    if (make_pair(i, j) == t) {
        return 0;
    }
    cout << i << " : " << j << " : " << dir << " : " << rem << nl;
    if (i >= n || j >= m || i < 0 || j < 0 || arr[i][j] == '#' || rem <= 0) return 1e10;
    if (dp[i][j][dir][rem] != 1e10) return dp[i][j][dir][rem];
    int ways = 1e10;
    // left
    for (int k = 1; k <= 3; k++) {
        if (dir == 1 && k > rem) break;
        ways = min(ways, helper(i, j - k, dp, 1, rem - k, arr));
    }
    dp[i][j][1][rem] = min(dp[i][j][1][rem], ways + 1);
    ways = 1e10;
    // right
    for (int k = 1; k <= 3; k++) {
        if (dir == 3 && k > rem) break;
        ways = min(ways, helper(i, j + k, dp, 3, rem - k, arr));
    }
    dp[i][j][3][rem] = min(dp[i][j][3][rem], ways + 1);
    ways = 1e10;
    // up
    for (int k = 1; k <= 3; k++) {
        if (dir == 2 && k > rem) break;
        ways = min(ways, helper(i - k, j, dp, 2, rem - k, arr));
    }
    dp[i][j][2][rem] = min(dp[i][j][2][rem], ways + 1);
    ways = 1e10;
    // left
    for (int k = 1; k <= 3; k++) {
        if (dir == 4 && k > rem) break;
        ways = min(ways, helper(i + k, j, dp, 4, rem - k, arr));
    }
    dp[i][j][4][rem] = min(dp[i][j][4][rem], ways + 1);
    dp[i][j][dir][rem] = min({dp[i][j][1][rem],
                              dp[i][j][2][rem],
                              dp[i][j][3][rem],
                              dp[i][j][4][rem]});
    return dp[i][j][dir][rem];
}

void solve() {
    cin >> n >> m;
    vector<string> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 'S') st = {i, j};
            if (arr[i][j] == 'T') t = {i, j};
        }
    }
    queue<vector<int>> q;
    q.push({st.first, st.second, -1, 3, 0});
    set<vector<int>> stt;
    stt.insert({st.first, st.second, -1, 3});
    auto check = [&](int r, int j) -> bool {
        return r < n && j < m && r >= 0 && j >= 0 && arr[r][j] != '#';
    };
    while (q.size()) {
        int x = q.front()[0];
        int y = q.front()[1];
        int dir = q.front()[2];
        int steps = q.front()[3];
        int ans = q.front()[4];
        q.pop();
        if (make_pair(x, y) == t) {
            cout << ans << nl;
            return;
        }
        // left
        if (dir == 1) {
            if (check(x, y - 1) && steps > 0) {
                if (stt.count({x, y - 1, dir, steps - 1})) continue;
                stt.insert({x, y - 1, dir, steps - 1});
                q.push({x, y - 1, dir, steps - 1, ans + 1});
            }
        }
        // up
        if (dir == 2) {
            if (check(x - 1, y) && steps > 0) {
                if (stt.count({x - 1, y, dir, steps - 1})) continue;
                stt.insert({x - 1, y, dir, steps - 1});
                q.push({x - 1, y, dir, steps - 1, ans + 1});
            }
        }
        // right
        if (dir == 3) {
            if (check(x, y + 1) && steps > 0) {
                if (stt.count({x, y + 1, dir, steps - 1})) continue;
                stt.insert({x, y + 1, dir, steps - 1});
                q.push({x, y + 1, dir, steps - 1, ans + 1});
            }
        }
        // down
        if (dir == 4) {
            if (check(x + 1, y) && steps > 0) {
                if (stt.count({x + 1, y, dir, steps - 1})) continue;
                stt.insert({x + 1, y, dir, steps - 1});
                q.push({x + 1, y, dir, steps - 1, ans + 1});
            }
        }
        for (int i = 1; i <= 4; i++) {
            if (dir != i) {
                if (i == 1) {
                    if (!check(x, y - 1)) continue;
                    if (stt.count({x, y - 1, i, 2})) continue;

                    stt.insert({x, y - 1, i, 2});
                    q.push({x, y - 1, i, 2, ans + 1});
                }
                if (i == 2) {
                    if (!check(x - 1, y)) continue;
                    if (stt.count({x - 1, y, i, 2})) continue;
                    stt.insert({x - 1, y, i, 2});
                    q.push({x - 1, y, i, 2, ans + 1});
                }
                if (i == 3) {
                    if (!check(x, y + 1)) continue;
                    if (stt.count({x, y + 1, i, 2})) continue;
                    stt.insert({x, y + 1, i, 2});
                    q.push({x, y + 1, i, 2, ans + 1});
                }
                if (i == 4) {
                    if (!check(x + 1, y)) continue;
                    if (stt.count({x + 1, y, i, 2})) continue;

                    stt.insert({x + 1, y, i, 2});
                    q.push({x + 1, y, i, 2, ans + 1});
                }
            }
        }
    }
    cout << -1 << nl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}