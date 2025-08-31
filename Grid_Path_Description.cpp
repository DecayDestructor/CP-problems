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
struct State {
    int index, r, c;
};

void solve() {
    string s;
    cin >> s;
    int n = s.length();

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(7, vector<int>(7, 0)));
    dp[0][0][0] = 1;  // start at (0,0)

    int dir[4][2] = {
        {0, 1},   // right
        {0, -1},  // left
        {-1, 0},  // up
        {1, 0}    // down
    };

    queue<State> q;
    q.push({0, 0, 0});

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        int index = cur.index, r = cur.r, c = cur.c;

        if (index >= n) continue;

        if (s[index] == 'U') {
            if (r - 1 >= 0) {
                if (dp[index + 1][r - 1][c] == 0)
                    q.push({index + 1, r - 1, c});
                dp[index + 1][r - 1][c] += dp[index][r][c];
            }
        } else if (s[index] == 'D') {
            if (r + 1 < 7) {
                if (dp[index + 1][r + 1][c] == 0)
                    q.push({index + 1, r + 1, c});
                dp[index + 1][r + 1][c] += dp[index][r][c];
            }
        } else if (s[index] == 'L') {
            if (c - 1 >= 0) {
                if (dp[index + 1][r][c - 1] == 0)
                    q.push({index + 1, r, c - 1});
                dp[index + 1][r][c - 1] += dp[index][r][c];
            }
        } else if (s[index] == 'R') {
            if (c + 1 < 7) {
                if (dp[index + 1][r][c + 1] == 0)
                    q.push({index + 1, r, c + 1});
                dp[index + 1][r][c + 1] += dp[index][r][c];
            }
        } else {
            for (auto &d : dir) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < 7 && nc >= 0 && nc < 7) {
                    if (dp[index + 1][nr][nc] == 0)
                        q.push({index + 1, nr, nc});
                    dp[index + 1][nr][nc] += dp[index][r][c];
                }
            }
        }
    }

    cout << dp[n][0][n - 1] << '\n';
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