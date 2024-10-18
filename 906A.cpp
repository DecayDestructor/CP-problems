#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

int n;

void solve()
{
    vector<int> arr(n);
    set<int> stt;
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        stt.insert(arr[i]);
        mpp[arr[i]]++;
    }
    if (stt.size() > 2)
    {
        cout << "no\n";
    }
    else
    {
        int counter1 = 1;
        int counter2 = 0;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] == arr[0])
                counter1++;
            else
                counter2++;
        }
        if (abs(counter1 - counter2) <= 1 || counter1 == n)
            cout << "yes\n";
        else
            cout << "no\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        solve();
    }
    return 0;
}
