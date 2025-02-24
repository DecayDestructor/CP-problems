
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define ca "YES\n"
#define wa "NO\n"

void takeinput(vector<ll> &v, ll n) {
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
    }
}

ll kadanes(vector<ll> &v, ll st, ll n) {
    ll sum = 0, ans = INT_MIN;
    for (ll i = st; i < n; i++) {
        sum += v[i];
        ans = max(ans, sum);
        if (sum < 0) {
            sum = 0;
        }
    }
    return ans;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    ll neg = 0;
    ll total = 0;
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
        total += v[i];
        if (v[i] < 0) {
            neg++;
        }
    }

    if (neg == 0) {
        if (total == 0) {
            cout << "NO" << endl;
            return;
        } else
            cout << "YES" << endl;
        return;
    }
    ll mx = kadanes(v, 1, n);
    mx = max(mx, kadanes(v, 0, n - 1));
    if (total > mx) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}