#pragma once

template <class T>
class Edge {
   public:
    int from, to, idx;
    T cost;

    Edge() = default;
    Edge(int from, int to, T cost = T(1), int idx = -1)
        : from(from), to(to), cost(cost), idx(idx) {}
    operator int() const { return to; }
};

template <class T>
class Graph {
   public:
    using E = Edge<T>;
    vector<vector<E>> g;
    vector<E> edges;
    int sz, es;

    Graph() {}
    Graph(int n) : sz(n), g(n), edges(0), es(0){};

    virtual void add_directed_edge(int from, int to, T cost = 1) {
        g[from].emplace_back(from, to, cost, es++);
    }

    virtual void add_edge(int from, int to, T cost = 1) {
        g[from].emplace_back(from, to, cost, es);
        g[to].emplace_back(to, from, cost, es++);
    }

    void read(int M, int offset = -1, bool directed = false,
              bool weighted = false) {
        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            a += offset;
            b += offset;
            T c = T(1);
            if (weighted) cin >> c;
            edges.emplace_back(a, b, c);
            if (directed)
                add_directed_edge(a, b, c);
            else
                add_edge(a, b, c);
        }
    }
};