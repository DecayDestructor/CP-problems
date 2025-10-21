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
#define int long long
int N = 2e5 + 100;
vi spf(N);
void smallestprimefac() {
    for (int i = 0; i <= N; i++) spf[i] = i;
    for (int i = 2; i <= N; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= N; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}
void solve() {
    int n;
    cin >> n;
    int evencounter = 0;
    map<int, int> mpp;
    vi arr(n);
    vi b(n);
    for (auto& it : arr) {
        cin >> it;
        evencounter += !(it % 2);
    }
    for (auto& it : b) cin >> it;
    for (auto& it : arr) {
        int temp = it;
        while (temp > 1) {
            int fac = spf[temp];
            mpp[fac]++;
            while (temp % fac == 0) temp = temp / fac;
        }
    }
    for (auto& it : mpp) {
        if (it.second >= 2) {
            cout << 0 << nl;
            return;
        }
    }
    // for (auto& it : mpp) cout << it.first << " : " << it.second << nl;
    for (auto& it : arr) {
        int temp = it;
        while (temp > 1) {
            int fac = spf[temp];
            mpp[fac]--;
            while (temp % fac == 0) temp = temp / fac;
        }
        // for (auto& it : mpp) cout << it.first << " : " << it.second << nl;
        temp = it + 1;
        while (temp > 1) {
            int fac = spf[temp];
            mpp[fac]++;
            if (mpp[fac] > 1) {
                cout << 1 << nl;
                return;
            }
            mpp[fac]--;
            while (temp % fac == 0) temp = temp / fac;
        }
        temp = it;
        while (temp > 1) {
            int fac = spf[temp];
            mpp[fac]++;
            while (temp % fac == 0) temp = temp / fac;
        }
    }
    if (evencounter > 1)
        cout << 0 << nl;
    else if (evencounter == 1)
        cout << 1 << nl;
    else
        cout << 2 << nl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    smallestprimefac();
    while (t--) {
        solve();
    }
    return 0;
}