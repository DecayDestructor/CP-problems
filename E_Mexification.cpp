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
int ceil_div(int a, int b) { return (a + b - 1) / b; }
void solve() {
    int n, k;
    cin >> n >> k;
    vi arr(n);
    vi mpp(n + 1);
    set<int> stt;
    for (auto &it : arr) {
        cin >> it;
        mpp[it]++;
    }
    for (int i = 0; i <= n + 1; i++) {
        stt.insert(i);
    }
    for (auto &it : arr) {
        stt.erase(it);
    }
    int mex = *stt.begin();
    int adder = !(k % 2);
    int mini = mex;
    for (int i = mex; i >= 0; i--) {
        if (mpp[i] > 1) {
            mini = i;
        }
    }
    // cout << "mini is " << mini << " mex is " << mex << nl;
    if (k == 1) {
        int sum = 0;
        for (auto &it : arr) {
            if (it > mex || mpp[it] > 1)
                sum += mex;
            else
                sum += it;
        }
        cout << sum << nl;
        return;
    } else if (mini == mex) {
        int counter = 0;
        for (int i = mex; i <= n; i++) {
            if (mpp[i]) counter += mpp[i];
        }
        int sum = 0;
        int adder = (!(k % 2)) && (counter > 1);
        // cout << !(k % 2) << nl;
        // cout << adder << nl;
        for (auto &it : arr) {
            if (it > mex)
                sum += mex + adder;
            else
                sum += it;
        }
        cout << sum << nl;
    } else {
        int adder = k % 2;
        // cout << "mini is " << mini << nl;
        int sum = 0;
        for (auto &it : arr) {
            if (it >= mini) {
                sum += (adder + mini);
            } else {
                sum += it;
            }
        }
        cout << sum << nl;
    }
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
    // if (t == 5) {
    //     while (t--) solve();
    // }
    // for (int i = 0; i < t; i++) {
    //     int n, k;
    //     cin >> n >> k;
    //     vi arr(n);
    //     for (auto &it : arr) cin >> it;
    //     if (i == 21) {
    //         cout << n << " " << k << nl;
    //         for (auto &it : arr) cout << it << " ";
    //         cout << nl;
    //     }
    // }
    return 0;
}