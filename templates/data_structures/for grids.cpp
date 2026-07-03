// rotate n * n grid counter clockWise or clockWise
vector<vector<int>> rotate(vector<vector<int>> &v)
{
	int n = v.size();
	vector<vector<int>> ret(v.size(), vector<int>(v.size()));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			// ret[i][j] = v[j][n - i - 1] ; //for counterclockWise
			// ret[i][j] = v[n - j - 1][i] ; //for clockWise
		}
	}
	return ret;
}