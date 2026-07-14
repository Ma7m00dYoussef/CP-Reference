#include <bits/stdc++.h>
using namespace std;
// 0-based , r included
template<typename T>
struct PST {
	struct Node {
		T val;
		Node *l, *r;

		Node(T v = 0) : val(v), l(nullptr), r(nullptr) {}

		Node(Node *L, Node *R) : l(L), r(R) {
			val = (L ? L->val : 0) + (R ? R->val : 0);
		}
	};
	int n;
	vector<Node*> root;

	PST(const vector<T> &a) {
		n = a.size();
		root.push_back(build(0, n - 1, a));
	}

	Node* build(int lx, int rx, const vector<T> &a) {
		if (lx == rx)
			return new Node(a[lx]);

		int mid = (lx + rx) >> 1;

		return new Node(
		    build(lx, mid, a),
		    build(mid + 1, rx, a)
		);
	}

	Node* update(Node *cur, int idx, T val, int lx, int rx) {
		if (lx == rx)
			return new Node(val);

		int mid = (lx + rx) >> 1;

		if (idx <= mid)
			return new Node(
			    update(cur->l, idx, val, lx, mid),
			    cur->r
			);

		return new Node(
		    cur->l,
		    update(cur->r, idx, val, mid + 1, rx)
		);
	}

	T query(Node *cur, int l, int r, int lx, int rx) {
		if (rx < l || r < lx)
			return 0;

		if (l <= lx && rx <= r)
			return cur->val;

		int mid = (lx + rx) >> 1;

		return query(cur->l, l, r, lx, mid)
		     + query(cur->r, l, r, mid + 1, rx);
	}

	void update(int base_v, int idx, T val) {
		root.push_back(
		    update(root[base_v], idx, val, 0, n - 1)
		);
	}
	T query(int version, int l, int r) {
		return query(root[version], l, r, 0, n - 1);
	}

// * Returns the index of the k-th smallest element
// * between two versions.
// *
// * leftRoot  = version before the range.
// * rightRoot = version after the range.
// *
// * Example:
// * version[l - 1]
// * version[r]
// *
// * Returns the compressed value index.
// *
// * Complexity: O(log N)
// *
	int kth(Node *leftRoot, Node *rightRoot, int k, int lx, int rx) {
		if (lx == rx)
			return lx;

		int mid = (lx + rx) >> 1;

		int leftCnt =
		    (rightRoot->l ? rightRoot->l->val : 0) -
		    (leftRoot->l ? leftRoot->l->val : 0);

		if (k <= leftCnt)
			return kth(leftRoot->l, rightRoot->l, k, lx, mid);

		return kth(
		    leftRoot->r,
		    rightRoot->r,
		    k - leftCnt,
		    mid + 1,
		    rx
		);
	}
	/*
	 * Wrapper of kth().
	 *
	 * versionL = prefix before range.
	 * versionR = prefix after range.
	 */
	int kth(int versionL, int versionR, int k) {
		return kth(
		    root[versionL],
		    root[versionR],
		    k,
		    0,
		    n - 1
		);
	}
};