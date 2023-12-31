/**
 * @docs docs/LowLink.md
 */

// based on ei1333
// allow self loops, multiple edges
template <class T>
struct LowLink : Graph<T> {
   public:
    using Graph<T>::Graph;
    using Graph<T>::g;
    vector<int> ord, low, articulation;
    vector<Edge<T>> bridge;

    virtual void build() {
        used.assign(g.size(), 0);
        ord.assign(g.size(), 0);
        low.assign(g.size(), 0);
        int k = 0;
        for (int i = 0; i < g.size(); i++) {
            if (!used[i]) dfs(i, -1, k);
        }
    }

   private:
    vector<int> used;

    void dfs(int v, int par, int& k) {
        used[v] = true;
        low[v] = ord[v] = k++;
        bool is_articulation = false, seen = false;
        int cnt = 0;
        for (auto& e : g[v]) {
            if (e.to == par && !exchange(seen, true)) {
                continue;
            }
            if (!used[e.to]) {
                ++cnt;
                dfs(e.to, v, k);
                low[v] = min(low[v], low[e.to]);
                is_articulation |= (par >= 0 && low[e.to] >= ord[v]);
                if (ord[v] < low[e.to]) bridge.emplace_back(e);
            } else {
                low[v] = min(low[v], ord[e.to]);
            }
        }
        is_articulation |= (par == -1 && cnt > 1);
        if (is_articulation) articulation.push_back(v);
    }
};