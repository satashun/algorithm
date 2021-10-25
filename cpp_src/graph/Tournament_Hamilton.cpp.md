---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cpp_src/graph/Tournament_Hamilton.cpp\"\n// using treap\n\
    // O(n log^2 n)\n\nauto hamilton = [&]() {\n    auto r = new node_t(0);\n\n  \
    \  // i -> j ?\n    auto comp = [&](int i, int j) {};\n\n    auto ff = [&](int\
    \ pos, int p) {\n        int id = get(r, pos);\n        return comp(id, p);\n\
    \    };\n\n    for (int i = 1; i < n; ++i) {\n        if (!ff(1, i)) {\n     \
    \       auto nx = new node_t(i);\n            r = insert(r, 1, nx);\n        }\
    \ else if (ff(i, i)) {\n            auto nx = new node_t(i);\n            r =\
    \ insert(r, i + 1, nx);\n        } else {\n            int lo = 1, hi = i;\n \
    \           while (hi - lo > 1) {\n                int m = (lo + hi) / 2;\n  \
    \              if (ff(m, i)) {\n                    lo = m;\n                }\
    \ else {\n                    hi = m;\n                }\n            }\n    \
    \        auto nx = new node_t(i);\n            r = insert(r, hi, nx);\n      \
    \  }\n    }\n\n    vector<int> vs;\n    rep(i, n) {\n        auto nx = split(r,\
    \ 1);\n        vs.push_back(nx.fi->val);\n        r = nx.se;\n    }\n    return\
    \ vs;\n};\n"
  code: "// using treap\n// O(n log^2 n)\n\nauto hamilton = [&]() {\n    auto r =\
    \ new node_t(0);\n\n    // i -> j ?\n    auto comp = [&](int i, int j) {};\n\n\
    \    auto ff = [&](int pos, int p) {\n        int id = get(r, pos);\n        return\
    \ comp(id, p);\n    };\n\n    for (int i = 1; i < n; ++i) {\n        if (!ff(1,\
    \ i)) {\n            auto nx = new node_t(i);\n            r = insert(r, 1, nx);\n\
    \        } else if (ff(i, i)) {\n            auto nx = new node_t(i);\n      \
    \      r = insert(r, i + 1, nx);\n        } else {\n            int lo = 1, hi\
    \ = i;\n            while (hi - lo > 1) {\n                int m = (lo + hi) /\
    \ 2;\n                if (ff(m, i)) {\n                    lo = m;\n         \
    \       } else {\n                    hi = m;\n                }\n           \
    \ }\n            auto nx = new node_t(i);\n            r = insert(r, hi, nx);\n\
    \        }\n    }\n\n    vector<int> vs;\n    rep(i, n) {\n        auto nx = split(r,\
    \ 1);\n        vs.push_back(nx.fi->val);\n        r = nx.se;\n    }\n    return\
    \ vs;\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/graph/Tournament_Hamilton.cpp
  requiredBy: []
  timestamp: '2021-10-25 19:28:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/graph/Tournament_Hamilton.cpp
layout: document
redirect_from:
- /library/cpp_src/graph/Tournament_Hamilton.cpp
- /library/cpp_src/graph/Tournament_Hamilton.cpp.html
title: cpp_src/graph/Tournament_Hamilton.cpp
---
