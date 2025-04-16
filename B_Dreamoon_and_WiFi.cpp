#include <bits/stdc++.h>
using namespace std;

double nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    double res = 1;
    for (int i = 1; i <= r; ++i) {
        res *= (n - i + 1);
        res /= i;
    }
    return res;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int target = 0, current = 0, qCount = 0;

    for (char c : s1)
        target += (c == '+' ? 1 : -1);

    for (char c : s2) {
        if (c == '+')
            current++;
        else if (c == '-')
            current--;
        else
            qCount++;
    }

    int diff = target - current;

    // Check if it’s even and possible
    if ((qCount + diff) % 2 != 0 || abs(diff) > qCount) {
        cout << fixed << setprecision(12) << 0.0 << "\n";
        return 0;
    }

    int plusCount = (qCount + diff) / 2;
    double probability = nCr(qCount, plusCount) / pow(2, qCount);

    cout << fixed << setprecision(12) << probability << "\n";
    return 0;
}
