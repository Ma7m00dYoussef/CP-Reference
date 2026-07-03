#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct SparseTable{
    ll n;
    vector<ll> LG;
    vector<vector<ll>> data;

    SparseTable(vector<ll> &a){
        n = (ll)a.size();
        LG = vector<ll>(n + 1, 0);

        LG[1] = 0;
        for (ll i = 2; i <= n; i++)
            LG[i] = LG[i / 2] + 1;

        data = vector<vector<ll>>(LG[n] + 1 , vector<ll>(n));
        for (ll i = 0; i < n; i++)
            data[0][i] = a[i];
        for (ll k = 1; k <= LG[n]; k++)
        {
            for (ll i = 0; i < n; i++)
            {
                if (i + (1 << (k - 1)) >= n)
                    break;
                data[k][i] = max(data[k - 1][i], data[k - 1][i + (1 << (k - 1))]);
            }
        }
    }

    ll query(ll l, ll r) {
        ll sz = r - l + 1;
        ll LOG = LG[sz];
        return max(data[LOG][l], data[LOG][r - (1 << LOG) + 1]);
    }
};
