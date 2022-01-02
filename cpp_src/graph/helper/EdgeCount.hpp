// ABC213G (also subset convolution)
// O(N * 2^N)
// es[S] := #((u,v) s.t. u \in S & v \in S)

V<int> edge_count(const VV<int>& e) {
    int n = SZ(e);
    V<int> es(1 << n);
    rep(i, 1 << n) {
        if (i == 0) continue;
        int p = -1;

        rep(j, n) if (i >> j & 1) { p = j; }
        es[i] = es[i ^ (1 << p)];
        rep(j, p) if (i >> j & 1) { es[i] += e[j][p]; }
    }
    return es;
}