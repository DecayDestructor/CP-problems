#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define loop(s, n, inc) for (ll i = s; i < n; i += inc)
#define all(a) a.begin(), a.end()
#define py cout << "YES" << nl
#define pn cout << "NO" << nl
#define print(ans) cout << ans << nl
#define isEven(n) if (n % 2 == 0)
#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define vvll vector<vector<ll>>
#define vvch vector<vector<char>>
#define vvi vector<vi>
#define pi pair<int, int>
#define vch vector<char>
#define int long long
ll lcm(ll a, ll b) { return (a / __gcd(a, b)) * b; }
bool RSORT(ll a, ll b) {
    return a > b;
}
vector<int> factorization(int n) {
    vector<int> factors;
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
// Prime Factorization
map<int, int> primeFactorisation(ll n) {
    map<int, int> mpp;
    for (ll i = 2; i <= sqrt(n); i++) {
        while (n % i == 0) {
            mpp[i]++;
            n = n / i;
        }
    }
    if (n != 1)
        mpp[n]++;
    return mpp;
}
// Sieve of Eratosthenes
vector<ll> sieveOfEratosthenes(int n) {
    vector<ll> sieve(n + 1, 1);
    sieve[0] = sieve[1] = 0;  // 0 and 1 are not primes
    for (int i = 2; i * i <= n; i++) {
        if (sieve[i]) {
            for (int j = i * i; j <= n; j += i) {
                sieve[j] = 0;  // Mark multiples of i as non-prime
            }
        }
    }
    return sieve;  // Return the sieve vector
}
// Sum of first n natural numbers
ll sumOfNaturalNumbers(ll n) {
    return (1LL * n * (n + 1)) / 2;  // Formula to calculate the sum
}
// DFS Traversal Validation
bool isValidDfsTraversal(ll row, ll col, ll m, ll n, vector<vll>& visited) {
    return row < n && col < m && row >= 0 && col >= 0 && !visited[row][col];
}
// Binary Exponentiation
ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
ll mminvprime(ll a, ll m) {
    return binpow(a, m - 2, m);
}
ll mod_add(ll a, ll b, ll m) {
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
ll mod_mul(ll a, ll b, ll m) {
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m) {
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
ll mod_div(ll a, ll b, ll m) {
    a = a % m;
    b = b % m;
    return (mod_mul(a, mminvprime(b, m), m) + m) % m;
}

bool revLessUnique(const vector<int>& a,
                   const vector<int>& b,
                   const map<int, int>& mpp) {
    set<int> seenA, seenB;

    int i = (int)a.size() - 1;
    int j = (int)b.size() - 1;

    while (true) {
        while (i >= 0 &&
               (seenA.count(a[i]) || mpp.find(a[i]) == mpp.end()))
            i--;

        while (j >= 0 &&
               (seenB.count(b[j]) || mpp.find(b[j]) == mpp.end()))
            j--;

        if (i < 0 || j < 0) break;

        seenA.insert(a[i]);
        seenB.insert(b[j]);

        if (a[i] != b[j])
            return a[i] < b[j];

        i--;
        j--;
    }

    // count remaining valid unique elements
    int remA = 0, remB = 0;

    while (i >= 0) {
        if (!seenA.count(a[i]) && mpp.find(a[i]) != mpp.end()) {
            remA++;
            seenA.insert(a[i]);
        }
        i--;
    }

    while (j >= 0) {
        if (!seenB.count(b[j]) && mpp.find(b[j]) != mpp.end()) {
            remB++;
            seenB.insert(b[j]);
        }
        j--;
    }

    return remA < remB;
}

// returns index of best array among given indices
int smallestReverseLexIndex(const vector<vector<int>>& arr,
                            const vector<int>& idx,
                            const map<int, int>& mpp) {
    if (idx.empty()) return -1;

    int best = idx[0];

    for (int k = 1; k < (int)idx.size(); k++) {
        int cur = idx[k];
        if (revLessUnique(arr[cur], arr[best], mpp))
            best = cur;
    }

    return best;
}
int ceil_div(int a, int b) { return (a + b - 1) / b; }
void solve() {
    int n;
    cin >> n;
    vector<vi> arr;
    map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        vi temp(l);
        for (auto& it : temp) {
            cin >> it;
            mpp[it] = 1;
        }
        arr.push_back(temp);
    }
    // cout << "Current array status : " << nl;
    // for (auto& it : arr) {
    //     for (auto& jt : it) cout << jt << " ";
    //     cout << nl;
    // }
    vi ans;
    while (!mpp.empty()) {
        int mini = 1e9;
        vi index;
        // get all the minimum indexes
        for (int i = 0; i < n; i++) {
            while (arr[i].size() && mpp.find(arr[i].back()) == mpp.end()) arr[i].pop_back();  // remove used elements
            if (arr[i].size() && arr[i].back() < mini) {
                index.clear();
                index.push_back(i);
                mini = arr[i].back();
            } else if (arr[i].size() && arr[i].back() == mini) {
                index.push_back(i);
            }
        }
        // cout << "Current array status : " << nl;
        // for (auto& it : arr) {
        //     for (auto& jt : it) cout << jt << " ";
        //     cout << nl;
        // }
        // cout << "Minimum value amongst them is " << mini << " and the indexes: ";
        // for (auto& it : index) cout << it << " ";
        // cout << nl;
        int bestindex = smallestReverseLexIndex(arr, index, mpp);
        // cout << "Index of best array : " << bestindex << nl;
        // cout << "Best array : " << nl;
        vi temp = arr[bestindex];
        // for (auto& it : temp) cout << it << " ";
        // cout << nl;
        reverse(all(temp));
        for (auto& it : temp) {
            if (mpp.find(it) == mpp.end()) continue;
            ans.push_back(it);
            mpp.erase(it);
        }
    }
    // cout << "answer ";
    for (auto& it : ans) cout << it << " ";
    cout << nl;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}