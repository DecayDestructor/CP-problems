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

vector<ll> sieveOfEratosthenes(int n) {
    vector<ll> sieve(n + 1, 1);
    sieve[0] = sieve[1] = 0;
    for (int i = 2; i * i <= n; i++) {
        if (sieve[i]) {
            for (int j = i * i; j <= n; j += i) {
                sieve[j] = 0;
            }
        }
    }
    return sieve;
}

ll sumOfNaturalNumbers(ll n) {
    return (1LL * n * (n + 1)) / 2;
}

bool isValidDfsTraversal(ll row, ll col, ll m, ll n, vector<vll> &visited) {
    return row < n && col < m && row >= 0 && col >= 0 && !visited[row][col];
}

ll power(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b % 2 == 1)
            res *= a;
        a *= a;
        b /= 2;
    }
    return res;
}
ll mminvprime(ll a, ll m) {
    return power(a, m - 2);
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

ll get_num(ll n, ll x, ll y) {
    ll res = 0;
    ll pow4 = power(4, n - 1);

    for (ll lvl = n; lvl > 0; --lvl) {
        ll size = power(2, lvl);
        ll half = size / 2;

        if (x <= half && y <= half) {
        } else if (x > half && y > half) {
            res += pow4;
            x -= half;
            y -= half;
        } else if (x > half && y <= half) {
            res += 2 * pow4;
            x -= half;
        } else {
            res += 3 * pow4;
            y -= half;
        }

        pow4 /= 4;
    }

    ll offset = 1;
    if (x == 2 && y == 2)
        offset = 2;
    else if (x == 2 && y == 1)
        offset = 3;
    else if (x == 1 && y == 2)
        offset = 4;

    return res + offset;
}

pair<ll, ll> get_pos(ll n, ll d) {
    ll x = 1, y = 1;
    ll remain = d;
    ll pow4 = power(4, n - 1);

    for (ll lvl = n; lvl > 0; --lvl) {
        ll size = power(2, lvl);
        ll half = size / 2;

        if (remain <= pow4) {
        } else if (remain <= 2 * pow4) {
            x += half;
            y += half;
            remain -= pow4;
        } else if (remain <= 3 * pow4) {
            x += half;
            remain -= 2 * pow4;
        } else {
            y += half;
            remain -= 3 * pow4;
        }

        pow4 /= 4;
    }

    return {x, y};
}

void solve() {
    ll n, q;
    cin >> n >> q;

    while (q--) {
        string queryType;
        cin >> queryType;

        if (queryType == "->") {
            ll x, y;
            cin >> x >> y;
            ll ans = get_num(n, x, y);
            cout << ans << nl;
        } else if (queryType == "<-") {
            ll d;
            cin >> d;
            pair<ll, ll> coords = get_pos(n, d);
            cout << coords.first << " " << coords.second << nl;
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