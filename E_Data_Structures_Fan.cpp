#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }

        string s;
        cin >> s;
        s = "0" + s;  // 1-indexed

        int q;
        cin >> q;

        vector<int> ans(2, 0);
        vector<int> pref(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            ans[s[i] - '0'] ^= a[i];
            pref[i] = pref[i - 1] ^ a[i];
        }

        int massxor = 0;

        while (q--) {
            int type;
            cin >> type;

            if (type == 1) {
                int l, r;
                cin >> l >> r;
                massxor ^= pref[r] ^ pref[l - 1];
            } else {
                int g;
                cin >> g;
                cout << (massxor ^ ans[g]) << " ";
            }
        }
        cout << nl;
    }

    return 0;
}
