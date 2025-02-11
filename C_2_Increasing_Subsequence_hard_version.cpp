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
    int n;
    cin >> n;
    vll arr(n);
    for (auto &it : arr)
        cin >> it;
    string s = "";
    int left = 0, right = n - 1;
    int prev = 0;
    while (left <= right) {
        if (arr[left] < arr[right]) {
            if (arr[left] > prev) {
                prev = arr[left];
                s += "L";
                left++;

            } else if (arr[right] > prev) {
                prev = arr[right];
                s += "R";
                right--;
            } else
                break;
        } else if (arr[right] < arr[left]) {
            if (arr[right] > prev) {
                prev = arr[right];
                s += "R";
                right--;

            } else if (arr[left] > prev) {
                prev = arr[left];
                left++;
                s += "L";
            } else
                break;
        } else {
            int c1 = 0, c2 = 0;
            if (arr[left] <= prev) break;
            int left1 = left, right1 = right;
            while (left1 < right && arr[left1 + 1] > arr[left1]) {
                c1++;
                left1++;
            }
            while (right1 > left && arr[right1 - 1] > arr[right1]) {
                right1--;
                c2++;
            }
            if (c1 > c2) {
                prev = arr[left];
                left++;
                s += "L";
            } else {
                prev = arr[right];
                right--;
                s += "R";
            }
        }
    }
    cout << s.length() << nl << s << nl;
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