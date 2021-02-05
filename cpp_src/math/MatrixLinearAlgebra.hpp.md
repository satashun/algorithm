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
  bundledCode: "#line 1 \"cpp_src/math/MatrixLinearAlgebra.hpp\"\ntemplate <class\
    \ T>\nstruct Matrix : VV<D> {\n    using Mat = Matrix<T>;\n    int H() const {\
    \ return int(size()); }\n    int W() const { return int((*this)[0].size();) }\n\
    \n    Mat operator*(const Mat& a) const {\n        int h = H(), w = W();\n   \
    \     int h2 = a.H(), w2 = a.W();\n        assert(w == h2);\n        Mat res(h,\
    \ V<T>(w2));\n\n        for (int i = 0; i < h; ++i) {\n            for (int j\
    \ = 0; j < w2; ++j) {\n                for (int k = 0; k < w; ++k) {\n       \
    \             res[i][j] += (*this)[i][k] * a[k][j];\n                }\n     \
    \       }\n        }\n        return res;\n    }\n\n    Mat& operator*=(const\
    \ Mat& r) { return *this = *this * r; }\n\n    Mat pow(ll n) const {\n       \
    \ assert(H() == W());\n        int h = H();\n        Mat x = *this, res(h, V<T>(h));\n\
    \        for (int i = 0; i < h; ++i) {\n            res[i] = T(1);\n        }\n\
    \        while (n > 0) {\n            if (n & 1) res *= x;\n            x *= x;\n\
    \            n >>= 1;\n        }\n        return res;\n    }\n};\n"
  code: "template <class T>\nstruct Matrix : VV<D> {\n    using Mat = Matrix<T>;\n\
    \    int H() const { return int(size()); }\n    int W() const { return int((*this)[0].size();)\
    \ }\n\n    Mat operator*(const Mat& a) const {\n        int h = H(), w = W();\n\
    \        int h2 = a.H(), w2 = a.W();\n        assert(w == h2);\n        Mat res(h,\
    \ V<T>(w2));\n\n        for (int i = 0; i < h; ++i) {\n            for (int j\
    \ = 0; j < w2; ++j) {\n                for (int k = 0; k < w; ++k) {\n       \
    \             res[i][j] += (*this)[i][k] * a[k][j];\n                }\n     \
    \       }\n        }\n        return res;\n    }\n\n    Mat& operator*=(const\
    \ Mat& r) { return *this = *this * r; }\n\n    Mat pow(ll n) const {\n       \
    \ assert(H() == W());\n        int h = H();\n        Mat x = *this, res(h, V<T>(h));\n\
    \        for (int i = 0; i < h; ++i) {\n            res[i] = T(1);\n        }\n\
    \        while (n > 0) {\n            if (n & 1) res *= x;\n            x *= x;\n\
    \            n >>= 1;\n        }\n        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/math/MatrixLinearAlgebra.hpp
  requiredBy: []
  timestamp: '2020-09-17 22:16:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/math/MatrixLinearAlgebra.hpp
layout: document
redirect_from:
- /library/cpp_src/math/MatrixLinearAlgebra.hpp
- /library/cpp_src/math/MatrixLinearAlgebra.hpp.html
title: cpp_src/math/MatrixLinearAlgebra.hpp
---
