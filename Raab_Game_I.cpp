#include <bits/stdc++.h>
using namespace std;
#define int long long

#define test_case
void solution() {
    int n, a, b;
    cin >> n >> a >> b;
    if (a + b > n) {
        cout << "NO";
        return;
    }
    vector<int> A(n);
    iota(begin(A), end(A), 1);
    vector<int> B(n, 0);
    set<int> vis;
    for (int i = b; i < n - a; ++i)
        B[i] = A[i], vis.insert(A[i]);
    int nn = n;
    for (int i = b - 1; ~i; --i) {
        while (vis.count(nn))
            --nn;
        B[i] = nn;
        vis.insert(nn);
    }
    nn = 1;
    for (int i = n - a; i < n; ++i) {
        while (vis.count(nn))
            ++nn;
        B[i] = nn;
        vis.insert(nn);
    }
    for (int i = 0; i < n; ++i) {
        if (!(1 <= B[i] and B[i] <= n)) {
            cout << "NO";
            return;
        }
        if (A[i] > B[i])
            --a;
        else if (A[i] < B[i])
            --b;
    }
    if (max(a, b)) {
        cout << "NO";
        return;
    }
    cout << "YES\n";
    for (int x : A)
        cout << x << ' ';
    cout << '\n';
    for (int x : B)
        cout << x << ' ';
}
int32_t main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int32_t t = 1;
#ifdef test_case
    cin >> t;
#endif
    while (t--) {
        solution();
        cout << "\n";
    }
}