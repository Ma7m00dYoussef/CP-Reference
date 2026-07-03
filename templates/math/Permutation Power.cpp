// permutation on vector
void apply_permutation(vector<int> &v, const vector<int> &perm) {
	int n = v.size() - 1;
	vector<int> tmp = v;
	for (int i = 1; i <= n; ++i)
	{
		v[i] = tmp[perm[i]];
	}
}

// permutation ^ k
vector<int> powerPermutation(vector<int> perm, ll k) {
	int n = perm.size() - 1;
	vector<int> res(n + 1);
	iota(res.begin(), res.end(), 0); //  identity permutation

	while (k > 0)
	{
		if (k & 1)
		{
			apply_permutation(res, perm);
		}
		apply_permutation(perm, perm);
		k >>= 1;
	}
	return res;
}