#include <bits/stdc++.h>
using namespace std;

// Function to get all factors of a number
vector<int> getFactors(int n) {
    vector<int> factors;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            factors.push_back(i);
            if (i != n / i)
                factors.push_back(n / i);
        }
    }
    return factors;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> A(n), B(n);

    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) cin >> B[i];

    // Step 1: Build factor map for A
    unordered_map<int, int> factorMap;  // factor -> max element in A with that factor
    for (int x : A) {
        vector<int> factors = getFactors(x);
        for (int f : factors) {
            auto it = factorMap.find(f);
            if (it == factorMap.end() || it->second < x)
                factorMap[f] = x;
        }
    }

    int maxGCD = 0, maxSum = 0;

    // Step 2: Check for each element in B
    for (int y : B) {
        vector<int> factors = getFactors(y);
        for (int f : factors) {
            auto it = factorMap.find(f);
            if (it != factorMap.end()) {
                int x = it->second;
                int sum = x + y;
                if (f > maxGCD || (f == maxGCD && sum > maxSum)) {
                    maxGCD = f;
                    maxSum = sum;
                }
            }
        }
    }

    cout << maxSum << "\n";
    return 0;
}
