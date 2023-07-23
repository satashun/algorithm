---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://yukicoder.me/submissions/869720
  bundledCode: "#line 1 \"cpp_src/math/MultipointEvaluation.hpp\"\n// yukicoder 2243\n\
    // https://yukicoder.me/submissions/869720\ntemplate <class D>\nstruct MultiEval\
    \ {\n    using P = MultiEval*;\n    P lc, rc;\n    V<D> xs;\n    int sz;\n   \
    \ Poly<D> dpol;\n\n    const int B = 100;\n\n    MultiEval(const V<D>& _xs, int\
    \ l, int r) : sz(r - l) {\n        if (r - l <= B) {\n            xs = {_xs.begin()\
    \ + l, _xs.begin() + r};\n            dpol = {{1}};\n            for (auto x :\
    \ xs) {\n                dpol *= {-x, 1};\n            }\n            return;\n\
    \        }\n        lc = new MultiEval(_xs, l, (l + r) / 2);\n        rc = new\
    \ MultiEval(_xs, (l + r) / 2, r);\n        dpol = lc->dpol * rc->dpol;\n    }\n\
    \n    MultiEval(const V<D>& xs) : MultiEval(xs, 0, xs.size()) {}\n\n    void eval(const\
    \ Poly<D>& poly, V<D>& res) {\n        auto p = poly % dpol;\n        if (sz <=\
    \ B) {\n            for (auto x : xs) {\n                res.pb(p.eval(x));\n\
    \            }\n            return;\n        }\n        lc->eval(p, res);\n  \
    \      rc->eval(p, res);\n    }\n\n    V<D> eval(const Poly<D>& poly) {\n    \
    \    V<D> res;\n        eval(poly, res);\n        return res;\n    }\n};\n"
  code: "// yukicoder 2243\n// https://yukicoder.me/submissions/869720\ntemplate <class\
    \ D>\nstruct MultiEval {\n    using P = MultiEval*;\n    P lc, rc;\n    V<D> xs;\n\
    \    int sz;\n    Poly<D> dpol;\n\n    const int B = 100;\n\n    MultiEval(const\
    \ V<D>& _xs, int l, int r) : sz(r - l) {\n        if (r - l <= B) {\n        \
    \    xs = {_xs.begin() + l, _xs.begin() + r};\n            dpol = {{1}};\n   \
    \         for (auto x : xs) {\n                dpol *= {-x, 1};\n            }\n\
    \            return;\n        }\n        lc = new MultiEval(_xs, l, (l + r) /\
    \ 2);\n        rc = new MultiEval(_xs, (l + r) / 2, r);\n        dpol = lc->dpol\
    \ * rc->dpol;\n    }\n\n    MultiEval(const V<D>& xs) : MultiEval(xs, 0, xs.size())\
    \ {}\n\n    void eval(const Poly<D>& poly, V<D>& res) {\n        auto p = poly\
    \ % dpol;\n        if (sz <= B) {\n            for (auto x : xs) {\n         \
    \       res.pb(p.eval(x));\n            }\n            return;\n        }\n  \
    \      lc->eval(p, res);\n        rc->eval(p, res);\n    }\n\n    V<D> eval(const\
    \ Poly<D>& poly) {\n        V<D> res;\n        eval(poly, res);\n        return\
    \ res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/math/MultipointEvaluation.hpp
  requiredBy: []
  timestamp: '2023-07-23 15:21:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/math/MultipointEvaluation.hpp
layout: document
redirect_from:
- /library/cpp_src/math/MultipointEvaluation.hpp
- /library/cpp_src/math/MultipointEvaluation.hpp.html
title: cpp_src/math/MultipointEvaluation.hpp
---
