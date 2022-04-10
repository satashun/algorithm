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
  bundledCode: "#line 1 \"cpp_src/math/FFTArbitraryMod.hpp\"\n/// g:gcd(a, b), ax+by=g\n\
    struct EG {\n    ll g, x, y;\n};\n\nEG ext_gcd(ll a, ll b) {\n    if (b == 0)\
    \ {\n        if (a >= 0)\n            return EG{a, 1, 0};\n        else\n    \
    \        return EG{-a, -1, 0};\n    } else {\n        auto e = ext_gcd(b, a %\
    \ b);\n        return EG{e.g, e.y, e.x - a / b * e.y};\n    }\n}\n\nll inv_mod(ll\
    \ x, ll md) {\n    auto z = ext_gcd(x, md).x;\n    return (z % md + md) % md;\n\
    }\n\ntemplate <class T>\nT zmod(T a, T b) {\n    a %= b;\n    if (a < 0) a +=\
    \ b;\n    return a;\n}\n\n// \u3053\u3053\u3092 mod \u306B\u5FDC\u3058\u3066\u9069\
    \u5207\u306B\u5909\u3048\u308B\nll mulmod(ll x, ll y, ll mod) { return x * y %\
    \ mod; }\n\nll garner(const V<ll>& b, const V<ll>& c) {\n    vector<ll> coffs(b.size(),\
    \ 1);\n    vector<ll> constants(b.size(), 0);\n\n    rep(i, (int)b.size() - 1)\
    \ {\n        // coffs[i] * v + constants[i] == mr[i].second (mod mr[i].first)\
    \ \u3092\u89E3\u304F\n        ll v = mulmod(zmod(b[i] - constants[i], c[i]), inv_mod(coffs[i],\
    \ c[i]),\n                      c[i]);\n        assert(v >= 0);\n\n        for\
    \ (int j = i + 1; j < (int)b.size(); j++) {\n            (constants[j] += mulmod(coffs[j],\
    \ v, c[j])) %= c[j];\n            coffs[j] = mulmod(coffs[j], c[i], c[j]);\n \
    \       }\n    }\n\n    return constants[b.size() - 1];\n}\n\nusing Mint1 = ModInt<1012924417>;\
    \  // 5\nusing Mint2 = ModInt<1224736769>;  // 3\nusing Mint3 = ModInt<1007681537>;\
    \  // 3\nusing Mint4 = ModInt<1045430273>;  // 4\n\nNumberTheoreticTransform<Mint1>\
    \ ntt1;\nNumberTheoreticTransform<Mint2> ntt2;\nNumberTheoreticTransform<Mint3>\
    \ ntt3;\nNumberTheoreticTransform<Mint4> ntt4;\n\n// D : modint\ntemplate <class\
    \ D>\nV<D> arbmod_convolution(V<D> _a, V<D> _b, ll mod) {\n    V<ll> a(SZ(_a)),\
    \ b(SZ(_b));\n    rep(i, SZ(_a)) a[i] = _a[i].v;\n    rep(i, SZ(_b)) b[i] = _b[i].v;\n\
    \    V<Mint1> a1(ALL(a)), b1(ALL(b));\n    V<Mint2> a2(ALL(a)), b2(ALL(b));\n\
    \    V<Mint3> a3(ALL(a)), b3(ALL(b));\n    V<Mint4> a4(ALL(a)), b4(ALL(b));\n\n\
    \    auto x = ntt1.mul(a1, b1);\n    auto y = ntt2.mul(a2, b2);\n    auto z =\
    \ ntt3.mul(a3, b3);\n    auto w = ntt4.mul(a4, b4);\n\n    V<D> res(x.size());\n\
    \    V<ll> c{1012924417, 1224736769, 1007681537, 1045430273, mod};\n\n    rep(i,\
    \ SZ(x)) {\n        V<ll> b{x[i].v, y[i].v, z[i].v, w[i].v, 0ll};\n        res[i]\
    \ = garner(b, c);\n    }\n\n    return res;\n}\n\nint main() {\n    int N, M;\n\
    \    scanf(\"%d %d\", &N, &M);\n    V<ll> a(N), b(M);\n    rep(i, N) { scanf(\"\
    %d\", &a[i]); }\n    rep(i, M) { scanf(\"%d\", &b[i]); }\n    auto res = arbmod_convolution(a,\
    \ b, TEN(9) + 7);\n    int sz = res.size();\n    rep(i, sz) printf(\"%d%c\", res[i],\
    \ i == sz - 1 ? '\\n' : ' ');\n\n    return 0;\n}\n"
  code: "/// g:gcd(a, b), ax+by=g\nstruct EG {\n    ll g, x, y;\n};\n\nEG ext_gcd(ll\
    \ a, ll b) {\n    if (b == 0) {\n        if (a >= 0)\n            return EG{a,\
    \ 1, 0};\n        else\n            return EG{-a, -1, 0};\n    } else {\n    \
    \    auto e = ext_gcd(b, a % b);\n        return EG{e.g, e.y, e.x - a / b * e.y};\n\
    \    }\n}\n\nll inv_mod(ll x, ll md) {\n    auto z = ext_gcd(x, md).x;\n    return\
    \ (z % md + md) % md;\n}\n\ntemplate <class T>\nT zmod(T a, T b) {\n    a %= b;\n\
    \    if (a < 0) a += b;\n    return a;\n}\n\n// \u3053\u3053\u3092 mod \u306B\u5FDC\
    \u3058\u3066\u9069\u5207\u306B\u5909\u3048\u308B\nll mulmod(ll x, ll y, ll mod)\
    \ { return x * y % mod; }\n\nll garner(const V<ll>& b, const V<ll>& c) {\n   \
    \ vector<ll> coffs(b.size(), 1);\n    vector<ll> constants(b.size(), 0);\n\n \
    \   rep(i, (int)b.size() - 1) {\n        // coffs[i] * v + constants[i] == mr[i].second\
    \ (mod mr[i].first) \u3092\u89E3\u304F\n        ll v = mulmod(zmod(b[i] - constants[i],\
    \ c[i]), inv_mod(coffs[i], c[i]),\n                      c[i]);\n        assert(v\
    \ >= 0);\n\n        for (int j = i + 1; j < (int)b.size(); j++) {\n          \
    \  (constants[j] += mulmod(coffs[j], v, c[j])) %= c[j];\n            coffs[j]\
    \ = mulmod(coffs[j], c[i], c[j]);\n        }\n    }\n\n    return constants[b.size()\
    \ - 1];\n}\n\nusing Mint1 = ModInt<1012924417>;  // 5\nusing Mint2 = ModInt<1224736769>;\
    \  // 3\nusing Mint3 = ModInt<1007681537>;  // 3\nusing Mint4 = ModInt<1045430273>;\
    \  // 4\n\nNumberTheoreticTransform<Mint1> ntt1;\nNumberTheoreticTransform<Mint2>\
    \ ntt2;\nNumberTheoreticTransform<Mint3> ntt3;\nNumberTheoreticTransform<Mint4>\
    \ ntt4;\n\n// D : modint\ntemplate <class D>\nV<D> arbmod_convolution(V<D> _a,\
    \ V<D> _b, ll mod) {\n    V<ll> a(SZ(_a)), b(SZ(_b));\n    rep(i, SZ(_a)) a[i]\
    \ = _a[i].v;\n    rep(i, SZ(_b)) b[i] = _b[i].v;\n    V<Mint1> a1(ALL(a)), b1(ALL(b));\n\
    \    V<Mint2> a2(ALL(a)), b2(ALL(b));\n    V<Mint3> a3(ALL(a)), b3(ALL(b));\n\
    \    V<Mint4> a4(ALL(a)), b4(ALL(b));\n\n    auto x = ntt1.mul(a1, b1);\n    auto\
    \ y = ntt2.mul(a2, b2);\n    auto z = ntt3.mul(a3, b3);\n    auto w = ntt4.mul(a4,\
    \ b4);\n\n    V<D> res(x.size());\n    V<ll> c{1012924417, 1224736769, 1007681537,\
    \ 1045430273, mod};\n\n    rep(i, SZ(x)) {\n        V<ll> b{x[i].v, y[i].v, z[i].v,\
    \ w[i].v, 0ll};\n        res[i] = garner(b, c);\n    }\n\n    return res;\n}\n\
    \nint main() {\n    int N, M;\n    scanf(\"%d %d\", &N, &M);\n    V<ll> a(N),\
    \ b(M);\n    rep(i, N) { scanf(\"%d\", &a[i]); }\n    rep(i, M) { scanf(\"%d\"\
    , &b[i]); }\n    auto res = arbmod_convolution(a, b, TEN(9) + 7);\n    int sz\
    \ = res.size();\n    rep(i, sz) printf(\"%d%c\", res[i], i == sz - 1 ? '\\n' :\
    \ ' ');\n\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/math/FFTArbitraryMod.hpp
  requiredBy: []
  timestamp: '2022-04-10 12:39:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/math/FFTArbitraryMod.hpp
layout: document
redirect_from:
- /library/cpp_src/math/FFTArbitraryMod.hpp
- /library/cpp_src/math/FFTArbitraryMod.hpp.html
title: cpp_src/math/FFTArbitraryMod.hpp
---
