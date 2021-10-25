// based on ei1333
// tree : u-v -> comp[u]-comp[v]
template <class T>
struct TwoEdgeConnectedComponents : LowLink<T> {
   public:
    using LowLink<T>::LowLink;
    using LowLink<T>::g;
    using LowLink<T>::ord;
    using LowLink<T>::low;
    using LowLink<T>::bridge;

    vector<int> comp;
    Graph<T> tree;
    vector<vector<int>> group;

    void build() {
        LowLink<T>::build();
        comp.assign(g.size(), -1);
        int k = 0;
        for (int i = 0; i < g.size(); i++) {
            if (comp[i] == -1) dfs(i, -1, k);
        }
        group.resize(k);
        for (int i = 0; i < g.size(); i++) {
            group[comp[i]].emplace_back(i);
        }
        tree = Graph<T>(k);
        for (auto& e : bridge) {
            tree.add_edge(comp[e.from], comp[e.to], e.cost);
        }
    }
    /*
        void show() {
            print(group.size());
            for (auto& v : group) {
                cout << SZ(v) << ' ';
                print(v);
            }
        }
    */
   private:
    void dfs(int idx, int par, int& k) {
        if (par >= 0 && ord[par] >= low[idx])
            comp[idx] = comp[par];
        else
            comp[idx] = k++;
        for (auto& e : g[idx]) {
            if (comp[e.to] == -1) dfs(e.to, idx, k);
        }
    }
};