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

// Binary exponentiation
ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll result = 1;
    while (b > 0) {
        if (b & 1) result = (result * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return result;
}

// Modular inverse (prime modulus)
ll mminvprime(ll a, ll m) {
    return binpow(a, m - 2, m);
}

void solve() {
    int n;
    ll k;
    cin >> n >> k;
    vll arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    ll N = k + 1;
    ll primeFactor = N;

    for (ll d = 2; d * d <= N; ++d) {
        if (N % d == 0) {
            primeFactor = min(primeFactor, d);
            break;
        }
    }

    auto mod = [&](ll x, ll m) -> ll { return (x % m + m) % m; };
    ll remK = mod(k, primeFactor);
    ll invK = mminvprime(remK, primeFactor);

    for (int i = 0; i < n; i++) {
        ll curRem = mod(arr[i], primeFactor);
        ll need = (primeFactor - curRem) % primeFactor;
        ll mult = (need * invK) % primeFactor;
        arr[i] += mult * k;
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << nl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}
