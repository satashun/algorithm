// consider merging components
// by choosing cheapest edges
// add edges with same cost at the same time
// return : (directed tree, multiple components ?)
// index of root : g.size()-1
// https://atcoder.jp/contests/abc235/submissions/28567563

template <class T>
pair<Graph<T>, bool> merging_tree(int N, V<Edge<T>> edges) {
    map<T, V<pii>> es;
    for (auto e : edges) {
        es[e.cost].eb(e.from, e.to);
    }

    unionfind uf;
    uf.init(N);

    V<int> id(N);
    rep(i, N) id[i] = i;

    Graph<T> g(N * 2 + 10);

    int now = N;

    for (auto [ct, vec] : es) {
        V<int> pt;
        for (auto& [a, b] : vec) {
            a = uf.find(a);
            b = uf.find(b);
        }

        for (auto [a, b] : vec) {
            if (a != b) {
                pt.pb(a);
                pt.pb(b);
            }
        }

        mkuni(pt);
        int sz = SZ(pt);
        unionfind sub;
        sub.init(sz);

        for (auto [a, b] : vec) {
            if (a == b) continue;
            a = lower_bound(ALL(pt), a) - pt.begin();
            b = lower_bound(ALL(pt), b) - pt.begin();
            sub.unite(a, b);
        }
        VV<int> gr(sz);
        rep(i, sz) gr[sub.find(i)].pb(i);

        for (auto v : gr) {
            if (SZ(v) == 0) continue;
            V<int> real;
            for (int x : v) real.pb(pt[x]);

            int nid = now++;
            for (int x : real) {
                g.add_directed_edge(nid, id[x]);
            }

            rep(i, SZ(real)) { uf.unite(real[i], real[0]); }
            id[uf.find(real[0])] = nid;
        }
    }

    set<int> st;
    rep(i, N) st.insert(id[uf.find(i)]);

    bool fake = 0;
    if (st.size() > 1) {
        fake = 1;
        int nid = now++;
        for (int x : st) {
            g.add_directed_edge(nid, x);
        }
    }

    g.resize(now);
    return mp(g, fake);
}