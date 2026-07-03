#include <bits/stdc++.h>
typedef long long ll;
const int N = 1e5 + 5 , LOG = 16 ;
vector<int> adj[N];
int lvl[N];
int up[N][LOG];
struct LCA
{

	LCA()
	{
		dfs(1, -1);
	}

	void dfs(int node, int par)
	{
		for (int i = 1; i < LOG; i++)
			up[node][i] = up[up[node][i - 1]][i - 1];

		for (auto &ch : adj[node])
		{
			if (ch == par)
				continue;

			up[ch][0] = node;
			lvl[ch] = lvl[node] + 1;

			dfs(ch, node);
		}
	}

	int getKthParent(int node, int k)
	{
		for (int i = LOG - 1; i >= 0; i--)
		{
			if ((k >> i) & 1)
				node = up[node][i];
		}
		return node;
	}

	int lca(int a, int b)
	{
		if (lvl[a] < lvl[b])
			swap(a, b);

		a = getKthParent(a, lvl[a] - lvl[b]);

		if (a == b)
			return a;

		for (int i = LOG - 1; i >= 0; i--)
			for (int i = LOG - 1; i >= 0; i--)
			{
				if (up[a][i] != up[b][i])
					a = up[a][i], b = up[b][i];
			}

		return up[a][0];
	}
};