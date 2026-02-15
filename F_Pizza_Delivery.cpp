#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
#define vi vector<int>
#define vvi vector<vi>
#define int long long
int dist(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}
void solve() {
    int n, ax, ay, bx, by;
    cin >> n >> ax >> ay >> bx >> by;
    // dp[i][0] = ans if we enter from top, //dp[i][1] = ans if we enter from bottom
    vi x(n), y(n);
    map<int, pair<int, int>> mpp;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }
    for (int i = 0; i < n; i++) {
        if (mpp.find(x[i]) == mpp.end()) {
            mpp[x[i]] = {y[i], y[i]};
        }
        mpp[x[i]].first = min(mpp[x[i]].first, y[i]);
        mpp[x[i]].second = max(mpp[x[i]].second, y[i]);
    }
    vi x2;
    for (auto& it : mpp) x2.push_back(it.first);
    int n2 = x2.size();
    vector<vi> dp(n2, vi(2));
    dp[0][0] = dist(ax, ay, x2[0], mpp[x2[0]].second) + mpp[x2[0]].second - mpp[x2[0]].first;
    dp[0][1] = dist(ax, ay, x2[0], mpp[x2[0]].first) + mpp[x2[0]].second - mpp[x2[0]].first;
    for (int i = 1; i < n2; i++) {
        int len = mpp[x2[i]].second - mpp[x2[i]].first;
        int x1 = x2[i - 1];
        int bottop = dist(x1, mpp[x1].first, x2[i], mpp[x2[i]].second) + dp[i - 1][0] + len;
        int toptop = dist(x1, mpp[x1].second, x2[i], mpp[x2[i]].second) + dp[i - 1][1] + len;
        int botbot = dist(x1, mpp[x1].first, x2[i], mpp[x2[i]].first) + dp[i - 1][0] + len;
        int topbot = dist(x1, mpp[x1].second, x2[i], mpp[x2[i]].first) + dp[i - 1][1] + len;
        dp[i][0] = min(bottop, toptop);
        dp[i][1] = min(topbot, botbot);
    }
    int len1 = dp[n2 - 1][0] + dist(bx, by, x2[n2 - 1], mpp[x2[n2 - 1]].first);
    int len2 = dp[n2 - 1][1] + dist(bx, by, x2[n2 - 1], mpp[x2[n2 - 1]].second);
    cout << min(len1, len2) << nl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) {
        // cout << "answer ";
        solve();
    }
    return 0;
}