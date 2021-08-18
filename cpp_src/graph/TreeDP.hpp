template <class N, class E>
class treedp {
   public:
    int n;
    const VV<E>& g;
    V<N> a, b;  // temporary, b : left
    V<N> res, sub, bus;

    void dfs_pre(int v, int p) {
        a[v].init(v);
        E up;
        for (auto e : g[v]) {
            if (e != p) {
                dfs_pre(e, v);
                b[e] = a[v];
                a[v] = a[v] + a[e];
            } else {
                up = e;
            }
        }
        sub[v] = a[v];
        if (p != -1) a[v] = a[v].up(up);
    }

    void dfs_all(int v, int p, N cur) {
        for (int i = int(g[v].size()) - 1; i >= 0; --i) {
            auto e = g[v][i];
            if (e == p) continue;
            bus[e] = cur + b[e];
            dfs_all(e, v, bus[e].up(e));
            cur = cur + a[e];
        }
        res[v] = cur;
    }

    treedp(const VV<E>& gg, int root = 0)
        : n(gg.size()), g(gg), a(n), b(n), res(n), sub(n), bus(n) {
        dfs_pre(root, -1);
        N tmp;
        tmp.init(root);
        dfs_all(root, -1, tmp);
    }
};

/*
struct N {
    void init(int v) {}

    // v -> to -> *
    // after calculation on vertices under to
    // consider the edge (v - to)

    N up(int to) const {
        N res = *this;
        return res;
    }

    N operator+(const N& r) const {
        N res = *this;
        return res;
    }
};

void slv() {
    int n;
    treedp<N, int> dp(n);
}*/