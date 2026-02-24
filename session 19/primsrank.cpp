#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, rankv;

    DSU(int n) {
        parent.resize(n);
        rankv.resize(n, 0);
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findParent(int x) {
        if(parent[x] == x)
            return x;
        return parent[x] = findParent(parent[x]);
    }

    void unionByRank(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv) return;

        if(rankv[pu] < rankv[pv]) {
            parent[pu] = pv;
        }
        else if(rankv[pv] < rankv[pu]) {
            parent[pv] = pu;
        }
        else {
            parent[pv] = pu;
            rankv[pu]++;
        }
    }
};

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges;

    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b){
        return a[2] < b[2];
    });

    DSU dsu(V);
    int mstWeight = 0;

    for(auto &e : edges) {
        int u = e[0];
        int v = e[1];
        int w = e[2];

        if(dsu.findParent(u) != dsu.findParent(v)) {
            mstWeight += w;
            dsu.unionByRank(u, v);
        }
    }

    cout << mstWeight << endl;

    return 0;
}