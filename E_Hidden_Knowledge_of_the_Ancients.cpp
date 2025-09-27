#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define ll long long
#define vi vector<int>
#define int long long

map<int, int> mpp;
int n, k, l, r;
vi arr;

int countSub(int k1) {
    mpp.clear();
    int left = 0, right = 0;
    while (right < l) {
        mpp[arr[right++]]++;
    }
    int count = 0;
    while (right < n && left < n) {
        if (right - left < l) {
            mpp[arr[right]]++;
            right++;
        } else if (right - left > r) {
            mpp[arr[left]]--;
            if (!mpp[arr[left]]) mpp.erase(arr[left]);
            left++;
        } else if (mpp.size() >= k1) {
            int curr = right - left;
            int maxExtend = min(r, n - left) - curr;
            count += maxExtend + 1;
            mpp[arr[left]]--;
            if (!mpp[arr[left]]) mpp.erase(arr[left]);
            left++;
        } else {
            mpp[arr[right++]]++;
        }
    }
    while (left < n) {
        if (mpp.size() >= k1 && right - left >= l && right - left <= r) {
            count++;
        }
        mpp[arr[left]]--;
        if (!mpp[arr[left]]) mpp.erase(arr[left]);
        left++;
    }
    return count;
}

void solve() {
    cin >> n >> k >> l >> r;
    arr.assign(n, 0ll);
    for (auto &it : arr) cin >> it;
    int ge = countSub(k);
    int g = countSub(k + 1);
    cout << ge - g << nl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
