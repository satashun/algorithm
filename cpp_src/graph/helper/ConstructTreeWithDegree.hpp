// construct tree with designated degrees
// no such tree -> returns an empty vector
// AGC059B

VV<int> construct_from_deg(V<int> deg) {
    debug(deg);
    int kind = 0, sz = SZ(deg);
    rep(i, sz) if (deg[i] > 0) kind++;

    VV<int> g;
    ll sum = accumulate(ALL(deg), 0ll);
    if (sum != (kind - 1) * 2) return g;

    g.resize(sz);
    set<pii> st;
    rep(i, SZ(deg)) if (deg[i] > 0) st.emplace(deg[i], i);

    while (SZ(st) > 1) {
        auto [v1, c1] = *st.begin();
        st.erase(st.begin());
        auto [v2, c2] = *(--st.end());
        st.erase(mp(v2, c2));
        if (v2 > 1) st.emplace(v2 - 1, c2);
        g[c1].pb(c2);
        g[c2].pb(c1);
    }
    return g;
}