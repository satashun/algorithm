template <class E>
struct LCA {
    VV<int> anc;
    V<int> dep;
    V<E> depw;
    int lg;
    const Graph<E>& g;

    LCA(const Graph<E>& g, int root = 0) : g(g) {
        int n = g.size();
        lg = 1;
        while ((1 << lg) < n) lg++;
        anc = VV<int>(lg, V<int>(n, -1));
        dep = V<int>(n);
        depw = V<E>(n);

        dep[0] = 0;
        depw[0] = 0;
        dfs(root, -1, 0);

        for (int i = 1; i < lg; i++) {
            for (int j = 0; j < n; j++) {
                anc[i][j] =
                    (anc[i - 1][j] == -1) ? -1 : anc[i - 1][anc[i - 1][j]];
            }
        }
    }

    void dfs(int v, int p, int d) {
        anc[0][v] = p;

        for (auto e : g[v]) {
            if (e.to == p) continue;
            dep[e.to] = dep[v] + 1;
            depw[e.to] = depw[v] + e.cost;
            dfs(e.to, v, d + 1);
        }
    }

    int query(int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        int df = dep[u] - dep[v];
        for (int i = lg - 1; i >= 0; --i) {
            if ((df >> i) & 1) {
                df -= (1 << i);
                u = anc[i][u];
            }
        }
        if (u == v) return u;
        for (int i = lg - 1; i >= 0; --i) {
            if (anc[i][u] != anc[i][v]) {
                u = anc[i][u];
                v = anc[i][v];
            }
        }
        return anc[0][u];
    }

    // ABC267F
    int lev_anc(int v, int k) {
        if (dep[v] < k) return -1;
        rep(i, lg) {
            if (k >> i & 1) {
                if (anc[i][v] == -1) return -1;
                v = anc[i][v];
            }
        }
        return v;
    }

    int dist(int a, int b) {
        int lc = query(a, b);
        return dep[a] + dep[b] - dep[lc] * 2;
    }

    // UTPC2024M
    E distw(int a, int b) {
        int lc = query(a, b);
        return depw[a] + depw[b] - depw[lc] * 2;
    }

    // return x: u->x->v, dist(u,x=k)
    // return -1 if dist(u,v)<k
    // ARC198D (k=1)
    int between(int u, int v, int k) {
        int lc = query(u, v);
        int du = dep[u] - dep[lc];
        if (du >= k) {
            return lev_anc(u, k);
        } else {
            int rem = k - du;
            int dv = dep[v] - dep[lc];
            if (dv < rem) return -1;
            return lev_anc(v, dv - rem);
        }
    }
};