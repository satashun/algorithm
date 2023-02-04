---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cpp_src/graph/TwoSat.hpp\"\n// ABC277 Ex\nstruct TwoSat\
    \ {\n   public:\n    TwoSat() : _n(0), scc(0) {}\n    TwoSat(int n) : _n(n), _answer(n),\
    \ scc(n * 2) {}\n\n    // a(i,f) or a(j,g)\n    void add_clause(int i, int f,\
    \ int j, int g) {\n        scc.add_directed_edge(i * 2 + !f, j * 2 + g);\n   \
    \     scc.add_directed_edge(j * 2 + !g, i * 2 + f);\n    }\n\n    // a(i,f)->a(j,g)\n\
    \    // a(i,!f) or a(j,g)\n    void add_implication(int i, int f, int j, int g)\
    \ {\n        add_clause(i, !f, j, g);\n    }\n\n    bool satisfiable() {\n   \
    \     scc.init();\n        auto& cmp = scc.cmp;\n\n        rep(v, _n) {\n    \
    \        if (cmp[v * 2] == cmp[v * 2 + 1]) return false;\n            _answer[v]\
    \ = cmp[v * 2] < cmp[v * 2 + 1];\n        }\n        return true;\n    }\n\n \
    \   V<int> answer() const { return _answer; }\n\n   private:\n    int _n;\n  \
    \  V<int> _answer;\n    SCC<int> scc;\n};\n"
  code: "// ABC277 Ex\nstruct TwoSat {\n   public:\n    TwoSat() : _n(0), scc(0) {}\n\
    \    TwoSat(int n) : _n(n), _answer(n), scc(n * 2) {}\n\n    // a(i,f) or a(j,g)\n\
    \    void add_clause(int i, int f, int j, int g) {\n        scc.add_directed_edge(i\
    \ * 2 + !f, j * 2 + g);\n        scc.add_directed_edge(j * 2 + !g, i * 2 + f);\n\
    \    }\n\n    // a(i,f)->a(j,g)\n    // a(i,!f) or a(j,g)\n    void add_implication(int\
    \ i, int f, int j, int g) {\n        add_clause(i, !f, j, g);\n    }\n\n    bool\
    \ satisfiable() {\n        scc.init();\n        auto& cmp = scc.cmp;\n\n     \
    \   rep(v, _n) {\n            if (cmp[v * 2] == cmp[v * 2 + 1]) return false;\n\
    \            _answer[v] = cmp[v * 2] < cmp[v * 2 + 1];\n        }\n        return\
    \ true;\n    }\n\n    V<int> answer() const { return _answer; }\n\n   private:\n\
    \    int _n;\n    V<int> _answer;\n    SCC<int> scc;\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/graph/TwoSat.hpp
  requiredBy: []
  timestamp: '2023-02-04 17:43:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/graph/TwoSat.hpp
layout: document
redirect_from:
- /library/cpp_src/graph/TwoSat.hpp
- /library/cpp_src/graph/TwoSat.hpp.html
title: cpp_src/graph/TwoSat.hpp
---
