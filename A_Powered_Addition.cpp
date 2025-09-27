#include <bits/stdc++.h>

using namespace std;

#define yey cout << "YES" << "\n";

#define nope cout << "NO" << "\n";

#define ll long long

#define el "\n"

#define all(x) x.begin(), x.end()

#define rall(x) x.rbegin(), x.rend()

#define vec vector<ll>

#define phb push_back

#define plb pop_back();

#define fr(i, s, e) for (ll i = s; i < e; i++)

#define in(arr) \
    for (auto &a : arr) cin >> a;

#define out(arr) \
    for (const auto &it : arr) cout << it << " ";

#define send(x) cout << x << el;

#define sz(x) ((int)(x).size())

void solve() {
    ll n;

    cin >> n;

    vec arr(n);

    in(arr);

    if (is_sorted(all(arr))) {
        send(0);

        return;
    }

    ll maxi = arr[0];

    ll ans = LLONG_MIN;

    fr(i, 1, n) {
        if (maxi > arr[i]) {
            ll diff = maxi - arr[i];

            ll msb = 63 - __builtin_clzll(diff);

            ans = max(ans, msb + 1);

        }

        else {
            maxi = arr[i];
        }
    }

    send(ans);
}

int main() {
    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);

    cout.tie(nullptr);

    ll int t;

    cin >> t;

    while (t--) {
        solve();
    }
}