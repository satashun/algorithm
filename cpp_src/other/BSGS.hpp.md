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
  bundledCode: "#line 1 \"cpp_src/other/BSGS.hpp\"\n// Baby Step Giant Step\n// ABC270G\n\
    // x_0 = S, x_{i+1}= (Ax_i + B) % P\n// smallest i s.t. x_i = G\n\nll BSGS(int\
    \ P, int A, int B, int S, int G) {\n    const int L = sqrt(P) + 1;\n\n    using\
    \ mint = atcoder::modint;\n    mint::set_mod(P);\n\n    if (S == G) {\n      \
    \  return 0;\n    }\n\n    if (A == 0) {\n        // S,B,B,..\n        if (G ==\
    \ B) {\n            return 1;\n        } else {\n            return -1;\n    \
    \    }\n    }\n\n    V<pair<mint, mint>> vs(L + 1);\n    vs[0] = mp(mint(1), mint(0));\n\
    \    rep(i, L) {\n        auto [a, b] = vs[i];\n        vs[i + 1] = mp(a * A,\
    \ b * A + B);\n    }\n\n    unordered_map<int, int> T;\n    rep(i, L) {\n    \
    \    auto [a, b] = vs[i];\n        auto r = mint(G - b) * a.inv();\n        if\
    \ (!T.count(r.val())) {\n            T[r.val()] = i;\n        }\n    }\n\n   \
    \ mint cur = S;\n    for (int i = 0; i < P; i += L) {\n        // cur*a+b=G\n\
    \        if (T.count(cur.val())) {\n            return i + T[cur.val()];\n   \
    \     }\n        cur = cur * vs[L].fi + vs[L].se;\n    }\n    return -1;\n}\n"
  code: "// Baby Step Giant Step\n// ABC270G\n// x_0 = S, x_{i+1}= (Ax_i + B) % P\n\
    // smallest i s.t. x_i = G\n\nll BSGS(int P, int A, int B, int S, int G) {\n \
    \   const int L = sqrt(P) + 1;\n\n    using mint = atcoder::modint;\n    mint::set_mod(P);\n\
    \n    if (S == G) {\n        return 0;\n    }\n\n    if (A == 0) {\n        //\
    \ S,B,B,..\n        if (G == B) {\n            return 1;\n        } else {\n \
    \           return -1;\n        }\n    }\n\n    V<pair<mint, mint>> vs(L + 1);\n\
    \    vs[0] = mp(mint(1), mint(0));\n    rep(i, L) {\n        auto [a, b] = vs[i];\n\
    \        vs[i + 1] = mp(a * A, b * A + B);\n    }\n\n    unordered_map<int, int>\
    \ T;\n    rep(i, L) {\n        auto [a, b] = vs[i];\n        auto r = mint(G -\
    \ b) * a.inv();\n        if (!T.count(r.val())) {\n            T[r.val()] = i;\n\
    \        }\n    }\n\n    mint cur = S;\n    for (int i = 0; i < P; i += L) {\n\
    \        // cur*a+b=G\n        if (T.count(cur.val())) {\n            return i\
    \ + T[cur.val()];\n        }\n        cur = cur * vs[L].fi + vs[L].se;\n    }\n\
    \    return -1;\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/other/BSGS.hpp
  requiredBy: []
  timestamp: '2023-01-02 15:43:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/other/BSGS.hpp
layout: document
redirect_from:
- /library/cpp_src/other/BSGS.hpp
- /library/cpp_src/other/BSGS.hpp.html
title: cpp_src/other/BSGS.hpp
---
