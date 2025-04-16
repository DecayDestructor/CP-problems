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
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n % 2 == 0) {
        map<char, int> odd, even;
        for (int i = 0; i < n; i++) {
            if (i % 2)
                odd[s[i]]++;
            else
                even[s[i]]++;
        }
        int maxiOdd = -1, maxiEven = -1;
        for (auto &it : odd) maxiOdd = max(maxiOdd, it.second);
        for (auto &it : even) maxiEven = max(maxiEven, it.second);
        cout << n - (maxiEven + maxiOdd) << nl;

    } else {
        cout << "odd" << nl;
        vector<pair<char, int>> preEven(n + 1), sufEven(n + 1);
        vi preCounter(26), sufCounter(26);
        for (int i = 1; i <= n; i += 2) {
            preCounter[s[i - 1] - 'a']++;
            if (preCounter[s[i - 1] - 'a'] > preEven[i - 1].second) {
                preEven[i] = {s[i - 1], preCounter[s[i - 1] - 'a']};
            } else {
                preEven[i] = preEven[i - 1];
            }
        }
        for (auto it = preEven.begin(); it != preEven.end(); ++it) {
            if (it->first == 0 && it != preEven.begin()) {
                *it = *(prev(it));
            }
            cout << it->first << " " << it->second << nl;
        }
        vector<pair<char, int>> preOdd(n + 1), sufOdd(n + 1);
        preCounter.assign(26, 0);
        sufCounter.assign(26, 0);
        for (int i = n; i >= 0; i -= 2) {
            sufCounter[s[i - 1] - 'a']++;
            if (sufCounter[s[i - 1] - 'a'] > sufOdd[i - 1].second) {
                preEven[i] = {s[i - 1], preCounter[s[i - 1] - 'a']};
            } else {
                preEven[i] = preEven[i - 1];
            }
        }
        for (auto it = preEven.begin(); it != preEven.end(); ++it) {
            if (it->first == 0 && it != preEven.begin()) {
                *it = *(prev(it));
            }
            cout << it->first << " " << it->second << nl;
        }
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
    return 0;
}