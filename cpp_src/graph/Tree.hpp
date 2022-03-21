template <class T>
pii find_diam(Graph<T>& g) {
    int r = 0;
    auto ds = bfs(g, r);
    int r2 = max_element(ALL(ds)) - ds.begin();
    auto ds2 = bfs(g, r2);
    int r3 = max_element(ALL(ds2)) - ds2.begin();
    auto ds3 = bfs(g, r3);
    return mp(r2, r3);
}