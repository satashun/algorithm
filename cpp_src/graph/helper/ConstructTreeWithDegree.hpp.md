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
  bundledCode: "#line 1 \"cpp_src/graph/helper/ConstructTreeWithDegree.hpp\"\n// construct\
    \ tree with designated degrees\n// no such tree -> returns an empty vector\n//\
    \ AGC059B\n\nVV<int> construct_from_deg(V<int> deg) {\n    debug(deg);\n    int\
    \ kind = 0, sz = SZ(deg);\n    rep(i, sz) if (deg[i] > 0) kind++;\n\n    VV<int>\
    \ g;\n    ll sum = accumulate(ALL(deg), 0ll);\n    if (sum != (kind - 1) * 2)\
    \ return g;\n\n    g.resize(sz);\n    set<pii> st;\n    rep(i, SZ(deg)) if (deg[i]\
    \ > 0) st.emplace(deg[i], i);\n\n    while (SZ(st) > 1) {\n        auto [v1, c1]\
    \ = *st.begin();\n        st.erase(st.begin());\n        auto [v2, c2] = *(--st.end());\n\
    \        st.erase(mp(v2, c2));\n        if (v2 > 1) st.emplace(v2 - 1, c2);\n\
    \        g[c1].pb(c2);\n        g[c2].pb(c1);\n    }\n    return g;\n}\n"
  code: "// construct tree with designated degrees\n// no such tree -> returns an\
    \ empty vector\n// AGC059B\n\nVV<int> construct_from_deg(V<int> deg) {\n    debug(deg);\n\
    \    int kind = 0, sz = SZ(deg);\n    rep(i, sz) if (deg[i] > 0) kind++;\n\n \
    \   VV<int> g;\n    ll sum = accumulate(ALL(deg), 0ll);\n    if (sum != (kind\
    \ - 1) * 2) return g;\n\n    g.resize(sz);\n    set<pii> st;\n    rep(i, SZ(deg))\
    \ if (deg[i] > 0) st.emplace(deg[i], i);\n\n    while (SZ(st) > 1) {\n       \
    \ auto [v1, c1] = *st.begin();\n        st.erase(st.begin());\n        auto [v2,\
    \ c2] = *(--st.end());\n        st.erase(mp(v2, c2));\n        if (v2 > 1) st.emplace(v2\
    \ - 1, c2);\n        g[c1].pb(c2);\n        g[c2].pb(c1);\n    }\n    return g;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/graph/helper/ConstructTreeWithDegree.hpp
  requiredBy: []
  timestamp: '2023-12-31 13:48:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/graph/helper/ConstructTreeWithDegree.hpp
layout: document
redirect_from:
- /library/cpp_src/graph/helper/ConstructTreeWithDegree.hpp
- /library/cpp_src/graph/helper/ConstructTreeWithDegree.hpp.html
title: cpp_src/graph/helper/ConstructTreeWithDegree.hpp
---
