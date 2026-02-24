class Solution {
public:
    int findParent(int x, vector<int>& parent) {
        if(parent[x] == x) return x;
        return parent[x] = findParent(parent[x], parent);
    }
    
    void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
        int pu = findParent(u, parent);
        int pv = findParent(v, parent);
        
        if(pu == pv) return;
        
        if(rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if(rank[pv] < rank[pu]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
    
    int spanningTree(int V, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b){
            return a[2] < b[2];
        });
        
        vector<int> parent(V), rank(V, 0);
        for(int i = 0; i < V; i++) parent[i] = i;
        
        int sum = 0;
        
        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            
            if(findParent(u, parent) != findParent(v, parent)) {
                sum += w;
                unionSet(u, v, parent, rank);
            }
        }
        
        return sum;
    }
};