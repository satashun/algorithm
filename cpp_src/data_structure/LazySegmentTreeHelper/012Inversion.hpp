// ABC265G
// submission : https://atcoder.jp/contests/abc265/submissions/42179632

struct U {
    using T1 = array<array<ll, 3>, 3>;
    using T2 = array<ll, 3>;

    static T1 id1() {
        T1 res;
        rep(i, 3) rep(j, 3) res[i][j] = 0;
        return res;
    }
    static T2 id2() {
        T2 res;
        rep(i, 3) res[i] = i;
        return res;
    }
    static T1 op11(const T1& a, const T1& b) {
        T1 res = id1();
        rep(i, 3) {
            rep(j, 3) {
                res[i][j] += a[i][j] + b[i][j];
                if (i != j) {
                    res[i][j] += a[i][i] * b[j][j];
                }
            }
        }

        return res;
    }

    static T1 op21(const T2& b, const T1& a) {
        T1 res = id1();
        rep(i, 3) {
            rep(j, 3) {
                if (i == j || b[i] != b[j]) {
                    res[b[i]][b[j]] += a[i][j];
                }
            }
        }
        return res;
    }

    // order : b -> a
    static T2 op22(const T2& a, const T2& b) {
        T2 res;
        rep(i, 3) res[i] = a[b[i]];
        return res;
    }
};