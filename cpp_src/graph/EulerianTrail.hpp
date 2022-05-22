// modified https://ei1333.github.io/library/graph/others/eulerian-trail.hpp
// allow multiple edges and self loops, multiple components
template <class T, bool directed>
struct EulerianTrail : Graph<T> {
   public:
    using Graph<T>::g;
    using Graph<T>::Graph;
    using Graph<T>::edges;
    using Graph<T>::es;
    using E = Edge<T>;

    V<int> used_vertex, used_edge, deg;

    void init(int n) {
        deg.assign(n, 0);
        used_vertex.assign(n, 0);
    }

    void add_directed_edge(int from, int to, T cost = 1) {
        g[from].emplace_back(from, to, cost, es++);
        deg[from]++;
        deg[to]--;
    }

    void add_edge(int from, int to, T cost = 1) {
        g[from].emplace_back(from, to, cost, es);
        g[to].emplace_back(to, from, cost, es++);
        deg[from]++;
        deg[to]++;
    }

    EulerianTrail(int n) : Graph<T>(n), used_vertex(n), deg(n) {}

    E get_edge(int idx) const { return edges[idx]; }

    VV<int> enumerate_eulerian_trail() {
        if (directed) {
            for (auto& v : deg)
                if (v != 0) return {};
        } else {
            for (auto& v : deg)
                if (v & 1) return {};
        }
        used_edge.assign(es, 0);
        VV<int> res;
        rep(i, g.size()) {
            if (!SZ(g[i]) || used_vertex[i]) continue;
            res.push_back(go(i));
        }
        return res;
    }

    // yukicoder 583
    VV<int> enumerate_semi_eulerian_trail() {
        unionfind uf(g.size());
        for (auto& e : edges) {
            uf.unite(e.from, e.to);
        }
        VV<int> group(g.size());
        rep(i, g.size()) group[uf.find(i)].push_back(i);

        VV<int> res;
        used_edge.assign(es, 0);

        for (auto& vs : group) {
            if (!SZ(vs)) continue;
            int s = -1, t = -1;
            if (directed) {
                for (auto& v : vs) {
                    if (abs(deg[v]) > 1) {
                        return {};
                    } else if (deg[v] == 1) {
                        if (s != -1) return {};
                        s = v;
                    }
                }
            } else {
                for (auto& v : vs) {
                    if (deg[v] & 1) {
                        if (s == -1)
                            s = v;
                        else if (t == -1)
                            t = v;
                        else
                            return {};
                    }
                }
            }
            debug(s, t);
            if (s == -1) s = vs[0];
            res.emplace_back(go(s));
            if (!SZ(res.back())) res.pop_back();
        }
        return res;
    }

    // return {id of edges}
    V<int> go(int s) {
        stack<pair<int, int>> st;
        V<int> ord;
        st.emplace(s, -1);
        while (!st.empty()) {
            int idx = st.top().first;
            used_vertex[idx] = true;
            if (g[idx].empty()) {
                ord.emplace_back(st.top().second);
                st.pop();
            } else {
                auto e = g[idx].back();
                g[idx].pop_back();
                if (used_edge[e.idx]) continue;
                used_edge[e.idx] = true;
                st.emplace(e.to, e.idx);
            }
        }
        ord.pop_back();
        reverse(ord.begin(), ord.end());
        return ord;
    }
};