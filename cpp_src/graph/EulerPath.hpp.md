---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - https://codeforces.com/contest/508/submission/92099335
  bundledCode: "#line 1 \"cpp_src/graph/EulerPath.hpp\"\n// Hierholzer algorithm\n\
    // https://codeforces.com/contest/508/submission/92099335\n\n// directed\n// destruct\
    \ graph\n\ntemplate <class E>\nV<int> EulerianPath(const int s, VV<E>& g) {\n\
    \    auto dfs = [&](auto&& self, int u, V<int>& path) -> void {\n        while\
    \ (!g[u].empty()) {\n            int v = g[u].back();  // E : int\n          \
    \  g[u].pop_back();\n            self(self, v, path);\n        }\n        path.push_back(u);\n\
    \    };\n    V<int> path;\n    dfs(dfs, s, path);\n    reverse(path.begin(), path.end());\n\
    \    return path;\n}\n"
  code: "// Hierholzer algorithm\n// https://codeforces.com/contest/508/submission/92099335\n\
    \n// directed\n// destruct graph\n\ntemplate <class E>\nV<int> EulerianPath(const\
    \ int s, VV<E>& g) {\n    auto dfs = [&](auto&& self, int u, V<int>& path) ->\
    \ void {\n        while (!g[u].empty()) {\n            int v = g[u].back();  //\
    \ E : int\n            g[u].pop_back();\n            self(self, v, path);\n  \
    \      }\n        path.push_back(u);\n    };\n    V<int> path;\n    dfs(dfs, s,\
    \ path);\n    reverse(path.begin(), path.end());\n    return path;\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/graph/EulerPath.hpp
  requiredBy: []
  timestamp: '2020-09-11 21:28:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/graph/EulerPath.hpp
layout: document
redirect_from:
- /library/cpp_src/graph/EulerPath.hpp
- /library/cpp_src/graph/EulerPath.hpp.html
title: cpp_src/graph/EulerPath.hpp
---
