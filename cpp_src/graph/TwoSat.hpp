// ABC277 Ex
struct TwoSat {
   public:
    TwoSat() : _n(0), scc(0) {}
    TwoSat(int n) : _n(n), _answer(n), scc(n * 2) {}

    // a(i,f) or a(j,g)
    void add_clause(int i, int f, int j, int g) {
        scc.add_directed_edge(i * 2 + !f, j * 2 + g);
        scc.add_directed_edge(j * 2 + !g, i * 2 + f);
    }

    // a(i,f)->a(j,g)
    // a(i,!f) or a(j,g)
    void add_implication(int i, int f, int j, int g) {
        add_clause(i, !f, j, g);
    }

    bool satisfiable() {
        scc.init();
        auto& cmp = scc.cmp;

        rep(v, _n) {
            if (cmp[v * 2] == cmp[v * 2 + 1]) return false;
            _answer[v] = cmp[v * 2] < cmp[v * 2 + 1];
        }
        return true;
    }

    V<int> answer() const { return _answer; }

   private:
    int _n;
    V<int> _answer;
    SCC<int> scc;
};