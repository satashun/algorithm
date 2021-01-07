---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cpp_src/math/MultipointEvaluation.hpp\"\ntemplate<class\
    \ D>\nstruct MultiEval {\n\tusing P = MultiEval*;\n\tP lc, rc;\n\tV<D> xs;\n\t\
    int sz;\n\tPoly<D> dpol;\n\n\tconst int B = 100;\n\n\tMultiEval(const V<D>& _xs,\
    \ int l, int r) : sz(r - l) {\n\t\tif (r - l <= B) {\n\t\t\txs = {_xs.begin()\
    \ + l, _xs.begin() + r};\n\t\t\tdpol = {{1}};\n\t\t\tfor (auto x : xs) {\n\t\t\
    \t\tdpol *= {-x, 1};\n\t\t\t}\n\t\t\treturn ;\n\t\t}\n\t\tlc = new MultiEval(_xs,\
    \ l, (l + r) / 2);\n\t\trc = new MultiEval(_xs, (l + r) / 2, r);\n\t\tdpol = lc->dpol\
    \ * rc->dpol;\n\t}\n\n\tMultiEval(const V<D>& xs) : MultiEval(xs, 0, xs.size())\
    \ {}\n\n\tvoid eval(const Poly<D>& poly, V<D>& res) {\n\t\tauto p = poly % dpol;\n\
    \t\tif (sz <= B) {\n\t\t\tfor (auto x : xs) {\n\t\t\t\tres.pb(p.eval(x));\n\t\t\
    \t}\n\t\t\treturn ;\n\t\t}\n\t\tlc->eval(p, res);\n\t\trc->eval(p, res);\n\t}\n\
    \n\tV<D> eval(const Poly<D>& poly) {\n\t\tV<D> res;\n\t\teval(poly, res);\n\t\t\
    return res;\n\t}\n};\n"
  code: "template<class D>\nstruct MultiEval {\n\tusing P = MultiEval*;\n\tP lc, rc;\n\
    \tV<D> xs;\n\tint sz;\n\tPoly<D> dpol;\n\n\tconst int B = 100;\n\n\tMultiEval(const\
    \ V<D>& _xs, int l, int r) : sz(r - l) {\n\t\tif (r - l <= B) {\n\t\t\txs = {_xs.begin()\
    \ + l, _xs.begin() + r};\n\t\t\tdpol = {{1}};\n\t\t\tfor (auto x : xs) {\n\t\t\
    \t\tdpol *= {-x, 1};\n\t\t\t}\n\t\t\treturn ;\n\t\t}\n\t\tlc = new MultiEval(_xs,\
    \ l, (l + r) / 2);\n\t\trc = new MultiEval(_xs, (l + r) / 2, r);\n\t\tdpol = lc->dpol\
    \ * rc->dpol;\n\t}\n\n\tMultiEval(const V<D>& xs) : MultiEval(xs, 0, xs.size())\
    \ {}\n\n\tvoid eval(const Poly<D>& poly, V<D>& res) {\n\t\tauto p = poly % dpol;\n\
    \t\tif (sz <= B) {\n\t\t\tfor (auto x : xs) {\n\t\t\t\tres.pb(p.eval(x));\n\t\t\
    \t}\n\t\t\treturn ;\n\t\t}\n\t\tlc->eval(p, res);\n\t\trc->eval(p, res);\n\t}\n\
    \n\tV<D> eval(const Poly<D>& poly) {\n\t\tV<D> res;\n\t\teval(poly, res);\n\t\t\
    return res;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/math/MultipointEvaluation.hpp
  requiredBy: []
  timestamp: '2020-09-17 22:13:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/math/MultipointEvaluation.hpp
layout: document
redirect_from:
- /library/cpp_src/math/MultipointEvaluation.hpp
- /library/cpp_src/math/MultipointEvaluation.hpp.html
title: cpp_src/math/MultipointEvaluation.hpp
---
