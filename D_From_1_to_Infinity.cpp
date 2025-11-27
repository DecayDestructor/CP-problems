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
bool isValidDfsTraversal(ll row, ll col, ll m, ll n, vector<vll>& visited) {
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
int myCountX(int N, int X) {
    if (N < 0) return 0;  // no negatives

    int r = 0;       // result accumulator
    int factor = 1;  // current digit position (1, 10, 100, ...)
    while (N / factor != 0) {
        int lower = N - (N / factor) * factor;  // digits right of current
        int curr = (N / factor) % 10;           // current digit
        int higher = N / (factor * 10);         // digits left of current

        if (curr < X)
            r += higher * factor;
        else if (curr == X)
            r += higher * factor + lower + 1;
        else  // curr > X
            r += (higher + 1) * factor;

        // Special handling for 0 (no leading zeros)
        if (X == 0)
            r -= factor;

        factor *= 10;
    }
    return r;
}

int ceil_div(int a, int b) { return (a + b - 1) / b; }
int digitcounter(int x) {
    return 1ll * 9 * x * binpow(10, x - 1);
}
int countDigit(int n) {
    // Convert the integer to a string
    string num = to_string(n);

    // Return the length of the string (i.e., number of digits)
    return num.length();
}
vector<vi> precomp;  // count, start,end
void solve() {
    int n;
    cin >> n;
    int start = precomp[0][1];
    int end = precomp[0][2];
    for (auto& it : precomp) {
        if (n <= it[0]) {
            start = it[1];
            end = it[2];
            break;
        } else {
            n -= it[0];
        }
    }
    // cout << start << " " << end << nl;
    int d = countDigit(start);
    int count[10] = {0};
    int x = n / d + (start - 1);
    int tempx = x;
    // cout << x << nl;
    if (n % d) {
        x++;
        n = n % d;
        for (int i = 0; i < to_string(x).length() && n > 0; i++, n--) {
            count[to_string(x)[i] - '0']++;
        }
    }
    int ans = 0;
    for (int i = 0; i <= 9; i++) {
        // cout << i << " : " << myCountX(tempx, i) << nl;
        ans += 1ll * i * myCountX(tempx, i) + count[i];
    }
    cout << "answer ";
    cout << ans << nl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    int start = 1;
    for (int i = 1; i <= 18; i++) {
        int total = digitcounter(i);
        precomp.push_back({total, start, (total / i) + start - 1});
        start = start * 10;
    }
    while (t--) {
        solve();
    }
    return 0;
}