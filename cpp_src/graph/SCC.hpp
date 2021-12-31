// ABC214H
// if i -> j, then cmp[i] <= cmp[j]
// g_comp : compressed DAG

template <class T>
struct SCC : Graph<T> {
   public:
    using Graph<T>::Graph;
    using Graph<T>::g;
    Graph<T> rg;

    V<int> vs, cmp, vis;
    VV<int> comps;

    // allow multiple edges
    Graph<T> g_comp;

    void dfs(int v) {
        vis[v] = true;

        for (auto e : g[v]) {
            if (!vis[e.to]) {
                dfs(e.to);
            }
        }

        vs.push_back(v);
    }

    void rdfs(int v, int k) {
        vis[v] = true;
        cmp[v] = k;

        for (auto e : rg[v]) {
            if (!vis[e.to]) {
                rdfs(e.to, k);
            }
        }
    }

    void init() {
        int n = g.size();
        rg = Graph<T>(n);
        rep(i, n) {
            for (auto e : g[i]) {
                rg.add_directed_edge(e.to, e.from, e.cost);
            }
        }

        vs = cmp = V<int>(n);
        vis = V<int>(n);

        rep(v, n) if (!vis[v]) dfs(v);

        fill(vis.begin(), vis.end(), false);

        int k = 0;
        reverse(vs.begin(), vs.end());

        for (int v : vs) {
            if (!vis[v]) {
                rdfs(v, k++);
            }
        }

        comps.resize(k);
        rep(v, n) { comps[cmp[v]].push_back(v); }

        g_comp = Graph<T>(k);

        rep(i, n) {
            for (auto e : g[i]) {
                if (cmp[i] != cmp[e.to]) {
                    g_comp.add_directed_edge(cmp[i], cmp[e.to], e.cost);
                }
            }
        }
    }
};