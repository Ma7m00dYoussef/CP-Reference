#include <bits/stdc++.h>
using namespace std;
struct Mo {

	struct Query {
		int l, r, idx;
	};

	int n;
	int SQ;
	vector<Query> queries;

	Mo(int n) : n(n) {
		SQ = ceil(sqrt(n));
	}

	void add_query(int l, int r, int idx) {
		queries.push_back({l, r, idx});
	}

	void build() {
		sort(queries.begin(), queries.end(), [&](const Query &a, const Query &b) {

			int block_a = a.l / SQ;
			int block_b = b.l / SQ;

			if (block_a != block_b)
				return block_a < block_b;

			if (block_a & 1)
				return a.r > b.r;

			return a.r < b.r;
		});
	}

	void update(int i, int delta) {
		// Update the contribution of index i.
		// delta > 0 : add.
		// delta < 0 : remove.
	}

	void answer(int query_idx) {
		// Store the answer for query_idx.
	}

	void process() {

		build();

		int L = 0;
		int R = -1;

		for (auto [l, r, idx] : queries) {

			while (L > l)
				update(--L, +1);

			while (R < r)
				update(++R, +1);

			while (L < l)
				update(L++, -1);

			while (R > r)
				update(R--, -1);

			answer(idx);
		}
	}
};