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
  bundledCode: "#line 1 \"cpp_src/math/FormalPowerSeriesArbitrary.hpp\"\n/// g:gcd(a,\
    \ b), ax+by=g\nstruct EG {\n    ll g, x, y;\n};\n\nEG ext_gcd(ll a, ll b) {\n\
    \    if (b == 0) {\n        if (a >= 0)\n            return EG{a, 1, 0};\n   \
    \     else\n            return EG{-a, -1, 0};\n    } else {\n        auto e =\
    \ ext_gcd(b, a % b);\n        return EG{e.g, e.y, e.x - a / b * e.y};\n    }\n\
    }\n\nll inv_mod(ll x, ll md) {\n    auto z = ext_gcd(x, md).x;\n    return (z\
    \ % md + md) % md;\n}\n\ntemplate <class T>\nT zmod(T a, T b) {\n    a %= b;\n\
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
    \ntemplate <class D>\nstruct Poly : public V<D> {\n    template <class... Args>\n\
    \    Poly(Args... args) : V<D>(args...) {}\n    Poly(initializer_list<D> init)\
    \ : V<D>(init.begin(), init.end()) {}\n\n    int size() const { return V<D>::size();\
    \ }\n    D at(int p) const { return (p < this->size() ? (*this)[p] : D(0)); }\n\
    \n    void shrink() {\n        while (this->size() > 0 && this->back() == D(0))\
    \ this->pop_back();\n    }\n\n    // first len terms\n    Poly pref(int len) const\
    \ {\n        return Poly(this->begin(), this->begin() + min(this->size(), len));\n\
    \    }\n\n    // for polynomial division\n    Poly rev() const {\n        Poly\
    \ res = *this;\n        reverse(res.begin(), res.end());\n        return res;\n\
    \    }\n\n    Poly shiftr(int d) const {\n        int n = max(size() + d, 0);\n\
    \        Poly res(n);\n        for (int i = 0; i < size(); ++i) {\n          \
    \  if (i + d >= 0) {\n                res[i + d] = at(i);\n            }\n   \
    \     }\n        return res;\n    }\n\n    Poly operator+(const Poly& r) const\
    \ {\n        auto n = max(size(), r.size());\n        V<D> tmp(n);\n        for\
    \ (int i = 0; i < n; ++i) {\n            tmp[i] = at(i) + r.at(i);\n        }\n\
    \        return tmp;\n    }\n    Poly operator-(const Poly& r) const {\n     \
    \   auto n = max(size(), r.size());\n        V<D> tmp(n);\n        for (int i\
    \ = 0; i < n; ++i) {\n            tmp[i] = at(i) - r.at(i);\n        }\n     \
    \   return tmp;\n    }\n\n    // scalar\n    Poly operator*(const D& k) const\
    \ {\n        int n = size();\n        V<D> tmp(n);\n        for (int i = 0; i\
    \ < n; ++i) {\n            tmp[i] = at(i) * k;\n        }\n        return tmp;\n\
    \    }\n\n    Poly operator*(const Poly& r) const {\n        Poly a = *this;\n\
    \        Poly b = r;\n        auto v = arbmod_convolution(a, b, D::get_mod());\n\
    \        return v;\n    }\n\n    // scalar\n    Poly operator/(const D& k) const\
    \ { return *this * k.inv(); }\n\n    Poly operator/(const Poly& r) const {\n \
    \       if (size() < r.size()) {\n            return {{}};\n        }\n      \
    \  int d = size() - r.size() + 1;\n        return (rev().pref(d) * r.rev().inv(d)).pref(d).rev();\n\
    \    }\n\n    Poly operator%(const Poly& r) const {\n        auto res = *this\
    \ - *this / r * r;\n        res.shrink();\n        return res;\n    }\n\n    Poly\
    \ diff() const {\n        V<D> res(max(0, size() - 1));\n        for (int i =\
    \ 1; i < size(); ++i) {\n            res[i - 1] = at(i) * i;\n        }\n    \
    \    return res;\n    }\n\n    Poly inte() const {\n        V<D> res(size() +\
    \ 1);\n        for (int i = 0; i < size(); ++i) {\n            res[i + 1] = at(i)\
    \ / (D)(i + 1);\n        }\n        return res;\n    }\n\n    // f * f.inv(m)\
    \ === 1 mod (x^m)\n    // f_0 ^ -1 must exist\n    Poly inv(int m) const {\n \
    \       Poly res = Poly({D(1) / at(0)});\n        for (int i = 1; i < m; i *=\
    \ 2) {\n            res = (res * D(2) - res * res * pref(i * 2)).pref(i * 2);\n\
    \        }\n        return res.pref(m);\n    }\n\n    // f_0 = 1 must hold\n \
    \   Poly log(int n) const {\n        auto f = pref(n);\n        return (f.diff()\
    \ * f.inv(n - 1)).pref(n - 1).inte();\n    }\n\n    // f_0 = 0 must hold\n   \
    \ Poly exp(int n) const {\n        auto h = diff();\n        Poly f({1}), g({1});\n\
    \n        for (int m = 1; m < n; m *= 2) {\n            g = (g * D(2) - f * g\
    \ * g).pref(m);\n            auto q = h.pref(m - 1);\n            auto w = (q\
    \ + g * (f.diff() - f * q)).pref(m * 2 - 1);\n            f = (f + f * (*this\
    \ - w.inte()).pref(m * 2)).pref(m * 2);\n        }\n\n        return f.pref(n);\n\
    \    }\n\n    // front n elements of f(x)^k\n    // be careful when k = 0\n  \
    \  Poly pow(ll k, int n) const {\n        int zero = 0;\n        while (zero <\
    \ size() && at(zero) == 0) {\n            zero++;\n        }\n\n        if (zero\
    \ == size() || zero * k >= n) {\n            Poly res(n);\n            if (n >\
    \ 0 && k == 0) res[0] = 1;\n            return res;\n        }\n\n        Poly\
    \ h(this->begin() + zero, this->end());\n        debug(h);\n        D a = h[0],\
    \ ra = D(1) / a;\n        h *= ra;\n        h = h.log(n - zero * k) * D(k);\n\
    \        h = h.exp(n - zero * k);\n        h = h.shiftr(zero * k) * a.pow(k);\n\
    \        return h;\n    }\n\n    // f_0 = 1 must hold (use it with modular sqrt)\n\
    \    // CF250E\n    Poly sqrt(int n) const {\n        Poly f = pref(n);\n    \
    \    Poly g({1});\n        for (int i = 1; i < n; i *= 2) {\n            g = (g\
    \ + f.pref(i * 2) * g.inv(i * 2)) * D(2).inv();\n        }\n        return g.pref(n);\n\
    \    }\n\n    D eval(D x) const {\n        D res = 0, c = 1;\n        for (auto\
    \ a : *this) {\n            res += a * c;\n            c *= x;\n        }\n  \
    \      return res;\n    }\n\n    Poly powmod(ll k, const Poly& md) {\n       \
    \ auto v = *this % md;\n        Poly res{1};\n        while (k) {\n          \
    \  if (k & 1) {\n                res = res * v % md;\n            }\n        \
    \    v = v * v % md;\n            k /= 2;\n        }\n        return res;\n  \
    \  }\n\n    Poly& operator+=(const Poly& r) { return *this = *this + r; }\n  \
    \  Poly& operator-=(const Poly& r) { return *this = *this - r; }\n    Poly& operator*=(const\
    \ D& r) { return *this = *this * r; }\n    Poly& operator*=(const Poly& r) { return\
    \ *this = *this * r; }\n    Poly& operator/=(const Poly& r) { return *this = *this\
    \ / r; }\n    Poly& operator/=(const D& r) { return *this = *this / r; }\n   \
    \ Poly& operator%=(const Poly& r) { return *this = *this % r; }\n\n    friend\
    \ ostream& operator<<(ostream& os, const Poly& pl) {\n        if (pl.size() ==\
    \ 0) return os << \"0\";\n        for (int i = 0; i < pl.size(); ++i) {\n    \
    \        if (pl[i]) {\n                os << pl[i] << \"x^\" << i;\n         \
    \       if (i + 1 != pl.size()) os << \",\";\n            }\n        }\n     \
    \   return os;\n    }\n\n    explicit operator bool() const {\n        bool f\
    \ = false;\n        for (int i = 0; i < size(); ++i) {\n            if (at(i))\
    \ {\n                f = true;\n            }\n        }\n        return f;\n\
    \    }\n};\n"
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
    \ntemplate <class D>\nstruct Poly : public V<D> {\n    template <class... Args>\n\
    \    Poly(Args... args) : V<D>(args...) {}\n    Poly(initializer_list<D> init)\
    \ : V<D>(init.begin(), init.end()) {}\n\n    int size() const { return V<D>::size();\
    \ }\n    D at(int p) const { return (p < this->size() ? (*this)[p] : D(0)); }\n\
    \n    void shrink() {\n        while (this->size() > 0 && this->back() == D(0))\
    \ this->pop_back();\n    }\n\n    // first len terms\n    Poly pref(int len) const\
    \ {\n        return Poly(this->begin(), this->begin() + min(this->size(), len));\n\
    \    }\n\n    // for polynomial division\n    Poly rev() const {\n        Poly\
    \ res = *this;\n        reverse(res.begin(), res.end());\n        return res;\n\
    \    }\n\n    Poly shiftr(int d) const {\n        int n = max(size() + d, 0);\n\
    \        Poly res(n);\n        for (int i = 0; i < size(); ++i) {\n          \
    \  if (i + d >= 0) {\n                res[i + d] = at(i);\n            }\n   \
    \     }\n        return res;\n    }\n\n    Poly operator+(const Poly& r) const\
    \ {\n        auto n = max(size(), r.size());\n        V<D> tmp(n);\n        for\
    \ (int i = 0; i < n; ++i) {\n            tmp[i] = at(i) + r.at(i);\n        }\n\
    \        return tmp;\n    }\n    Poly operator-(const Poly& r) const {\n     \
    \   auto n = max(size(), r.size());\n        V<D> tmp(n);\n        for (int i\
    \ = 0; i < n; ++i) {\n            tmp[i] = at(i) - r.at(i);\n        }\n     \
    \   return tmp;\n    }\n\n    // scalar\n    Poly operator*(const D& k) const\
    \ {\n        int n = size();\n        V<D> tmp(n);\n        for (int i = 0; i\
    \ < n; ++i) {\n            tmp[i] = at(i) * k;\n        }\n        return tmp;\n\
    \    }\n\n    Poly operator*(const Poly& r) const {\n        Poly a = *this;\n\
    \        Poly b = r;\n        auto v = arbmod_convolution(a, b, D::get_mod());\n\
    \        return v;\n    }\n\n    // scalar\n    Poly operator/(const D& k) const\
    \ { return *this * k.inv(); }\n\n    Poly operator/(const Poly& r) const {\n \
    \       if (size() < r.size()) {\n            return {{}};\n        }\n      \
    \  int d = size() - r.size() + 1;\n        return (rev().pref(d) * r.rev().inv(d)).pref(d).rev();\n\
    \    }\n\n    Poly operator%(const Poly& r) const {\n        auto res = *this\
    \ - *this / r * r;\n        res.shrink();\n        return res;\n    }\n\n    Poly\
    \ diff() const {\n        V<D> res(max(0, size() - 1));\n        for (int i =\
    \ 1; i < size(); ++i) {\n            res[i - 1] = at(i) * i;\n        }\n    \
    \    return res;\n    }\n\n    Poly inte() const {\n        V<D> res(size() +\
    \ 1);\n        for (int i = 0; i < size(); ++i) {\n            res[i + 1] = at(i)\
    \ / (D)(i + 1);\n        }\n        return res;\n    }\n\n    // f * f.inv(m)\
    \ === 1 mod (x^m)\n    // f_0 ^ -1 must exist\n    Poly inv(int m) const {\n \
    \       Poly res = Poly({D(1) / at(0)});\n        for (int i = 1; i < m; i *=\
    \ 2) {\n            res = (res * D(2) - res * res * pref(i * 2)).pref(i * 2);\n\
    \        }\n        return res.pref(m);\n    }\n\n    // f_0 = 1 must hold\n \
    \   Poly log(int n) const {\n        auto f = pref(n);\n        return (f.diff()\
    \ * f.inv(n - 1)).pref(n - 1).inte();\n    }\n\n    // f_0 = 0 must hold\n   \
    \ Poly exp(int n) const {\n        auto h = diff();\n        Poly f({1}), g({1});\n\
    \n        for (int m = 1; m < n; m *= 2) {\n            g = (g * D(2) - f * g\
    \ * g).pref(m);\n            auto q = h.pref(m - 1);\n            auto w = (q\
    \ + g * (f.diff() - f * q)).pref(m * 2 - 1);\n            f = (f + f * (*this\
    \ - w.inte()).pref(m * 2)).pref(m * 2);\n        }\n\n        return f.pref(n);\n\
    \    }\n\n    // front n elements of f(x)^k\n    // be careful when k = 0\n  \
    \  Poly pow(ll k, int n) const {\n        int zero = 0;\n        while (zero <\
    \ size() && at(zero) == 0) {\n            zero++;\n        }\n\n        if (zero\
    \ == size() || zero * k >= n) {\n            Poly res(n);\n            if (n >\
    \ 0 && k == 0) res[0] = 1;\n            return res;\n        }\n\n        Poly\
    \ h(this->begin() + zero, this->end());\n        debug(h);\n        D a = h[0],\
    \ ra = D(1) / a;\n        h *= ra;\n        h = h.log(n - zero * k) * D(k);\n\
    \        h = h.exp(n - zero * k);\n        h = h.shiftr(zero * k) * a.pow(k);\n\
    \        return h;\n    }\n\n    // f_0 = 1 must hold (use it with modular sqrt)\n\
    \    // CF250E\n    Poly sqrt(int n) const {\n        Poly f = pref(n);\n    \
    \    Poly g({1});\n        for (int i = 1; i < n; i *= 2) {\n            g = (g\
    \ + f.pref(i * 2) * g.inv(i * 2)) * D(2).inv();\n        }\n        return g.pref(n);\n\
    \    }\n\n    D eval(D x) const {\n        D res = 0, c = 1;\n        for (auto\
    \ a : *this) {\n            res += a * c;\n            c *= x;\n        }\n  \
    \      return res;\n    }\n\n    Poly powmod(ll k, const Poly& md) {\n       \
    \ auto v = *this % md;\n        Poly res{1};\n        while (k) {\n          \
    \  if (k & 1) {\n                res = res * v % md;\n            }\n        \
    \    v = v * v % md;\n            k /= 2;\n        }\n        return res;\n  \
    \  }\n\n    Poly& operator+=(const Poly& r) { return *this = *this + r; }\n  \
    \  Poly& operator-=(const Poly& r) { return *this = *this - r; }\n    Poly& operator*=(const\
    \ D& r) { return *this = *this * r; }\n    Poly& operator*=(const Poly& r) { return\
    \ *this = *this * r; }\n    Poly& operator/=(const Poly& r) { return *this = *this\
    \ / r; }\n    Poly& operator/=(const D& r) { return *this = *this / r; }\n   \
    \ Poly& operator%=(const Poly& r) { return *this = *this % r; }\n\n    friend\
    \ ostream& operator<<(ostream& os, const Poly& pl) {\n        if (pl.size() ==\
    \ 0) return os << \"0\";\n        for (int i = 0; i < pl.size(); ++i) {\n    \
    \        if (pl[i]) {\n                os << pl[i] << \"x^\" << i;\n         \
    \       if (i + 1 != pl.size()) os << \",\";\n            }\n        }\n     \
    \   return os;\n    }\n\n    explicit operator bool() const {\n        bool f\
    \ = false;\n        for (int i = 0; i < size(); ++i) {\n            if (at(i))\
    \ {\n                f = true;\n            }\n        }\n        return f;\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/math/FormalPowerSeriesArbitrary.hpp
  requiredBy: []
  timestamp: '2022-04-10 12:39:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/math/FormalPowerSeriesArbitrary.hpp
layout: document
redirect_from:
- /library/cpp_src/math/FormalPowerSeriesArbitrary.hpp
- /library/cpp_src/math/FormalPowerSeriesArbitrary.hpp.html
title: cpp_src/math/FormalPowerSeriesArbitrary.hpp
---
