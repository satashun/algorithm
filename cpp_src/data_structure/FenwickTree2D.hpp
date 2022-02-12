template <typename T>
struct BIT2D {
    int N, M;
    VV<T> bit;
    BIT2D(int P, int Q) : N(P + 3), M(Q + 3) { bit.assign(N, vector<T>(M, 0)); }

    void add(int r, int c, T x) {
        r++, c++;
        for (int i = r; i < N; i += (i & -i)) {
            for (int j = c; j < M; j += (j & -j)) {
                bit[i][j] += x;
            }
        }
    }

    // 0 <= r <= N, 0 <= c <= M
    // sum of [0,r)x[0,c)
    T sum(int r, int c) {
        T s(0);
        for (int i = r; i > 0; i -= (i & -i)) {
            for (int j = c; j > 0; j -= (j & -j)) {
                s += bit[i][j];
            }
        }
        return s;
    }

    // sum of [r1,r2)x[c1,c2)
    T sum(int r1, int c1, int r2, int c2) {
        return sum(r2, c2) - sum(r2, c1) - sum(r1, c2) + sum(r1, c1);
    }
};