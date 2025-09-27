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
vi mark;
string s, b;
int final_answer = 0;
int count() {
    // cout << "subset is : " << nl;
    // for (int i = 0; i < 26; i++) {
    //     if (mark[i]) cout << char('a' + i) << nl;
    // }
    int answer = 0;
    for (int i = 0; i < s.length(); i++) {
        int counter = 0;
        while (i < s.length() && (s[i] == b[i] || mark[s[i] - 'a'])) {
            counter++;
            i++;
        }
        answer += sumOfNaturalNumbers(counter);
    }
    return answer;
}
void backtrack(int len, int &k, vch &chars, int pos) {
    if (len > k) return;
    if (pos == chars.size()) {
        if (len == k) {
            final_answer = max(final_answer, count());
        }
        return;
    }
    // take
    mark[chars[pos] - 'a'] = 1;
    backtrack(len + 1, k, chars, pos + 1);
    // not take
    mark[chars[pos] - 'a'] = 0;
    backtrack(len, k, chars, pos + 1);
}
void solve() {
    int n, k;
    cin >> n >> k;
    cin >> s >> b;
    final_answer = 0;
    mark.assign(26, 0);
    unordered_map<char, bool> unq;
    for (auto &it : s) unq[it] = true;
    vch chars;
    for (auto &it : unq) chars.push_back(it.first);
    k = min(k, (int)unq.size());
    backtrack(0, k, chars, 0);
    // cout << "answer " << nl;
    cout << final_answer << nl;
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