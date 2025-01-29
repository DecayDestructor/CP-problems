#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define mod 1000000007
#define init ios::sync_with_stdio(0), cin.tie(0);
typedef vector<int> vi;
typedef pair<int, int> pi;
#define MS(x, y) memset(x, y, sizeof(x))
#define F first
#define S second
#define PB push_back
#define MP make_pair
vector<long long> prefix = {0, 1, 5, 9, 15, 22, 30};
int query(int l, int r) {
    cout << "? " << l << ' ' << r << endl;
    return prefix[r] - prefix[l - 1];
    fflush(stdout);
}
int main() {
    init;
    int n;
    cin >> n;
    int ar[n];

    for (int i = 2; i <= n; i++) {
        ar[i - 1] = query(1, i);
    }

    ar[0] = query(2, n);

    ar[0] = ar[n - 1] - ar[0];
    for (int i = n - 1; i > 0; i--)
        ar[i] -= ar[i - 1];

    cout << "! ";
    for (int i = 0; i < n; i++)
        cout << ar[i] << ' ';
}