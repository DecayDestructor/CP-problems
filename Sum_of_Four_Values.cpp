#include <bits/stdc++.h>
#define ll long long int

using namespace std;

// function to find a quadruplet whose sum = X
void solve(vector<ll>& arr, ll X, ll N) {
    // vector to store the values along with their indices
    vector<vector<ll>> vec(N, vector<ll>(2));

    for (int i = 0; i < N; i++) {
        vec[i][0] = arr[i];
        vec[i][1] = i + 1;
    }

    // Sort the vector in increasing order of the values
    sort(vec.begin(), vec.end());

    // Iterate for all possible values of first element
    for (ll ptr1 = 0; ptr1 < N - 3; ptr1++) {
        // Iterate for all possible values of second element
        for (ll ptr2 = ptr1 + 1; ptr2 < N - 2; ptr2++) {
            // Maintain two pointers for the third and
            // fourth element
            ll ptr3 = ptr2 + 1;
            ll ptr4 = N - 1;
            while (ptr3 < ptr4) {
                ll currentSum = vec[ptr1][0] + vec[ptr2][0] + vec[ptr3][0] + vec[ptr4][0];

                // If current sum is equal to X, then we
                // have found a quadruplet whose sum = X
                if (currentSum == X) {
                    cout << vec[ptr1][1] << " "
                         << vec[ptr2][1] << " "
                         << vec[ptr3][1] << " "
                         << vec[ptr4][1] << "\n";
                    return;
                }

                // Decrease the currentSum by moving ptr4 to
                // ptr4 - 1
                else if (currentSum > X) {
                    ptr4--;
                }

                // Increase the currentSum by moving ptr3 to
                // ptr3 + 1
                else if (currentSum < X) {
                    ptr3++;
                }
            }
        }
    }
    // If no quadruplet has sum = X, print "IMPOSSIBLE"
    cout << "IMPOSSIBLE";
}

int main() {
    // Sample Input
    ll N = 6, X = 20;
    vector<ll> arr = {3, 4, 5, 6, 7, 8};

    solve(arr, X, N);
    // your code goes here
    return 0;
}