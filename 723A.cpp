#include <bits/stdc++.h>
using namespace std;
int main()
{

    int x1, x2, x3;
    cin >> x1 >> x2 >> x3;
    int left = min(x1, min(x2, x3));
    int right = max(x1, max(x2, x3));
    int distance = INT_MAX;
    for (; left <= right; left++)
    {
        int sum = abs(x1 - left) + abs(x2 - left) + abs(x3 - left);
        distance = min(distance, sum);
    }
    cout << distance << endl;

    return 0;
}