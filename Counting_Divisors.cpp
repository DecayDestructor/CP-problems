#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define nl "\n"

const int N = 1e6;
vi precomp(N + 1, 0);

void precompute() {
    // Using divisor sieve
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            precomp[j]++;  // i divides j
        }
    }
}

void solve() {
    int n;
    cin >> n;
    cout << precomp[n] << nl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    precompute();  // O(N log N)

    while (t--) {
        solve();
    }
    return 0;
}
