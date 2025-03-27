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
ll binpow(ll a, ll b) {
    // a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
// ll mminvprime(ll a, ll m) {
//     return binpow(a, m - 2, m);
// }
// ll mod_add(ll a, ll b, ll m) {
//     a = a % m;
//     b = b % m;
//     return (((a + b) % m) + m) % m;
// }
// ll mod_mul(ll a, ll b, ll m) {
//     a = a % m;
//     b = b % m;
//     return (((a * b) % m) + m) % m;
// }
// ll mod_sub(ll a, ll b, ll m) {
//     a = a % m;
//     b = b % m;
//     return (((a - b) % m) + m) % m;
// }
// ll mod_div(ll a, ll b, ll m) {
//     a = a % m;
//     b = b % m;
//     return (mod_mul(a, mminvprime(b, m), m) + m) % m;
// }
// vi primes = sieveOfEratosthenes(2e5);
vll spf(2e5 + 1, 1e9);
vector<pair<int, int>> primeFactorization(int x) {
    vector<pair<int, int>> ans;

    while (x != 1) {
        int prime = spf[x];
        int cnt = 0;
        while (x % prime == 0) {
            cnt++;
            x = x / prime;
        }
        // cout << prime << " : " << cnt << nl;
        ans.push_back({prime, cnt});
    }

    return ans;
}
int maxN = 2e5;
void solve() {
    int n;
    cin >> n;
    vll arr(n);
    vvll mpp(maxN);
    for (auto &it : arr) {
        cin >> it;
        vector<pair<int, int>> fac = primeFactorization(it);
        for (auto &it : fac) {
            mpp[it.first].push_back(it.second);
        }
    }
    int answer = 1;
    for (int i = 1; i <= maxN; i++) {
        vi it = mpp[i];
        sort(all(it));
        if (it.size() < n - 1) continue;
        if (it.size() == n) {
            answer *= (1ll * binpow(i, it[1]));
        } else {
            answer *= (1ll * binpow(i, it[0]));
        }
    }
    cout << answer << nl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    vector<bool> isPrime(maxN, true);

    for (long long i = 2; i < maxN; i++) {
        if (isPrime[i]) {
            spf[i] = i;
            for (long long j = i * i; j < maxN; j += i) {
                isPrime[j] = false;
                spf[j] = min(spf[j], (int)i);
            }
        }
    }
    while (t--) {
        solve();
    }
    return 0;
}