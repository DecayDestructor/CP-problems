#include <bits/stdc++.h>
using namespace std;

// Macros
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

// Functions
ll lcm(ll a, ll b) { return (a / __gcd(a, b)) * b; }

// Input and Output for arrays
template <typename T>
void inputArray(vector<T> &arr, int n) {
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}
template <typename T>
void outputArray(vector<T> &arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << nl;
    }
}

// Debugging
void debug(auto &arr) {
    for (auto &it : arr) {
        cout << it << " ";
    }
    cout << nl;
}

// Sorting comparator for descending order
bool RSORT(ll a, ll b) {
    return a > b;
}

// Factorization
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

// Additional Code from the provided snippet
const int MAX = 200'007;
int a[MAX], psum[MAX];

// Function to calculate the "log base 3 count"
int f(int x) {
    int cnt = 0;
    while (x) {
        x /= 3;
        cnt++;
    }
    return cnt;
}

// Solve function for each test case
void solve() {
    int l, r;
    cin >> l >> r;
    cout << psum[r] - psum[l - 1] + a[l] << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Precompute values for `a` and prefix sums
    psum[0] = 0;
    for (int i = 1; i < MAX; i++) {
        a[i] = f(i);
        psum[i] = psum[i - 1] + a[i];
    }

    // Handle test cases
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
