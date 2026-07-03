#define i64 uint64_t

const i64 MOD = (1ULL << 61) - 1;

inline i64 mul(i64 a, i64 b) {
    __uint128_t p = (__uint128_t)a * b;
    i64 ret = (i64)(p >> 61) + (i64)(p & MOD);
    return ret >= MOD ? ret - MOD : ret;
}

inline i64 add(i64 a, i64 b) {
    return a + b >= MOD ? a + b - MOD : a + b;
}

inline i64 sub(i64 a, i64 b) {
    return a >= b ? a - b : a - b + MOD;
}

struct Hash2D {

    static vector<i64> pwRow , pwCol;
    static i64 BASE_ROW , BASE_COL;

    int n , m;
    vector<vector<i64>> pre;

    Hash2D(const vector<string>& a) {
        n = a.size();
        m = a[0].size();

        while ((int)pwRow.size() <= n)
            pwRow.push_back(mul(pwRow.back(), BASE_ROW));

        while ((int)pwCol.size() <= m)
            pwCol.push_back(mul(pwCol.back(), BASE_COL));

        pre.assign(n + 1, vector<i64>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                i64 cur = (i64)a[i - 1][j - 1];

                pre[i][j] =
                    add(
                        add(
                            mul(pre[i - 1][j], BASE_ROW),
                            mul(pre[i][j - 1], BASE_COL)
                        ),
                        cur
                    );

                pre[i][j] = sub(
                    pre[i][j],
                    mul(
                        mul(pre[i - 1][j - 1], BASE_ROW),
                        BASE_COL
                    )
                );
            }
        }
    }
    i64 getHash(int r1, int c1, int r2, int c2) const {

        int h = r2 - r1 + 1;
        int w = c2 - c1 + 1;

        i64 res = pre[r2 + 1][c2 + 1];

        res = sub(
            res,
            mul(pre[r1][c2 + 1], pwRow[h])
        );

        res = sub(
            res,
            mul(pre[r2 + 1][c1], pwCol[w])
        );

        res = add(
            res,
            mul(
                mul(pre[r1][c1], pwRow[h]),
                pwCol[w]
            )
        );

        return res;
    }
};
vector<i64> Hash2D::pwRow = {1};
vector<i64> Hash2D::pwCol = {1};
i64 Hash2D::BASE_ROW = 0;
i64 Hash2D::BASE_COL = 0;
void initHash2D() {
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<i64> dist(257, MOD - 2);
    Hash2D::BASE_ROW = dist(rng);
    Hash2D::BASE_COL = dist(rng);
}