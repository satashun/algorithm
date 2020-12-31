#pragma once

template <class T>
class Edge {
    int from, to;
    T cost;

    Edge() = default;
    Edge(int from, int to, T cost = T(1), int idx = -1)
        : from(from), to(to), cost(cost), idx(idx) {}
};

template <class T>
class Graph {
   public:
    using E = Edge<T>;
    vector<vector<E>> > g;
    vector<E> edges;

    Graph() = default;
    Graph(int n) : g(n), edges(0){};

    virtual void add_edge(int a, int b, T c);
    /*
        void add_edge(int a, int b, T c = T(1), bool directed = false) {
            int id = (int)edges.size();
            g[a].emplace_back(a, b, c);
            if (!directed) g[b].emplace_back(b, a, c);
        }*/
};
