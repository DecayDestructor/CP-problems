#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::pair;
using std::vector;

// BeginCodeSnip{DSU (from the module)}
class DisjointSets {
   private:
    vector<int> parents;
    vector<int> sizes;

   public:
    DisjointSets(int size) : parents(size), sizes(size, 1) {
        for (int i = 0; i < size; i++) {
            parents[i] = i;
        }
    }

    int find(int x) { return parents[x] == x ? x : (parents[x] = find(parents[x])); }

    bool unite(int x, int y) {
        int x_root = find(x);
        int y_root = find(y);
        if (x_root == y_root) {
            return false;
        }

        if (sizes[x_root] < sizes[y_root]) {
            std::swap(x_root, y_root);
        }
        sizes[x_root] += sizes[y_root];
        parents[y_root] = x_root;
        return true;
    }

    bool connected(int x, int y) { return find(x) == find(y); }
};
// EndCodeSnip

int main() {
    int city_num;
    int road_num;
    std::cin >> city_num >> road_num;

    struct Road {
        int c1, c2;
        int cost;
    };
    vector<Road> roads(road_num);
    for (Road& r : roads) {
        std::cin >> r.c1 >> r.c2 >> r.cost;
        r.c1--;
        r.c2--;
    }
    std::sort(roads.begin(), roads.end(),
              [&](const Road& e1, const Road& e2) { return e1.cost < e2.cost; });

    DisjointSets cities(city_num);
    long long min_cost = 0;
    int added = 0;
    for (Road& r : roads) {
        bool status = cities.unite(r.c1, r.c2);
        min_cost += status * r.cost;
        added += status;
    }

    if (added != city_num - 1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << min_cost << endl;
    }
}