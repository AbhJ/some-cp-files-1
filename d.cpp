class Solution {
public:
    int parent[1000],ind[1000];
    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }
    void make_set(int v) {
        parent[v] = v;
        ind[v] = rand();
    }
    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (ind[a] < ind[b])
                swap(a, b);
            parent[b] = a;
        }
    }
    vector<vector<int>>A;
    int v[1000];
    void dfs(int u){
        if(v[u] == 1)return;
        v[u] = 1;
        for(auto &i: A[u])if(v[i] != 1)dfs(i);
    }
    int minimumTeachings(int n, vector<vector<int>>& a, vector<vector<int>>& b) {
        int vis[1000];
        A.resize(1000, vector<int>());
        fill(vis, vis + 1000, 0);
        for(int i = 0; i < 1000; i++)make_set(i);
        for(auto &i: b)
            for(auto &f: a[i[0] - 1])
                for(auto &s: a[i[1] - 1])
                    A[f].push_back(s), A[s].push_back(f);
        set<int>S;
        int cnt = 0;
        for(int i = 0; i < 1000; i++)if(vis[i] == 1 and v[i] == 0)dfs(i), cnt++;
        return cnt;
    }
};