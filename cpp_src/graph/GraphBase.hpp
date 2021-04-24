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
    int sz;

    Graph() {}
    Graph(int n) : sz(n), g(n), edges(0){};

    virtual void add_edge(int a, int b, T c) = 0;
};