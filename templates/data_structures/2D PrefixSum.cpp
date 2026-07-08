#include <bits/stdc++.h>
using namespace std;
// 2D Prefix Sum
// ------------------------------------------------------------
// Assumptions:
// - The input matrix is 1-based.
// - a[0][*] and a[*][0] are dummy rows/columns.
// - Valid indices are:
//     rows: 1 .. n
//     cols: 1 .. m
//
// Query:
// - query(pref, x1, y1, x2, y2)
// - Returns the sum of the rectangle:
//     rows [x1..x2], cols [y1..y2] (inclusive)
// - All coordinates are 1-based.
// ------------------------------------------------------------

vector<vector<long long>> build_prefix(const vector<vector<int>> &a) {
	int n = a.size() - 1;
	int m = a[0].size() - 1;

	vector<vector<long long>> pref(n + 1, vector<long long>(m + 1));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			// Sum of rectangle (1,1) -> (i,j)
			pref[i][j] = a[i][j]
				   + pref[i - 1][j]
				   + pref[i][j - 1]
				   - pref[i - 1][j - 1];
		}
	}

	return pref;
}

// Returns the sum of rectangle:
// rows [x1..x2], cols [y1..y2] (inclusive)
// All indices are 1-based.
long long query(const vector<vector<long long>> &pref,
		int x1, int y1, int x2, int y2) {
	return pref[x2][y2]
	     - pref[x1 - 1][y2]
	     - pref[x2][y1 - 1]
	     + pref[x1 - 1][y1 - 1];
}