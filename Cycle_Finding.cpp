#include <bits/stdc++.h>
#define ll long long int
#define INF 1000000000000000
#define pb push_back
using namespace std;

// Adjacency List to store the weighted graph
vector<pair<ll, ll> > graph[2501];
// array to store the distance to any node
ll dist[2501];
// array to store the parent of any node
ll par[2501];
// array to store the number of time a node has been relaxed
ll cnt[2501];
ll n, m, u, v, w;
// array to keep track of whether a node is already in the queue
bool in_queue[2501];
// array to keep track of visited nodes
bool visited[2501];
ll x;

// Function to run Shortest Path Fast Algorithm
bool spfa(ll start) {
    // Initialize the distance of starting node = 0
    dist[start] = 0;
    // Initialize the parent of starting node = -1
    par[start] = -1;
    // Queue to run SPFA
    queue<ll> q;
    // Push the starting node in the queue
    q.push(start);
    in_queue[start] = true;

    while (!q.empty()) {
        // Pop the front element of the queue
        ll ele = q.front();
        visited[ele] = true;
        in_queue[ele] = false;
        q.pop();

        // Iterate over all the children of the current node
        for (auto child : graph[ele]) {
            // If the distance to the child node is greater
            // than the distance of the current node + edge weight,
            // then relax the child node
            if (dist[child.first] > dist[ele] + child.second) {
                // Increment the relaxation count of the child node
                cnt[child.first]++;
                // If the child has been relaxed more than n times,
                // then there is a cycle
                if (cnt[child.first] > n) {
                    x = child.first;
                    par[child.first] = ele;
                    return false;
                }
                // Update the minimum distance to the child node
                dist[child.first] = dist[ele] + child.second;
                // Push the child node if it is already not in queue
                if (!in_queue[child.first]) {
                    q.push(child.first);
                    in_queue[child.first] = true;
                }
                // Update the parent of the child node with the current node
                par[child.first] = ele;
            }
        }
    }
    return true;
}

void reset_arrays() {
    // Reset all arrays for multiple test cases
    for (int i = 0; i <= n; i++) {
        graph[i].clear();
        dist[i] = INF;
        par[i] = -1;
        cnt[i] = 0;
        in_queue[i] = false;
        visited[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read number of nodes and edges
    cin >> n >> m;

    // Initialize arrays
    reset_arrays();

    // Read edges
    for (ll i = 0; i < m; i++) {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    // Check for negative cycle from each node
    for (ll i = 1; i <= n; i++) {
        // If there is a negative weight cycle in the graph
        if (!spfa(i)) {
            cout << "YES" << endl;
            ll ele = x;
            stack<ll> st;
            bool is_stack[2501] = {};

            // Push all the elements in the stack using the parent array
            while (!is_stack[ele]) {
                is_stack[ele] = true;
                st.push(ele);
                ele = par[ele];
            }

            // Print all the nodes in the negative weight cycle
            cout << ele << " ";
            while (st.top() != ele) {
                cout << st.top() << " ";
                st.pop();
            }
            cout << ele << endl;
            return 0;
        }

        // Reset for next iteration
        for (int j = 1; j <= n; j++) {
            dist[j] = INF;
            par[j] = -1;
            cnt[j] = 0;
            in_queue[j] = false;
            visited[j] = false;
        }
    }

    cout << "NO" << endl;
    return 0;
}