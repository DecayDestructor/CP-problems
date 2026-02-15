#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long y, x;
        cin >> y >> x;

        long long k = max(y, x);
        long long ans;

        if (k % 2 == 0) {
            if (y == k)
                ans = k * k - (x - 1);
            else
                ans = (k - 1) * (k - 1) + y;
        } else {
            if (x == k)
                ans = k * k - (y - 1);
            else
                ans = (k - 1) * (k - 1) + x;
        }

        cout << ans << '\n';
    }
    return 0;
}
