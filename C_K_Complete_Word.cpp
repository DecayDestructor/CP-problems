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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<string> temp(k, "");
    for (int i = 0; i < n; i++) {
        // cout << s[i] << nl;
        temp[i % k] += (s[i]);
    }
    int answer = 0;
    int left = 0, right = k - 1;
    for (int i = 0; i < k / 2; i++) {
        vector<int> alpha(26, 0);
        for (char &ch : temp[left]) {
            alpha[ch - 'a']++;
        }
        for (char &ch : temp[right]) {
            alpha[ch - 'a']++;
        }
        int maxi = -1;
        for (auto &it : alpha) {
            maxi = max(maxi, it);
        }
        // cout << temp[left] << " : " << temp[right] << " : " << (2 * n / k) - maxi << nl;
        answer += ((2 * n / k) - maxi);
        left++;
        right--;
    }
    if (left == right) {
        vector<int> alpha(26, 0);
        for (char &ch : temp[left]) {
            alpha[ch - 'a']++;
        }
        int maxi = -1;
        for (auto &it : alpha) {
            maxi = max(maxi, it);
        }
        // cout << temp[left] << " : " << temp[right] << " : " << (n / k) - maxi << nl;
        answer += ((n / k) - maxi);
        left++;
        right--;
    }
    cout << answer << nl;
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