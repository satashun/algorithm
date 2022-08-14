template <class T>
class Forest : public Graph<T> {
   public:
    using Graph<T>::edges;
    using Graph<T>::g;
    using Graph<T>::Graph;

    V<int> in, ot, dep, par;
    V<T> dist;

    Forest(int n) : Graph<T>(n) {}

    void init() {
        int sz = g.size();
        in = V<int>(sz, -1);
        ot = V<int>(sz, -1);
        dep = V<int>(sz, -1);
        par = V<int>(sz, -1);
        dist = V<int>(sz);
    }

    void dfs(int v, int p, int d, int& k) {
        in[v] = k++;
        dep[v] = d;
        par[v] = p;
        for (auto e : g[v]) {
            if (e.to == p) continue;
            dfs(e.to, v, d + 1, k);
            dist[e.to] = dist[v] + e.cost;
        }
        ot[v] = k;
    }

    void build() {
        int now = 0;
        for (int i = 0; i < g.size(); ++i) {
            if (in[i] == -1) {
                dfs(i, -1, 0, now);
            }
        }
    }
};

template <class T>
Graph<T> read_tree(int n) {
    Graph<T> g(n);
    g.read(n - 1);
    return g;
}

template <class T>
pii find_diam(Graph<T>& g) {
    int r = 0;
    auto ds = bfs(g, r);
    int r2 = max_element(ALL(ds)) - ds.begin();
    auto ds2 = bfs(g, r2);
    int r3 = max_element(ALL(ds2)) - ds2.begin();
    auto ds3 = bfs(g, r3);
    return mp(r2, r3);
}