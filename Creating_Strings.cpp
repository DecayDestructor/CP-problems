#include <bits/stdc++.h>
using namespace std;

string s;
vector<string> results;
vector<bool> used;

void backtrack(string &current, map<char, int> &freq, int n) {
    if ((int)current.size() == n) {
        results.push_back(current);
        return;
    }
    for (auto &p : freq) {
        char c = p.first;
        int count = p.second;
        if (count > 0) {
            current.push_back(c);
            freq[c]--;
            backtrack(current, freq, n);
            freq[c]++;
            current.pop_back();
        }
    }
}

int main() {
    cin >> s;
    map<char, int> freq;
    for (char c : s) freq[c]++;

    string current;
    backtrack(current, freq, s.size());

    cout << results.size() << "\n";
    for (auto &str : results) cout << str << "\n";
    return 0;
}
