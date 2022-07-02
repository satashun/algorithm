// ABC 253 H
template <class T>
T count_spanning_tree(int N, int mask, const V<pii>& es) {
    V<int> id(N, -1);
    int now = 0;
    rep(j, N) {
        if (mask >> j & 1) {
            id[j] = now++;
        }
    }

    Matrix<Mint> A(now, now);
    V<int> deg(now);
    for (auto [a, b] : es) {
        if (id[a] != -1 && id[b] != -1) {
            deg[id[a]]++;
            deg[id[b]]++;
            A.a[id[a]][id[b]]--;
            A.a[id[b]][id[a]]--;
        }
    }

    rep(i, now) A.a[i][i] = deg[i];

    V<int> sa(now - 1), sb(now - 1);
    iota(ALL(sa), 0);
    iota(ALL(sb), 0);
    auto B = sub_matrix(A, sa, sb);
    return det(B);
}