#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;
const int MAXN = 2e6;

vector<ll> fac(MAXN, 1);
vector<ll> inv(MAXN, 1);

/**
 * Computes x^n modulo m in O(log p) time.
 * See also: https://usaco.guide/gold/modular
 */
ll binpow(ll x, ll n, ll m) {
    x %= m;
    ll res = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            res = res * x % m;
        }
        x = x * x % m;
        n /= 2;
    }
    return res;
}

ll binom(int n, int k) { return fac[n] * inv[k] % MOD * inv[n - k] % MOD; }

int main() {
    for (int i = 2; i < MAXN; i++) {
        fac[i] = i * fac[i - 1] % MOD;
    }

    // Calculate the modular inverse with exponentiation
    inv[MAXN - 1] = binpow(fac[MAXN - 1], MOD - 2, MOD);
    // Calculate the modular inverse with factorial definition
    for (int i = MAXN - 2; i > 0; i--) {
        inv[i] = (i + 1) * inv[i + 1] % MOD;
    }

    int n, m;
    cin >> n >> m;

    cout << binom(n + m - 1, n - 1) << endl;
}