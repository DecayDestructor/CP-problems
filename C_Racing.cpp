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
#define int long long
#define pi pair<int, int>
template <typename T1, typename T2>
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
    int n;
    cin >> n;
    vi d(n);
    vector<pair<int, int>> arr(n);
    for (auto &it : d) cin >> it;
    for (auto &it : arr) cin >> it.first >> it.second;
    vi mini(n);
    if (d[n - 1] == -1 || d[n - 1] == 1) {
        mini[n - 1] = arr[n - 1].first - 1;
    } else {
        mini[n - 1] = arr[n - 1].first;
    }
    for (int i = n - 2; i >= 0; i--) {
        if (d[i] != 0) {
            mini[i] = max(arr[i].first - 1, mini[i + 1] - 1);
        } else {
            mini[i] = max(arr[i].first, mini[i + 1]);
        }
        // mini[i]=max(mini[i],arr[])
    }
    vi maxi(n);
    maxi[n - 1] = arr[n - 1].second;
    for (int i = n - 2; i >= 0; i--) {
        maxi[i] = min(maxi[i + 1], arr[i].second);
    }
    // for (auto &it : mini) {
    //     cout << it << " ";
    // }
    // cout << nl;
    // for (auto &it : maxi) {
    //     cout << it << " ";
    // }
    // cout << nl;
    vi answer;
    int curr = 0;
    for (int i = 0; i < n; i++) {
        if (curr < arr[i].first) {
            cout << i << nl;
            cout << -1 << nl;
            return;
        }
        if (d[i] == 1) {
            if (curr + 1 < mini[i] || curr + 1 < arr[i].first) {
                cout << -1 << nl;
                return;
            }
            if (curr + 1 > maxi[i]) {
                cout << -1 << nl;
                return;
            } else {
                curr++;
                answer.push_back(1);
            }
        } else if (d[i] == -1) {
            if (curr + 1 < mini[i] || curr + 1 < arr[i].first) {
                cout << -1 << nl;
                return;
            }
            if (curr + 1 > maxi[i]) {
                answer.push_back(0);
            } else {
                curr++;
                answer.push_back(1);
            }
        } else {
            if (curr < mini[i] || curr > maxi[i]) {
                cout << -1 << nl;
                return;
            }
            curr += d[i];
            answer.push_back(d[i]);
        }
    }
    for (auto &it : answer) {
        cout << it << " ";
    }
    cout << nl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    // if (t == 5)
    //     while (t--) {
    //         solve();
    //     }
    // else {
    //     for (int i = 0; i < t; i++) {
    //         int n;
    //         cin >> n;
    //         vi d(n);
    //         vector<pair<int, int>> arr(n);
    //         for (auto &it : d) cin >> it;
    //         for (auto &it : arr) cin >> it.first >> it.second;
    //         if (i == 27) {
    //             cout << n << nl;
    //             for (auto &it : d) cout << it << " ";
    //             cout << nl;
    //             for (auto &it : arr) cout << it.first << " : " << it.second << nl;
    //         }
    //     }
    // }
    while (t--) {
        solve();
    }

    return 0;
}