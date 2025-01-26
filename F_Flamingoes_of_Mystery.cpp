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

void query(int l, int r) {
    cout << "? " << l << ' ' << r << endl;
    fflush(stdout);
}
int main() {
    init;
    int n;
    cin >> n;
    int ar[n];

    for (int i = 2; i <= n; i++) {
        query(1, i);
        cin >> ar[i - 1];
    }

    query(2, n);
    cin >> ar[0];

    ar[0] = ar[n - 1] - ar[0];
    for (int i = n - 1; i > 0; i--)
        ar[i] -= ar[i - 1];

    cout << "! ";
    for (int i = 0; i < n; i++)
        cout << ar[i] << ' ';
}