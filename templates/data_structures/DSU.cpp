#include <bits/stdc++.h>
typedef int64_t ll;

struct DSU {
    vector<int> rank, parent;
    int forsets;

    DSU(int n) {
        rank = parent = vector<int>(n + 1, 1);
        forsets = n;
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int find_parent(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_parent(parent[v]);
    }

    void link(int par, int node) {
        parent[node] = par;
        if (rank[par] == rank[node])
            rank[par]++;
        forsets--;
    }

    bool merge(int v, int u) {
        v = find_parent(v), u = find_parent(u);
        if (v != u)
        {
            if (rank[v] < rank[u])
                swap(v, u);
            link(v, u);
        }
        return v != u;
    }
};
