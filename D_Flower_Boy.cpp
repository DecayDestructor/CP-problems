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
void solve() {
    int n, m;
    cin >> n >> m;
    vi arr(n);
    vi b(m);
    for (auto &it : arr) cin >> it;
    for (auto &it : b) cin >> it;

    int answer = 1e12;
    vi prefix(m, -1), suffix(m, -1);
    int j = 0;

    // Build prefix array
    for (int i = 0; i < n; i++) {
        if (j < m && arr[i] >= b[j]) {
            prefix[j] = i;
            j++;
        }
    }
    if (j == m) {
        cout << 0 << nl;
        return;
    }

    // Build suffix array
    j = m - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (j >= 0 && arr[i] >= b[j]) {
            suffix[j] = i;
            j--;
        }
    }
    if (j < 0) {
        cout << 0 << nl;
        return;
    }

    // Check for each possible removal
    for (int i = 1; i < m - 1; i++) {
        if (prefix[i - 1] != -1 && suffix[i + 1] != -1 && prefix[i - 1] < suffix[i + 1]) {
            answer = min(answer, b[i]);
        }
    }

    // Check removing first flower
    if (suffix[1] != -1) {
        answer = min(answer, b[0]);
    }

    // Check removing last flower
    if (prefix[m - 2] != -1) {
        answer = min(answer, b[m - 1]);
    }

    cout << (answer == 1e12 ? -1 : answer) << nl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    // if (t == 7) {
    while (t--) {
        solve();
    }
    // }
    // for (int i = 0; i < t; i++) {
    //     int n, m;
    //     cin >> n >> m;
    //     vi arr(n);
    //     vi b(m);
    //     for (auto &it : arr) cin >> it;
    //     for (auto &it : b) cin >> it;
    //     if (i == 47) {
    //         cout << n << " " << m;
    //         for (auto &it : arr) cout << it << " ";
    //         cout << nl;
    //         for (auto &it : b) cout << it << " ";
    //         cout << nl;
    //     }
    // }
    return 0;
}