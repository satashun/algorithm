struct weighted_union {
    // i2g[i] := アイテム i の所属するグループの番号
    // g2i[g] := グループ g に所属するアイテムたち

    vector<int> i2g;
    vector<vector<int>> g2i;

    void init(int n) {
        i2g.resize(n);
        g2i.resize(n);
        gg.resize(n);
        for (int i = 0; i < n; ++i) {
            i2g[i] = i;
            g2i[i].assign(1, i);
        }
    }

    int find(int i) { return i2g[i]; }

    void merge(int ia, int ib) {
        if (g2i[i2g[ia]].size() < g2i[i2g[ib]].size()) {
            swap(ia, ib);
        }

        int ga = i2g[ia], gb = i2g[ib];
        if (ga == gb) return;
        for (int j : g2i[gb]) i2g[j] = ga;
        g2i[ga].insert(g2i[ga].end(), g2i[gb].begin(), g2i[gb].end());
        g2i[gb].clear();
    }

    bool is_same_group(int ia, int ib) { return i2g[ia] == i2g[ib]; }
};