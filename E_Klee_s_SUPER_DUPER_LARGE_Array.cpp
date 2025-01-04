#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define loop(n) for (int i = 0; i < n; i++)
#define py cout << "YES" << nl
#define pn cout << "NO" << nl
#define print(ans) cout << ans << nl
#define isEven(n) if (n % 2 == 0)
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<char> vch;
template <typename T1, typename T2>
using vpp = vector<pair<T1, T2>>;
// Template functions for input and output
template <typename T>
void inputArray(vector<T> &arr, int n) {
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

template <typename T>
void outputArray(vector<T> &arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << nl;
    }
}
template <typename T>
vector<T> factorization(int n) {
    vector<T> factors;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            factors.push_back(i);
            if (i * i != n) {
                factors.push_back(n / i);
            }
        }
    }
    return factors;
}
ll n_sum(ll n) {
    return (n * (n + 1)) / 2;
}
void solve() {
    ll n, x;
    cin >> n >> x;
    // cout << n << " " << x << nl;
    ll total_sum = n_sum(x + n - 1) - n_sum(x - 1);
    ll left = 0;
    ll right = n - 1;
    ll answer = LLONG_MIN;
    // cout << total_sum << " " << right << " " << left << nl;
    ll final_answer = LLONG_MAX;
    while (left <= right) {
        // cout << "current answer is " << answer << nl;
        ll middle = (left + right) / 2;
        // cout << middle << nl;
        ll sum = n_sum(x + middle) - n_sum(x - 1);
        // ll required_sum1 = n_sum(x + middle) - n_sum(x - 1);
        ll required_sum2 = total_sum - sum;
        final_answer = min(abs(sum - required_sum2), final_answer);
        // cout << sum << nl;
        if (sum == total_sum / 2) {
            answer = middle + 1;
            break;
        } else if (sum < total_sum / 2) {
            left = middle + 1;
            answer = max(answer, middle + 1);
        } else if (sum > total_sum / 2) {
            right = middle - 1;
        }
    }

    // cout << required_sum1 << " " << required_sum2 << nl;
    // cout << abs(required_sum1 - required_sum2) << nl;
    cout << final_answer << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}