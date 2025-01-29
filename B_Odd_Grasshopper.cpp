#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        long long x0, n;
        cin >> x0 >> n;

        long long ans = 0;
        if (n % 4 == 0) {
            ans = x0;
        } else if (n % 4 == 1) {
            ans = (x0 % 2 == 0 ? x0 - n : x0 + n);
        } else if (n % 4 == 2) {
            ans = (x0 % 2 == 0 ? x0 + 1 : x0 - 1);
        } else {
            long long m = ((n + 3) / 4) * 4;
            ans = (x0 % 2 == 0 ? x0 + m : x0 - m);
        }
        cout << ans << '\n';
    }
    return 0;
}