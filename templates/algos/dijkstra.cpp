#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> dijkstra(int source, const vector<vector<pair<int, int>>> &graph) {
	int n = graph.size();
	vector<ll> dist(n, LLONG_MAX);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[source] = 0;
	pq.push({0, source});
	while (!pq.empty()) {
		auto [d, u] = pq.top();
		pq.pop();
		if (d != dist[u])
			continue;
		for (auto [v, w] : graph[u])
			if (dist[u] + w < dist[v])
			{
				dist[v] = dist[u] + w;
				pq.push({dist[v], v});
			}
	}
	return dist;
}