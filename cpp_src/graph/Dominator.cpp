// modified gifted infants' code

// immediately dominate:
// idom(v) := r -> v で必ず通る頂点のうち，一番近いもの
// idom(v) -> v で辺を貼ると木にできる

template <class T>
struct DominatorTree : Graph<T> {
    int n;
    VV<int> g, rG, bct;
    V<int> idom, semi, us, id, rId, par, mn, anc;
    DominatorTree(int nn) : n(nn) {
        g.resize(n);
        rG.resize(n);
        bct.resize(n);
        idom.resize(n, -1);
        semi.resize(n);
        us.resize(n);
        id.resize(n, -1);
        rId.resize(n);
        par.resize(n, -1);
        mn.resize(n);
        anc.resize(n, -1);
        for (int i = 0; i < n; ++i) {
            semi[i] = i;
            mn[i] = i;
        }
    }
    void add_edge(int a, int b) {
        g[a].pb(b);
        rG[b].pb(a);
    }

    int find(int v) {
        if (anc[v] == -1) return v;
        int a = find(anc[v]);
        if (id[semi[mn[anc[v]]]] < id[semi[mn[v]]]) {
            mn[v] = mn[anc[v]];
        }
        return anc[v] = a;
    }
    void link(int c, int p) { anc[c] = p; }
    void dfs(int v, int p, int& i) {
        if (id[v] != -1) return;
        id[v] = i;
        rId[i++] = v;
        par[v] = p;
        for (int c : g[v]) {
            dfs(c, v, i);
        }
    }
    V<int> calc(int root) {
        int sz = 0;
        dfs(root, -1, sz);
        for (int i = sz - 1; i > 0; --i) {
            int w = rId[i];
            for (int v : rG[w])
                if (id[v] != -1) {
                    find(v);
                    if (id[semi[mn[v]]] < id[semi[w]]) {
                        semi[w] = semi[mn[v]];
                    }
                }
            bct[semi[w]].push_back(w);
            for (int v : bct[par[w]]) {
                find(v);
                us[v] = mn[v];
            }
            bct[par[w]].clear();
            link(w, par[w]);
        }
        for (int i = 1; i < sz; ++i) {
            int w = rId[i];
            if (semi[w] == semi[us[w]]) {
                idom[w] = semi[w];
            } else {
                idom[w] = idom[us[w]];
            }
        }
        return idom;
    }
};