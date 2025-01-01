#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define ull unsigned long long
#define pb push_back

bool isPerfectSquare(int n) {
    int s = sqrt(n);
    return (s * s == n);
}

int main() {
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        if (n % 2 == 0) {
            for (int i = 1; i <= n / 2; i++) {
                cout << i << " " << i << " ";
            }
            cout << endl;

        } else if (n % 2 == 1 && n >= 27) {
            cout << "1 3 3 4 4 5 5 6 6 1 2 7 7 8 8 9 9 10 10 11 11 12 12 13 13 1 2 ";
            for (int i = 14; i <= n / 2; i++) cout << i << " " << i << " ";
            cout << endl;
        } else
            cout << -1 << endl;
    }

    return 0;
}