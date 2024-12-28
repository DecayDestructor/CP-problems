#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define loop(s, n) for (ll i = s; i < n; i++)
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
using vpp = vector<pair<T1, T2>>;
ll lcm(ll a, ll b) { return (a / __gcd(a, b)) * b; }
// Template functions for input and output
template <typename T>
void inputArray(vector<T> &arr, int n) {
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void debug(auto &arr) {
    for (auto &it : arr) {
        cout << it << " ";
    }
    cout << nl;
}
template <typename T>
void outputArray(vector<T> &arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << nl;
    }
}
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
    ll n, m;
    cin >> n >> m;
    vector<string> arr(n);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // debug(arr);
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << nl;
    // }
    ll numberOfLayers = 0;
    ll curr = 0;
    ll trow = n, tcol = m;
    while (curr < n * m) {
        curr += 2 * (trow + tcol - 2);
        numberOfLayers++;
        trow -= 2;
        tcol -= 2;
    }
    // cout << numberOfLayers << nl;
    ll count = 0;
    for (ll i = 0; i < numberOfLayers; i++) {
        vll layer;
        ll row = i, col = i;
        while (col < m - i) {
            layer.push_back(arr[row][col] - '0');
            col++;
        }
        col--;
        row++;
        while (row < n - i) {
            layer.push_back(arr[row][col] - '0');
            row++;
        }
        row--;
        col--;
        while (col >= i) {
            layer.push_back(arr[row][col] - '0');
            col--;
        }
        row--;
        col++;
        while (row > i) {
            layer.push_back(arr[row][col] - '0');
            row--;
        }
        // debug(layer);
        ll lsize = layer.size();
        for (ll t = 0; t < lsize; t++) {
            if (layer[t] == 1) {
                if (layer[(t + 1) % lsize] == 5 && layer[(t + 2) % lsize] == 4 && layer[(t + 3) % lsize] == 3) {
                    count++;
                }
            }
        }
    }
    cout << count << nl;
}
int main() {
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