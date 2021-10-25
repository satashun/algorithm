// using treap
// O(n log^2 n)

auto hamilton = [&]() {
    auto r = new node_t(0);

    // i -> j ?
    auto comp = [&](int i, int j) {};

    auto ff = [&](int pos, int p) {
        int id = get(r, pos);
        return comp(id, p);
    };

    for (int i = 1; i < n; ++i) {
        if (!ff(1, i)) {
            auto nx = new node_t(i);
            r = insert(r, 1, nx);
        } else if (ff(i, i)) {
            auto nx = new node_t(i);
            r = insert(r, i + 1, nx);
        } else {
            int lo = 1, hi = i;
            while (hi - lo > 1) {
                int m = (lo + hi) / 2;
                if (ff(m, i)) {
                    lo = m;
                } else {
                    hi = m;
                }
            }
            auto nx = new node_t(i);
            r = insert(r, hi, nx);
        }
    }

    vector<int> vs;
    rep(i, n) {
        auto nx = split(r, 1);
        vs.push_back(nx.fi->val);
        r = nx.se;
    }
    return vs;
};