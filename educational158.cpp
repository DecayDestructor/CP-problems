#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, x;
        cin >> n >> x;
        int *fuelStations = new int[n];
        int distance = INT_MIN;
        int left = 0;
        for (int j = 0; j < n; j++)
        {
            cin >> fuelStations[j];

            distance = max(distance, fuelStations[j] - left);

            left = fuelStations[j];
        }
        cout << max(distance, (x - fuelStations[n - 1]) * 2) << endl;
    }
    return 0;
}