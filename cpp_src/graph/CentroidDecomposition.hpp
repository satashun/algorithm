// ABC291H
template <class T>
class CentroidDecomposition {
   public:
    const int INF = 1e9;

    int n;
    V<int> centroid, subtree_size;
    Graph<T> g;
    VV<int> tree;

    CentroidDecomposition(Graph<T> g) : g(g) {
        n = g.size();
        centroid = V<int>(n);
        subtree_size = V<int>(n);
        tree = VV<int>(n);
    }

    int compute_subtree_size(int v, int p) {
        int c = 1;
        for (auto e : g[v]) {
            if (e.to == p || centroid[e.to]) continue;
            c += compute_subtree_size(e.to, v);
        }
        return subtree_size[v] = c;
    }

    pair<int, int> search_centroid(int v, int p, int t) {
        auto res = make_pair(INF, -1);
        int s = 1, m = 0;

        for (auto e : g[v]) {
            if (e.to == p || centroid[e.to]) continue;

            res = min(res, search_centroid(e.to, v, t));
            m = max(m, subtree_size[e.to]);
            s += subtree_size[e.to];
        }

        m = max(m, t - s);
        res = min(res, mp(m, v));
        return res;
    }

    // return centroid
    int solve_sub(int v) {
        compute_subtree_size(v, -1);
        int s = search_centroid(v, -1, subtree_size[v]).second;
        centroid[s] = 1;

        // centroid = s !!!!!

        for (auto e : g[s]) {
            if (centroid[e.to]) continue;
            int tr = solve_sub(e.to);
            tree[s].pb(tr);
        }
        return s;
    }
};