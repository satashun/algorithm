// ABC160F, ABC223G

template <class N, class E>
class treedp {
    // a: temporary, b[v] : left of v (when rooted at some vertex)
    // after dfs_pre, a[v] means(dp on subtree at v) and consider the edge to the parent
    
   public:
    int n;
    const Graph<E>& g;
    V<N> a, b;
    V<N> res, sub, bus;

    void dfs_pre(int v, int p) {
        a[v].init(v);
        E up;
        for (auto e : g[v]) {
            if (e.to != p) {
                dfs_pre(e.to, v);
                b[e.to] = a[v];
                a[v] = a[v] + a[e.to];
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
            if (e.to == p) continue;
            bus[e.to] = cur + b[e.to];
            dfs_all(e.to, v, bus[e.to].up(e));
            cur = cur + a[e.to];
        }
        res[v] = cur;
    }

    treedp(const Graph<E>& gg, int root = 0)
        : n(gg.size()), g(gg), a(n), b(n), res(n), sub(n), bus(n) {
        dfs_pre(root, -1);
        N tmp;  // identity
        dfs_all(root, -1, tmp);
    }

    void slv() {
    }
};

/*
// template<class E>
struct Data {
    Data() {}
    void init(int v) {}

    // v -> to -> *
    // after calculation on vertices under to
    // consider the edge (v - to)

    // Data up(E to) const {
    Data up(int to) const {
        Data res = *this;
        return res;
    }

    Data operator+(const Data& r) const {
        Data res = *this;
        return res;
    }
};
*/