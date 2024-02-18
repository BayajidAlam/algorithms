#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int par[N];

void dsu_initialize(int n) {
    for (int i = 0; i < n; i++) {
        par[i] = i;
    }
}

int dsu_find(int node) {
    if (par[node] == node)
        return node;
    return par[node] = dsu_find(par[node]);
}

bool dsu_union(int node1, int node2) {

    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    
    if (leaderA != leaderB) {
        par[leaderA] = leaderB;
        return false;
    }
    return true;
}

int main() {
    int n, e;
    cin >> n >> e;

    dsu_initialize(n);
    int cycle_edges = 0;

    for(int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        if (dsu_union(a, b)) cycle_edges++;
    }

    cout << cycle_edges << endl;
    return 0;
}