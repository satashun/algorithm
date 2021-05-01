#include "GraphBase.hpp"

template <class T>
class forest : public Graph<T> {
   public:
    using Graph<T>::g;
    using Graph<T>::edges;
    forest = default;
    forest(int n) : g(n){};
        int add(int from, int to, T cost = 1) {
        assert(0 <= from && from < n && 0 <= to && to < n);
        int id = (int)edges.size();
        assert(id < n - 1);
        g[from].push_back(id);
        g[to].push_back(id);
        edges.push_back({from, to, cost});
        return id;
    }
    int add_edge(int a, int b, T c=1) {
        int id=(int)edges.size();
        g[a].pb();
    }
};