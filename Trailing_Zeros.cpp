#include <iostream>
using namespace std;
int solve(int N) {
    if (N == 0) {
        return 0;
    }
    return N / 5 + solve(N / 5);
}

int main() {
    int N;
    cin >> N;
    cout << solve(N) << "\n";
    return 0;
}