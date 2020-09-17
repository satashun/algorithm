template <class C, class D>  // capacity, distance
struct MinCostFlow {
    struct edge {
        int to, rev;
        C cap;
        D cost;
        edge(int to, C cap, D cost, int rev)
            : to(to), cap(cap), cost(cost), rev(rev){};
    };

    using E = edge;

    const D INF = numeric_limits<D>::max() / D(3);

    int n;
    VV<E> g;
    V<D> h, dst;
    V<int> prevv, preve;

    MinCostFlow(int n) : n(n), g(n), h(n), dst(n), prevv(n), preve(n) {}

    void add_edge(int f, int t, C cap, D cost) {
        g[f].emplace_back(t, cap, cost, (int)g[t].size());
        g[t].emplace_back(f, 0, -cost, (int)g[f].size() - 1);
    }

    // true : no negative cycle
    bool init_negative(int s) {
        fill(h.begin(), h.end(), INF);
        h[s] = 0;
        for (int t = 0; t <= n; ++t) {
            for (int i = 0; i < n; ++i) {
                for (auto e : g[i]) {
                    if (!e.cap) continue;
                    if (h[e.to] > h[i] + e.cost && t == n) {
                        return false;
                    }
                    h[e.to] = min(h[e.to], h[i] + e.cost);
                }
            }
        }
        return true;
    }

    D exec(int s, int t, C f) {
        D res = 0;
        using Data = pair<D, int>;
        while (f > 0) {
            priority_queue<Data, vector<Data>, greater<Data>> que;
            fill(dst.begin(), dst.end(), INF);
            dst[s] = 0;
            que.push(Data(0, s));

            while (!que.empty()) {
                auto p = que.top();
                que.pop();
                int v = p.second;
                if (dst[v] < p.first) continue;

                rep(i, g[v].size()) {
                    auto e = g[v][i];
                    D nd = dst[v] + e.cost + h[v] - h[e.to];
                    if (e.cap > 0 && dst[e.to] > nd) {
                        dst[e.to] = nd;
                        prevv[e.to] = v;
                        preve[e.to] = i;
                        que.push(Data(dst[e.to], e.to));
                    }
                }
            }

            if (dst[t] == INF) return D(-inf);
            rep(i, n) h[i] += dst[i];

            C d = f;
            for (int v = t; v != s; v = prevv[v]) {
                d = min(d, g[prevv[v]][preve[v]].cap);
            }
            f -= d;
            res += d * h[t];
            for (int v = t; v != s; v = prevv[v]) {
                edge& e = g[prevv[v]][preve[v]];
                e.cap -= d;
                g[v][e.rev].cap += d;
            }
        }

        return res;
    }
};