vector<vector<int>> adj, comps;
vector<int> dfn, low, compId;
vector<bool> inStack;
stack<int> stk;
int timer;
void dfs(int node) {
    dfn[node] = low[node] = ++timer;
    stk.push(node);
    inStack[node] = 1;

    for (int child : adj[node]) {
        if (!dfn[child]) {
            dfs(child);
            low[node] = min(low[node], low[child]);
        } else if (inStack[child]) {
            low[node] = min(low[node], dfn[child]);
        }
    }

    if (dfn[node] == low[node]) {
        comps.push_back(vector<int>());
        int v = -1;
        while (v != node) {
            v = stk.top();
            stk.pop();
            inStack[v] = 0;
            comps.back().push_back(v);
            compId[v] = comps.size() - 1;
        }
    }
}

void tarjan() {
    timer = 0;
    dfn = low = compId = vector<int>(adj.size());
    inStack = vector<bool>(adj.size());
    comps = vector<vector<int>>();
    for (int node = 1; node < (int)adj.size(); node++) {
        if (!dfn[node]) {
            dfs(node);
        }
    }
}
//
timer = 0;
vector<int> dfn, low;

void tarjan_bridges(int node, int par) {
    dfn[node] = low[node] = ++timer;
    for (auto &child : adj[node]) {
        if (!dfn[child]) {
            tarjan_bridges(child, node);
            low[node] = min(low[node], low[child]);
            if (low[child] > dfn[node]) {
                // edge(node, child) is a bridge
            }
        } else if (child != par) {
            low[node] = min(low[node], dfn[child]);
        }
    }
}
//
void tarjan_artpoints(int node, int par) {
    dfn[node] = low[node] = ++timer;
    int children = 0;

    for (auto &child : adj[node]) {
        if (!dfn[child]) {
            children++;
            tarjan_artpoints(child, node);
            low[node] = min(low[node], low[child]);

            if (par != -1 && low[child] >= dfn[node]) {
                // node is an articulation point
            }
        } else if (child != par) {
            low[node] = min(low[node], dfn[child]);
        }
    }

    if (par == -1 && children > 1)
        // node (root) is ans articulation point
            ;
}