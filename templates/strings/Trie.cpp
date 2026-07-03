struct Trie {
	struct Node {
		vector<int> nxt;
		int fin = 0;
		Node() { nxt = vector<int>(26, -1); }
	};

	vector<Node> trie;
	Trie() { trie.push_back(Node()); }

	void insert(string &s) {
		int curr = 0;
		for (char c : s)
		{
			int &me = trie[curr].nxt[c - 'a'];
			if (me == -1)
			{
				me = trie.size();
				trie.push_back(Node());
			}
			curr = me;
		}
		trie[curr].fin = 1;
	}

	int exist(string &s) {
		int curr = 0;
		for (char c : s)
		{
			int &me = trie[curr].nxt[c - 'a'];
			if (me == -1)
				return false;
			curr = me;
		}
		return trie[curr].fin;
	}
};