// ABC328F
// ref: maspy's library
// G:群

template <typename G>
struct WeightedUnionFind {
    using E = typename G::value_type;

    int n, n_comp;
    V<int> par, size;
    V<E> dif;

    WeightedUnionFind(int n) : n(n), n_comp(n), dif(n, G::unit()), size(n, 1) {
        par.resize(n);
        iota(ALL(par), 0);
    }

    // (root, val[root]=unit としたときの val[v])
    pair<int, E> get(int v) {
        E res = G::unit();
        while (v != par[v]) {
            res = G::op(dif[v], res);
            res = G::op(dif[par[v]], res);
            dif[v] = G::op(dif[par[v]], dif[v]);
            v = par[v] = par[par[v]];
        }
        return {v, res};
    }

    pair<int, E> operator[](int v) { return get(v); }

    int merge(int from, int to, E x) {
        auto [v1, x1] = get(from);
        auto [v2, x2] = get(to);
        if (v1 == v2 && G::op(x1, x) != x2) return -1;
        if (v1 == v2) return 0;
        if (size[v1] < size[v2]) {
            swap(v1, v2);
            swap(x1, x2);
            x = G::inverse(x);
        }
        x = G::op(x1, x);
        x = G::op(x, G::inverse(x2));

        dif[v2] = x;
        par[v2] = v1;
        size[v1] += size[v2];
        n_comp--;
        return 1;
    }
};

template <typename T>
struct Monoid_Add {
    using value_type = T;
    static constexpr T op(const T& x, const T& y) { return x + y; }
    static constexpr T inverse(const T& x) { return -x; }
    static constexpr T unit() { return T(0); }
};