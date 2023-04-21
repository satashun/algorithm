// allow multiple components
// ABC266F, ABC296E
template <class T>
class Namori : public Graph<T> {
   public:
    using Graph<T>::edges;
    using Graph<T>::g;
    using Graph<T>::Graph;
    using E = Edge<T>;
    using Graph<T>::es;

    V<int> deg, par;
    VV<E> g2;  // g2 for tree from cycles
    V<bool> vis;
    VV<int> cycles;
    V<int> rt;

    Namori() {}
    Namori(int n) : Graph<T>(n), g2(n) {
        deg = V<int>(n);
        par = V<int>(n, -1);
        vis = V<bool>(n);
        rt = V<int>(n);
    }

    void add_edge(int from, int to, T cost = 1) {
        g[from].emplace_back(from, to, cost, es);
        g[to].emplace_back(to, from, cost, es++);
        ++deg[from], ++deg[to];
    }

    void dfs(int v, V<int>& cycle) {
        vis[v] = true;
        cycle.pb(v);

        for (auto e : g[v]) {
            if (deg[e.to] == 2 && !vis[e.to]) {
                dfs(e.to, cycle);
            }
        }
    }

    void dfs2(int v, int p, int r) {
        rt[v] = r;
        for (auto e : g2[v]) {
            if (e.to != p) {
                dfs2(e.to, v, r);
            }
        }
    }

    void build() {
        queue<int> que;
        rep(i, g.size()) {
            if (deg[i] == 1) {
                que.push(i);
            }
        }

        while (!que.empty()) {
            int v = que.front();
            que.pop();
            vis[v] = true;
            for (auto e : g[v]) {
                auto re = e;
                swap(re.from, re.to);
                if (deg[e.to] > 1) {
                    g2[e.to].pb(re);
                    par[v] = e.to;

                    if (--deg[e.to] == 1) {
                        que.push(e.to);
                    }
                }
            }
        }

        rep(i, g.size()) if (deg[i] == 2 && !vis[i]) {
            cycles.eb(V<int>{});
            dfs(i, cycles.back());
            V<int> cyc = cycles.back();
            for (int v : cyc) {
                dfs2(v, -1, v);
            }
        }
    }
};