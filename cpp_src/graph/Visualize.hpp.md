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
  bundledCode: "#line 1 \"cpp_src/graph/Visualize.hpp\"\n// label : index\n// dot\
    \ -Tsvg a.DOT -o a.svg\n\ntemplate <class T>\nvoid to_graphviz(const Graph<T>\
    \ g, string filename, bool directed = false) {\n    ofstream ss(filename + \"\
    .DOT\");\n    if (directed) {\n        ss << \"digraph{\\n\";\n        for (int\
    \ i = 0; i < g.size(); ++i) {\n            for (auto e : g[i]) {\n           \
    \     ss << i << \"->\" << e.to << \"[label=\\\"index=\" << e.idx\n          \
    \         << \", cost=\" << e.cost << \"\\\"];\\n\";\n            }\n        }\n\
    \    } else {\n        ss << \"graph{\\n\";\n        for (int i = 0; i < g.size();\
    \ ++i) {\n            for (auto e : g[i]) {\n                if (e.to > i) {\n\
    \                    ss << i << \"--\" << e.to << \"[label=\\\"index=\" << e.idx\n\
    \                       << \", cost=\" << e.cost << \"\\\"];\\n\";\n         \
    \       }\n            }\n        }\n    }\n\n    ss << \"}\\n\";\n    ss.close();\n\
    \    return;\n}\n"
  code: "// label : index\n// dot -Tsvg a.DOT -o a.svg\n\ntemplate <class T>\nvoid\
    \ to_graphviz(const Graph<T> g, string filename, bool directed = false) {\n  \
    \  ofstream ss(filename + \".DOT\");\n    if (directed) {\n        ss << \"digraph{\\\
    n\";\n        for (int i = 0; i < g.size(); ++i) {\n            for (auto e :\
    \ g[i]) {\n                ss << i << \"->\" << e.to << \"[label=\\\"index=\"\
    \ << e.idx\n                   << \", cost=\" << e.cost << \"\\\"];\\n\";\n  \
    \          }\n        }\n    } else {\n        ss << \"graph{\\n\";\n        for\
    \ (int i = 0; i < g.size(); ++i) {\n            for (auto e : g[i]) {\n      \
    \          if (e.to > i) {\n                    ss << i << \"--\" << e.to << \"\
    [label=\\\"index=\" << e.idx\n                       << \", cost=\" << e.cost\
    \ << \"\\\"];\\n\";\n                }\n            }\n        }\n    }\n\n  \
    \  ss << \"}\\n\";\n    ss.close();\n    return;\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/graph/Visualize.hpp
  requiredBy: []
  timestamp: '2021-10-17 02:35:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/graph/Visualize.hpp
layout: document
redirect_from:
- /library/cpp_src/graph/Visualize.hpp
- /library/cpp_src/graph/Visualize.hpp.html
title: cpp_src/graph/Visualize.hpp
---
