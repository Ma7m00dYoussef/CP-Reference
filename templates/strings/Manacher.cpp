struct Manacher {
	vector<int> odd, even;

	Manacher(string &s)
	{
		int n = s.size();

		odd.resize(n);
		for (int i = 0, l = 0, r = -1; i < n; i++)
		{
			int k = i > r ? 1 : min(odd[l + r - i], r - i + 1);
			while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) k++;
			odd[i] = k--;
			if (i + k > r) l = i - k, r = i + k;
		}

		even.resize(n);
		for (int i = 0, l = 0, r = -1; i < n; i++)
		{
			int k = i > r ? 0 : min(even[l + r - i + 1], r - i + 1);
			while (i - k - 1 >= 0 && i + k < n && s[i - k - 1] == s[i + k]) k++;
			even[i] = k--;
			if (i + k > r) l = i - k - 1, r = i + k;
		}
	}
};