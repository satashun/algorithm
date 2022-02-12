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
  bundledCode: "#line 1 \"cpp_src/other/ConvexHull.hpp\"\ntemplate <class T>\nusing\
    \ Point = complex<T>;\n\ntemplate <class T>\nT cross(const Point<T> &a, const\
    \ Point<T> &b) {\n    return (conj(a) * b).imag();\n}\n\n// ARC130F\n// lower\
    \ convex hull of (i, a[i])\n// returns: indices\ntemplate <class T>\nV<int> convex_hull(const\
    \ V<T> &a) {\n    using P = Point<T>;\n    int n = SZ(a);\n    V<P> pt(n);\n \
    \   rep(i, n) pt[i] = P(i, a[i]);\n\n    V<int> vec;\n    rep(i, n) {\n      \
    \  while (vec.size() > 1 && cross(pt[vec.end()[-1]] - pt[vec.end()[-2]],\n   \
    \                                    pt[i] - pt[vec.end()[-1]]) <= 0) {\n    \
    \        vec.pop_back();\n        }\n        vec.pb(i);\n    }\n    return vec;\n\
    }\n"
  code: "template <class T>\nusing Point = complex<T>;\n\ntemplate <class T>\nT cross(const\
    \ Point<T> &a, const Point<T> &b) {\n    return (conj(a) * b).imag();\n}\n\n//\
    \ ARC130F\n// lower convex hull of (i, a[i])\n// returns: indices\ntemplate <class\
    \ T>\nV<int> convex_hull(const V<T> &a) {\n    using P = Point<T>;\n    int n\
    \ = SZ(a);\n    V<P> pt(n);\n    rep(i, n) pt[i] = P(i, a[i]);\n\n    V<int> vec;\n\
    \    rep(i, n) {\n        while (vec.size() > 1 && cross(pt[vec.end()[-1]] - pt[vec.end()[-2]],\n\
    \                                       pt[i] - pt[vec.end()[-1]]) <= 0) {\n \
    \           vec.pop_back();\n        }\n        vec.pb(i);\n    }\n    return\
    \ vec;\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/other/ConvexHull.hpp
  requiredBy: []
  timestamp: '2022-02-12 18:33:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/other/ConvexHull.hpp
layout: document
redirect_from:
- /library/cpp_src/other/ConvexHull.hpp
- /library/cpp_src/other/ConvexHull.hpp.html
title: cpp_src/other/ConvexHull.hpp
---
