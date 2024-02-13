#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<pair<int, int>> v[N];

class cmp {
public:
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

void dijkstra(int src, int n) {
    int dis[N];
    for (int i = 0; i <= n; i++) {
        dis[i] = INT_MAX;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push({src, 0});
    dis[src] = 0;

    while (!pq.empty()) {
        pair<int, int> parent = pq.top();
        pq.pop();
        int node = parent.first;
        int cost = parent.second;
        for (pair<int, int> child : v[node]) {
            int childNode = child.first;
            int childCost = child.second;
            if (cost + childCost < dis[childNode]) {
                dis[childNode] = cost + childCost;
                pq.push({childNode, dis[childNode]});
            }
        }
    }

    int tt;
    cin >> tt;

    for (int i = 0; i < tt; i++) {
        int des, cost;
        cin >> des >> cost;
        if (dis[des] <= cost)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }

    int src;
    cin >> src;

    dijkstra(src, n);

    return 0;
}
