---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpp_src/math/Modular.hpp
    title: cpp_src/math/Modular.hpp
  - icon: ':warning:'
    path: cpp_src/other/FWT.hpp
    title: cpp_src/other/FWT.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/bitwise_xor_convolution
  bundledCode: "#line 1 \"test/yosupo/bitwise_xor_convolution.cpp\"\n//#pragma GCC\
    \ optimize(\"Ofast\")\n//#pragma GCC optimize(\"unroll-loops\")\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/bitwise_xor_convolution\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nusing ll = long long;\nusing pii = pair<int, int>;\ntemplate\
    \ <class T>\nusing V = vector<T>;\ntemplate <class T>\nusing VV = V<V<T>>;\n\n\
    #define pb push_back\n#define eb emplace_back\n#define mp make_pair\n#define fi\
    \ first\n#define se second\n#define rep(i, n) rep2(i, 0, n)\n#define rep2(i, m,\
    \ n) for (int i = m; i < (n); i++)\n#define per(i, b) per2(i, 0, b)\n#define per2(i,\
    \ a, b) for (int i = int(b) - 1; i >= int(a); i--)\n#define ALL(c) (c).begin(),\
    \ (c).end()\n#define SZ(x) ((int)(x).size())\n\nconstexpr ll TEN(int n) { return\
    \ (n == 0) ? 1 : 10 * TEN(n - 1); }\n\ntemplate <class T, class U>\nvoid chmin(T&\
    \ t, const U& u) {\n    if (t > u) t = u;\n}\ntemplate <class T, class U>\nvoid\
    \ chmax(T& t, const U& u) {\n    if (t < u) t = u;\n}\n\ntemplate <class T, class\
    \ U>\nostream& operator<<(ostream& os, const pair<T, U>& p) {\n    os << \"(\"\
    \ << p.first << \",\" << p.second << \")\";\n    return os;\n}\n\ntemplate <class\
    \ T>\nostream& operator<<(ostream& os, const vector<T>& v) {\n    os << \"{\"\
    ;\n    rep(i, v.size()) {\n        if (i) os << \",\";\n        os << v[i];\n\
    \    }\n    os << \"}\";\n    return os;\n}\n\n#ifdef LOCAL\nvoid debug_out()\
    \ { cerr << endl; }\ntemplate <typename Head, typename... Tail>\nvoid debug_out(Head\
    \ H, Tail... T) {\n    cerr << \" \" << H;\n    debug_out(T...);\n}\n#define debug(...)\
    \ \\\n    cerr << __LINE__ << \" [\" << #__VA_ARGS__ << \"]:\", debug_out(__VA_ARGS__)\n\
    #define dump(x) cerr << __LINE__ << \" \" << #x << \" = \" << (x) << endl\n#else\n\
    #define debug(...) (void(0))\n#define dump(x) (void(0))\n#endif\n\n#define call_from_test\n\
    #line 1 \"cpp_src/math/Modular.hpp\"\ntemplate <unsigned int MOD>\nstruct ModInt\
    \ {\n    using uint = unsigned int;\n    using ull = unsigned long long;\n   \
    \ using M = ModInt;\n\n    uint v;\n\n    ModInt(ll _v = 0) { set_norm(_v % MOD\
    \ + MOD); }\n    M& set_norm(uint _v) {  //[0, MOD * 2)->[0, MOD)\n        v =\
    \ (_v < MOD) ? _v : _v - MOD;\n        return *this;\n    }\n\n    explicit operator\
    \ bool() const { return v != 0; }\n    explicit operator int() const { return\
    \ v; }\n    M operator+(const M& a) const { return M().set_norm(v + a.v); }\n\
    \    M operator-(const M& a) const { return M().set_norm(v + MOD - a.v); }\n \
    \   M operator*(const M& a) const { return M().set_norm(ull(v) * a.v % MOD); }\n\
    \    M operator/(const M& a) const { return *this * a.inv(); }\n    M& operator+=(const\
    \ M& a) { return *this = *this + a; }\n    M& operator-=(const M& a) { return\
    \ *this = *this - a; }\n    M& operator*=(const M& a) { return *this = *this *\
    \ a; }\n    M& operator/=(const M& a) { return *this = *this / a; }\n    M operator-()\
    \ const { return M() - *this; }\n    M& operator++(int) { return *this = *this\
    \ + 1; }\n    M& operator--(int) { return *this = *this - 1; }\n\n    M pow(ll\
    \ n) const {\n        if (n < 0) return inv().pow(-n);\n        M x = *this, res\
    \ = 1;\n        while (n) {\n            if (n & 1) res *= x;\n            x *=\
    \ x;\n            n >>= 1;\n        }\n        return res;\n    }\n\n    M inv()\
    \ const {\n        ll a = v, b = MOD, p = 1, q = 0, t;\n        while (b != 0)\
    \ {\n            t = a / b;\n            swap(a -= t * b, b);\n            swap(p\
    \ -= t * q, q);\n        }\n        return M(p);\n    }\n\n    bool operator==(const\
    \ M& a) const { return v == a.v; }\n    bool operator!=(const M& a) const { return\
    \ v != a.v; }\n    friend ostream& operator<<(ostream& os, const M& a) { return\
    \ os << a.v; }\n    friend istream& operator>>(istream& in, M& x) { ll v_; in\
    \ >> v_; x = M(v_); return in; }\n    static uint get_mod() { return MOD; }\n\
    };\n\n// using Mint = ModInt<1000000007>;\n#line 1 \"cpp_src/other/FWT.hpp\"\n\
    //vector size : power of 2\n\ntemplate<class T>\nvoid and_fwt(vector<T>& f) {\n\
    \    int n = f.size();\n    for (int d = 1; d < n; d <<= 1) {\n        for (int\
    \ i = 0; i < n; i += d * 2) {\n            for (int j = 0; j < d; ++j) {\n   \
    \             T x = f[i+j], y = f[i+j+d];\n                f[i+j] = x + y;\n \
    \           }\n        }\n    }\n}\n\ntemplate<class T>\nvoid and_ifwt(vector<T>&\
    \ f) {\n    int n = f.size();\n    for (int d = 1; d < n; d <<= 1) {\n       \
    \ for (int i = 0; i < n; i += d * 2) {\n            for (int j = 0; j < d; ++j)\
    \ {\n                T x = f[i+j], y = f[i+j+d];\n                f[i+j] = x -\
    \ y;\n            }\n        }\n    }\n}\n\ntemplate <class T>\nvoid xor_fwt(vector<T>&\
    \ f, bool rev) {\n    int n = f.size();\n    for (int d = 1; d < n; d <<= 1) {\n\
    \        for (int i = 0; i < n; i += d * 2) {\n            for (int j = 0; j <\
    \ d; ++j) {\n                T x = f[i + j], y = f[i + j + d];\n             \
    \   f[i + j] = x + y;\n                f[i + j + d] = x - y;\n            }\n\
    \        }\n    }\n\n    if (rev) {\n        T r = T(1) / n;\n        for (auto&\
    \ x : f) x *= r;\n    }\n}\n#line 73 \"test/yosupo/bitwise_xor_convolution.cpp\"\
    \n#undef call_from_test\n\nusing Mint = ModInt<998244353>;\n\nint main() {\n \
    \   cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\n    int N;\n    cin\
    \ >> N;\n    V<Mint> a(1 << N), b(1 << N);\n    rep(i, 1 << N) cin >> a[i];\n\
    \    rep(i, 1 << N) cin >> b[i];\n\n    xor_fwt(a, false);\n    xor_fwt(b, false);\n\
    \    rep(i, 1 << N) a[i] *= b[i];\n    xor_fwt(a, true);\n    rep(i, 1 << N) {\
    \ cout << a[i] << (i + 1 == (1 << N) ? '\\n' : ' '); }\n\n    return 0;\n}\n"
  code: "//#pragma GCC optimize(\"Ofast\")\n//#pragma GCC optimize(\"unroll-loops\"\
    )\n#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_xor_convolution\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\nusing ll = long long;\n\
    using pii = pair<int, int>;\ntemplate <class T>\nusing V = vector<T>;\ntemplate\
    \ <class T>\nusing VV = V<V<T>>;\n\n#define pb push_back\n#define eb emplace_back\n\
    #define mp make_pair\n#define fi first\n#define se second\n#define rep(i, n) rep2(i,\
    \ 0, n)\n#define rep2(i, m, n) for (int i = m; i < (n); i++)\n#define per(i, b)\
    \ per2(i, 0, b)\n#define per2(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)\n\
    #define ALL(c) (c).begin(), (c).end()\n#define SZ(x) ((int)(x).size())\n\nconstexpr\
    \ ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }\n\ntemplate <class\
    \ T, class U>\nvoid chmin(T& t, const U& u) {\n    if (t > u) t = u;\n}\ntemplate\
    \ <class T, class U>\nvoid chmax(T& t, const U& u) {\n    if (t < u) t = u;\n\
    }\n\ntemplate <class T, class U>\nostream& operator<<(ostream& os, const pair<T,\
    \ U>& p) {\n    os << \"(\" << p.first << \",\" << p.second << \")\";\n    return\
    \ os;\n}\n\ntemplate <class T>\nostream& operator<<(ostream& os, const vector<T>&\
    \ v) {\n    os << \"{\";\n    rep(i, v.size()) {\n        if (i) os << \",\";\n\
    \        os << v[i];\n    }\n    os << \"}\";\n    return os;\n}\n\n#ifdef LOCAL\n\
    void debug_out() { cerr << endl; }\ntemplate <typename Head, typename... Tail>\n\
    void debug_out(Head H, Tail... T) {\n    cerr << \" \" << H;\n    debug_out(T...);\n\
    }\n#define debug(...) \\\n    cerr << __LINE__ << \" [\" << #__VA_ARGS__ << \"\
    ]:\", debug_out(__VA_ARGS__)\n#define dump(x) cerr << __LINE__ << \" \" << #x\
    \ << \" = \" << (x) << endl\n#else\n#define debug(...) (void(0))\n#define dump(x)\
    \ (void(0))\n#endif\n\n#define call_from_test\n#include \"../../cpp_src/math/Modular.hpp\"\
    \n#include \"../../cpp_src/other/FWT.hpp\"\n#undef call_from_test\n\nusing Mint\
    \ = ModInt<998244353>;\n\nint main() {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n\
    \n    int N;\n    cin >> N;\n    V<Mint> a(1 << N), b(1 << N);\n    rep(i, 1 <<\
    \ N) cin >> a[i];\n    rep(i, 1 << N) cin >> b[i];\n\n    xor_fwt(a, false);\n\
    \    xor_fwt(b, false);\n    rep(i, 1 << N) a[i] *= b[i];\n    xor_fwt(a, true);\n\
    \    rep(i, 1 << N) { cout << a[i] << (i + 1 == (1 << N) ? '\\n' : ' '); }\n\n\
    \    return 0;\n}"
  dependsOn:
  - cpp_src/math/Modular.hpp
  - cpp_src/other/FWT.hpp
  isVerificationFile: false
  path: test/yosupo/bitwise_xor_convolution.cpp
  requiredBy: []
  timestamp: '2021-02-19 20:19:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/yosupo/bitwise_xor_convolution.cpp
layout: document
redirect_from:
- /library/test/yosupo/bitwise_xor_convolution.cpp
- /library/test/yosupo/bitwise_xor_convolution.cpp.html
title: test/yosupo/bitwise_xor_convolution.cpp
---
