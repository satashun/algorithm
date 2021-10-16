// label : index
// dot -Tsvg a.DOT -o a.svg

template <class T>
void to_graphviz(const Graph<T> g, string filename, bool directed = false) {
    ofstream ss(filename + ".DOT");
    if (directed) {
        ss << "digraph{\n";
        for (int i = 0; i < g.size(); ++i) {
            for (auto e : g[i]) {
                ss << i << "->" << e.to << "[label=\"index=" << e.idx
                   << ", cost=" << e.cost << "\"];\n";
            }
        }
    } else {
        ss << "graph{\n";
        for (int i = 0; i < g.size(); ++i) {
            for (auto e : g[i]) {
                if (e.to > i) {
                    ss << i << "--" << e.to << "[label=\"index=" << e.idx
                       << ", cost=" << e.cost << "\"];\n";
                }
            }
        }
    }

    ss << "}\n";
    ss.close();
    return;
}