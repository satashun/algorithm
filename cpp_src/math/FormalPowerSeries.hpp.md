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
  bundledCode: "#line 1 \"cpp_src/math/FormalPowerSeries.hpp\"\n// depends on FFT\
    \ libs\n// work only with NTT-friendly mod \n\nNumberTheoreticTransform<Mint>\
    \ ntt;\n\nstruct prepare_FPS {\n    prepare_FPS() { ntt.init(); }\n} prep_FPS;\n\
    \ntemplate <class D>\nstruct Poly : public V<D> {\n    template <class... Args>\n\
    \    Poly(Args... args) : V<D>(args...) {}\n    Poly(initializer_list<D> init)\
    \ : V<D>(init.begin(), init.end()) {}\n\n    int size() const { return V<D>::size();\
    \ }\n    D at(int p) const { return (p < this->size() ? (*this)[p] : D(0)); }\n\
    \    \n    void shrink() {\n        while (this->size() > 0 && this->back() ==\
    \ D(0)) this->pop_back();\n    }\n\n    // first len terms\n    Poly pref(int\
    \ len) const {\n        return Poly(this->begin(), this->begin() + min(this->size(),\
    \ len));\n    }\n\n    // for polynomial division\n    Poly rev() const {\n  \
    \      Poly res = *this;\n        reverse(res.begin(), res.end());\n        return\
    \ res;\n    }\n\n    Poly shiftr(int d) const {\n        int n = max(size() +\
    \ d, 0);\n        Poly res(n);\n        for (int i = 0; i < size(); ++i) {\n \
    \           if (i + d >= 0) {\n                res[i + d] = at(i);\n         \
    \   }\n        }\n        return res;\n    }\n\n    Poly operator+(const Poly&\
    \ r) const {\n        auto n = max(size(), r.size());\n        V<D> tmp(n);\n\
    \        for (int i = 0; i < n; ++i) {\n            tmp[i] = at(i) + r.at(i);\n\
    \        }\n        return tmp;\n    }\n    Poly operator-(const Poly& r) const\
    \ {\n        auto n = max(size(), r.size());\n        V<D> tmp(n);\n        for\
    \ (int i = 0; i < n; ++i) {\n            tmp[i] = at(i) - r.at(i);\n        }\n\
    \        return tmp;\n    }\n\n    // scalar\n    Poly operator*(const D& k) const\
    \ {\n        int n = size();\n        V<D> tmp(n);\n        for (int i = 0; i\
    \ < n; ++i) {\n            tmp[i] = at(i) * k;\n        }\n        return tmp;\n\
    \    }\n\n    Poly operator*(const Poly& r) const {\n        Poly a = *this;\n\
    \        Poly b = r;\n        auto v = ntt.mul(a, b);\n        return v;\n   \
    \ }\n\n    // scalar\n    Poly operator/(const D& k) const { return *this * k.inv();\
    \ }\n\n    Poly operator/(const Poly& r) const {\n        if (size() < r.size())\
    \ {\n            return {{}};\n        }\n        int d = size() - r.size() +\
    \ 1;\n        return (rev().pref(d) * r.rev().inv(d)).pref(d).rev();\n    }\n\n\
    \    Poly operator%(const Poly& r) const {\n        auto res = *this - *this /\
    \ r * r;\n        res.shrink();\n        return res;\n    }\n\n    Poly diff()\
    \ const {\n        V<D> res(max(0, size() - 1));\n        for (int i = 1; i <\
    \ size(); ++i) {\n            res[i - 1] = at(i) * i;\n        }\n        return\
    \ res;\n    }\n\n    Poly inte() const {\n        V<D> res(size() + 1);\n    \
    \    for (int i = 0; i < size(); ++i) {\n            res[i + 1] = at(i) / (D)(i\
    \ + 1);\n        }\n        return res;\n    }\n\n    // f * f.inv(m) === 1 mod\
    \ (x^m)\n    // f_0 ^ -1 must exist\n    Poly inv(int m) const {\n        Poly\
    \ res = Poly({D(1) / at(0)});\n        for (int i = 1; i < m; i *= 2) {\n    \
    \        res = (res * D(2) - res * res * pref(i * 2)).pref(i * 2);\n        }\n\
    \        return res.pref(m);\n    }\n\n    // f_0 = 1 must hold\n    Poly log(int\
    \ n) const {\n        auto f = pref(n);\n        return (f.diff() * f.inv(n -\
    \ 1)).pref(n - 1).inte();\n    }\n\n    // f_0 = 0 must hold\n    Poly exp(int\
    \ n) const {\n        auto h = diff();\n        Poly f({1}), g({1});\n\n     \
    \   for (int m = 1; m < n; m *= 2) {\n            g = (g * D(2) - f * g * g).pref(m);\n\
    \            auto q = h.pref(m - 1);\n            auto w = (q + g * (f.diff()\
    \ - f * q)).pref(m * 2 - 1);\n            f = (f + f * (*this - w.inte()).pref(m\
    \ * 2)).pref(m * 2);\n        }\n\n        return f.pref(n);\n    }\n\n    //\
    \ front n elements of f(x)^k\n    // be careful when k = 0\n    Poly pow(ll k,\
    \ int n) const {\n        int zero = 0;\n        while (zero < size() && at(zero)\
    \ == 0) {\n            zero++;\n        }\n\n        if (zero == size() || zero\
    \ * k >= n) {\n            Poly res(n);\n            if (n > 0 && k == 0) res[0]\
    \ = 1;\n            return res;\n        }\n\n        Poly h(this->begin() + zero,\
    \ this->end());\n        D a = h[0], ra = D(1) / a;\n        h *= ra;\n      \
    \  h = h.log(n - zero * k) * D(k);\n        h = h.exp(n - zero * k);\n       \
    \ h = h.shiftr(zero * k) * a.pow(k);\n        return h;\n    }\n\n    // f_0 =\
    \ 1 must hold (use it with modular sqrt)\n    // CF250E\n    Poly sqrt(int n)\
    \ const {\n        Poly f = pref(n);\n        Poly g({1});\n        for (int i\
    \ = 1; i < n; i *= 2) {\n            g = (g + f.pref(i * 2) * g.inv(i * 2)) *\
    \ D(2).inv();\n        }\n        return g.pref(n);\n    }\n\n    D eval(D x)\
    \ const {\n        D res = 0, c = 1;\n        for (auto a : *this) {\n       \
    \     res += a * c;\n            c *= x;\n        }\n        return res;\n   \
    \ }\n\n    Poly powmod(ll k, const Poly& md) {\n        auto v = *this % md;\n\
    \        Poly res{1};\n        while (k) {\n            if (k & 1) {\n       \
    \         res = res * v % md;\n            }\n            v = v * v % md;\n  \
    \          k /= 2;\n        }\n        return res;\n    }\n\n    Poly& operator+=(const\
    \ Poly& r) { return *this = *this + r; }\n    Poly& operator-=(const Poly& r)\
    \ { return *this = *this - r; }\n    Poly& operator*=(const D& r) { return *this\
    \ = *this * r; }\n    Poly& operator*=(const Poly& r) { return *this = *this *\
    \ r; }\n    Poly& operator/=(const Poly& r) { return *this = *this / r; }\n  \
    \  Poly& operator/=(const D& r) { return *this = *this / r; }\n    Poly& operator%=(const\
    \ Poly& r) { return *this = *this % r; }\n\n    friend ostream& operator<<(ostream&\
    \ os, const Poly& pl) {\n        if (pl.size() == 0) return os << \"0\";\n   \
    \     for (int i = 0; i < pl.size(); ++i) {\n            if (pl[i]) {\n      \
    \          os << pl[i] << \"x^\" << i;\n                if (i + 1 != pl.size())\
    \ os << \",\";\n            }\n        }\n        return os;\n    }\n\n    explicit\
    \ operator bool() const {\n        bool f = false;\n        for (int i = 0; i\
    \ < size(); ++i) {\n            if (at(i)) {\n                f = true;\n    \
    \        }\n        }\n        return f;\n    }\n};\n\n// calculate characteristic\
    \ polynomial\n// c_0 * s_i + c_1 * s_{i+1} + ... + c_k * s_{i+k} = 0\n// c_k =\
    \ -1\n\ntemplate <class T>\nPoly<T> berlekamp_massey(const V<T>& s) {\n    int\
    \ n = int(s.size());\n    V<T> b = {T(-1)}, c = {T(-1)};\n    T y = Mint(1);\n\
    \    for (int ed = 1; ed <= n; ed++) {\n        int l = int(c.size()), m = int(b.size());\n\
    \        T x = 0;\n        for (int i = 0; i < l; i++) {\n            x += c[i]\
    \ * s[ed - l + i];\n        }\n        b.push_back(0);\n        m++;\n       \
    \ if (!x) {\n            continue;\n        }\n        T freq = x / y;\n     \
    \   if (l < m) {\n            auto tmp = c;\n            c.insert(begin(c), m\
    \ - l, Mint(0));\n            for (int i = 0; i < m; i++) {\n                c[m\
    \ - 1 - i] -= freq * b[m - 1 - i];\n            }\n            b = tmp;\n    \
    \        y = x;\n        } else {\n            for (int i = 0; i < m; i++) {\n\
    \                c[l - 1 - i] -= freq * b[m - 1 - i];\n            }\n       \
    \ }\n    }\n    return c;\n}\n\n// HUPC 2020 day3 K, ABC225H\n// calculate vec[0]\
    \ * vec[1] * ...\n// deg(result) must be bounded\n\ntemplate <class T>\nPoly<T>\
    \ prod(const V<Poly<T>>& vec) {\n    auto comp = [](const auto& a, const auto&\
    \ b) -> bool {\n        return a.size() > b.size();\n    };\n    priority_queue<Poly<T>,\
    \ V<Poly<T>>, decltype(comp)> que(comp);\n    que.push(Poly<T>{1});\n\n    for\
    \ (auto& pl : vec) que.push(pl);\n\n    while (que.size() > 1) {\n        auto\
    \ va = que.top();\n        que.pop();\n        auto vb = que.top();\n        que.pop();\n\
    \        que.push(va * vb);\n    }\n\n    return que.top();\n}\n\n// ABC215 G\n\
    // expand f(x + c)\n// require factorial\ntemplate <class T>\nPoly<T> taylor_shift(const\
    \ Poly<T>& f, ll c) {\n    using P = Poly<T>;\n    int n = f.size();\n    T powc\
    \ = 1;\n    P p(n), q(n);\n\n    rep(i, n) {\n        p[i] = f[i] * fact[i];\n\
    \        q[n - 1 - i] = powc * ifact[i];\n        powc *= c;\n    }\n    p = p\
    \ * q;\n    rep(i, n) q[i] = p[n - 1 + i] * ifact[i];\n    return q;\n}\n"
  code: "// depends on FFT libs\n// work only with NTT-friendly mod \n\nNumberTheoreticTransform<Mint>\
    \ ntt;\n\nstruct prepare_FPS {\n    prepare_FPS() { ntt.init(); }\n} prep_FPS;\n\
    \ntemplate <class D>\nstruct Poly : public V<D> {\n    template <class... Args>\n\
    \    Poly(Args... args) : V<D>(args...) {}\n    Poly(initializer_list<D> init)\
    \ : V<D>(init.begin(), init.end()) {}\n\n    int size() const { return V<D>::size();\
    \ }\n    D at(int p) const { return (p < this->size() ? (*this)[p] : D(0)); }\n\
    \    \n    void shrink() {\n        while (this->size() > 0 && this->back() ==\
    \ D(0)) this->pop_back();\n    }\n\n    // first len terms\n    Poly pref(int\
    \ len) const {\n        return Poly(this->begin(), this->begin() + min(this->size(),\
    \ len));\n    }\n\n    // for polynomial division\n    Poly rev() const {\n  \
    \      Poly res = *this;\n        reverse(res.begin(), res.end());\n        return\
    \ res;\n    }\n\n    Poly shiftr(int d) const {\n        int n = max(size() +\
    \ d, 0);\n        Poly res(n);\n        for (int i = 0; i < size(); ++i) {\n \
    \           if (i + d >= 0) {\n                res[i + d] = at(i);\n         \
    \   }\n        }\n        return res;\n    }\n\n    Poly operator+(const Poly&\
    \ r) const {\n        auto n = max(size(), r.size());\n        V<D> tmp(n);\n\
    \        for (int i = 0; i < n; ++i) {\n            tmp[i] = at(i) + r.at(i);\n\
    \        }\n        return tmp;\n    }\n    Poly operator-(const Poly& r) const\
    \ {\n        auto n = max(size(), r.size());\n        V<D> tmp(n);\n        for\
    \ (int i = 0; i < n; ++i) {\n            tmp[i] = at(i) - r.at(i);\n        }\n\
    \        return tmp;\n    }\n\n    // scalar\n    Poly operator*(const D& k) const\
    \ {\n        int n = size();\n        V<D> tmp(n);\n        for (int i = 0; i\
    \ < n; ++i) {\n            tmp[i] = at(i) * k;\n        }\n        return tmp;\n\
    \    }\n\n    Poly operator*(const Poly& r) const {\n        Poly a = *this;\n\
    \        Poly b = r;\n        auto v = ntt.mul(a, b);\n        return v;\n   \
    \ }\n\n    // scalar\n    Poly operator/(const D& k) const { return *this * k.inv();\
    \ }\n\n    Poly operator/(const Poly& r) const {\n        if (size() < r.size())\
    \ {\n            return {{}};\n        }\n        int d = size() - r.size() +\
    \ 1;\n        return (rev().pref(d) * r.rev().inv(d)).pref(d).rev();\n    }\n\n\
    \    Poly operator%(const Poly& r) const {\n        auto res = *this - *this /\
    \ r * r;\n        res.shrink();\n        return res;\n    }\n\n    Poly diff()\
    \ const {\n        V<D> res(max(0, size() - 1));\n        for (int i = 1; i <\
    \ size(); ++i) {\n            res[i - 1] = at(i) * i;\n        }\n        return\
    \ res;\n    }\n\n    Poly inte() const {\n        V<D> res(size() + 1);\n    \
    \    for (int i = 0; i < size(); ++i) {\n            res[i + 1] = at(i) / (D)(i\
    \ + 1);\n        }\n        return res;\n    }\n\n    // f * f.inv(m) === 1 mod\
    \ (x^m)\n    // f_0 ^ -1 must exist\n    Poly inv(int m) const {\n        Poly\
    \ res = Poly({D(1) / at(0)});\n        for (int i = 1; i < m; i *= 2) {\n    \
    \        res = (res * D(2) - res * res * pref(i * 2)).pref(i * 2);\n        }\n\
    \        return res.pref(m);\n    }\n\n    // f_0 = 1 must hold\n    Poly log(int\
    \ n) const {\n        auto f = pref(n);\n        return (f.diff() * f.inv(n -\
    \ 1)).pref(n - 1).inte();\n    }\n\n    // f_0 = 0 must hold\n    Poly exp(int\
    \ n) const {\n        auto h = diff();\n        Poly f({1}), g({1});\n\n     \
    \   for (int m = 1; m < n; m *= 2) {\n            g = (g * D(2) - f * g * g).pref(m);\n\
    \            auto q = h.pref(m - 1);\n            auto w = (q + g * (f.diff()\
    \ - f * q)).pref(m * 2 - 1);\n            f = (f + f * (*this - w.inte()).pref(m\
    \ * 2)).pref(m * 2);\n        }\n\n        return f.pref(n);\n    }\n\n    //\
    \ front n elements of f(x)^k\n    // be careful when k = 0\n    Poly pow(ll k,\
    \ int n) const {\n        int zero = 0;\n        while (zero < size() && at(zero)\
    \ == 0) {\n            zero++;\n        }\n\n        if (zero == size() || zero\
    \ * k >= n) {\n            Poly res(n);\n            if (n > 0 && k == 0) res[0]\
    \ = 1;\n            return res;\n        }\n\n        Poly h(this->begin() + zero,\
    \ this->end());\n        D a = h[0], ra = D(1) / a;\n        h *= ra;\n      \
    \  h = h.log(n - zero * k) * D(k);\n        h = h.exp(n - zero * k);\n       \
    \ h = h.shiftr(zero * k) * a.pow(k);\n        return h;\n    }\n\n    // f_0 =\
    \ 1 must hold (use it with modular sqrt)\n    // CF250E\n    Poly sqrt(int n)\
    \ const {\n        Poly f = pref(n);\n        Poly g({1});\n        for (int i\
    \ = 1; i < n; i *= 2) {\n            g = (g + f.pref(i * 2) * g.inv(i * 2)) *\
    \ D(2).inv();\n        }\n        return g.pref(n);\n    }\n\n    D eval(D x)\
    \ const {\n        D res = 0, c = 1;\n        for (auto a : *this) {\n       \
    \     res += a * c;\n            c *= x;\n        }\n        return res;\n   \
    \ }\n\n    Poly powmod(ll k, const Poly& md) {\n        auto v = *this % md;\n\
    \        Poly res{1};\n        while (k) {\n            if (k & 1) {\n       \
    \         res = res * v % md;\n            }\n            v = v * v % md;\n  \
    \          k /= 2;\n        }\n        return res;\n    }\n\n    Poly& operator+=(const\
    \ Poly& r) { return *this = *this + r; }\n    Poly& operator-=(const Poly& r)\
    \ { return *this = *this - r; }\n    Poly& operator*=(const D& r) { return *this\
    \ = *this * r; }\n    Poly& operator*=(const Poly& r) { return *this = *this *\
    \ r; }\n    Poly& operator/=(const Poly& r) { return *this = *this / r; }\n  \
    \  Poly& operator/=(const D& r) { return *this = *this / r; }\n    Poly& operator%=(const\
    \ Poly& r) { return *this = *this % r; }\n\n    friend ostream& operator<<(ostream&\
    \ os, const Poly& pl) {\n        if (pl.size() == 0) return os << \"0\";\n   \
    \     for (int i = 0; i < pl.size(); ++i) {\n            if (pl[i]) {\n      \
    \          os << pl[i] << \"x^\" << i;\n                if (i + 1 != pl.size())\
    \ os << \",\";\n            }\n        }\n        return os;\n    }\n\n    explicit\
    \ operator bool() const {\n        bool f = false;\n        for (int i = 0; i\
    \ < size(); ++i) {\n            if (at(i)) {\n                f = true;\n    \
    \        }\n        }\n        return f;\n    }\n};\n\n// calculate characteristic\
    \ polynomial\n// c_0 * s_i + c_1 * s_{i+1} + ... + c_k * s_{i+k} = 0\n// c_k =\
    \ -1\n\ntemplate <class T>\nPoly<T> berlekamp_massey(const V<T>& s) {\n    int\
    \ n = int(s.size());\n    V<T> b = {T(-1)}, c = {T(-1)};\n    T y = Mint(1);\n\
    \    for (int ed = 1; ed <= n; ed++) {\n        int l = int(c.size()), m = int(b.size());\n\
    \        T x = 0;\n        for (int i = 0; i < l; i++) {\n            x += c[i]\
    \ * s[ed - l + i];\n        }\n        b.push_back(0);\n        m++;\n       \
    \ if (!x) {\n            continue;\n        }\n        T freq = x / y;\n     \
    \   if (l < m) {\n            auto tmp = c;\n            c.insert(begin(c), m\
    \ - l, Mint(0));\n            for (int i = 0; i < m; i++) {\n                c[m\
    \ - 1 - i] -= freq * b[m - 1 - i];\n            }\n            b = tmp;\n    \
    \        y = x;\n        } else {\n            for (int i = 0; i < m; i++) {\n\
    \                c[l - 1 - i] -= freq * b[m - 1 - i];\n            }\n       \
    \ }\n    }\n    return c;\n}\n\n// HUPC 2020 day3 K, ABC225H\n// calculate vec[0]\
    \ * vec[1] * ...\n// deg(result) must be bounded\n\ntemplate <class T>\nPoly<T>\
    \ prod(const V<Poly<T>>& vec) {\n    auto comp = [](const auto& a, const auto&\
    \ b) -> bool {\n        return a.size() > b.size();\n    };\n    priority_queue<Poly<T>,\
    \ V<Poly<T>>, decltype(comp)> que(comp);\n    que.push(Poly<T>{1});\n\n    for\
    \ (auto& pl : vec) que.push(pl);\n\n    while (que.size() > 1) {\n        auto\
    \ va = que.top();\n        que.pop();\n        auto vb = que.top();\n        que.pop();\n\
    \        que.push(va * vb);\n    }\n\n    return que.top();\n}\n\n// ABC215 G\n\
    // expand f(x + c)\n// require factorial\ntemplate <class T>\nPoly<T> taylor_shift(const\
    \ Poly<T>& f, ll c) {\n    using P = Poly<T>;\n    int n = f.size();\n    T powc\
    \ = 1;\n    P p(n), q(n);\n\n    rep(i, n) {\n        p[i] = f[i] * fact[i];\n\
    \        q[n - 1 - i] = powc * ifact[i];\n        powc *= c;\n    }\n    p = p\
    \ * q;\n    rep(i, n) q[i] = p[n - 1 + i] * ifact[i];\n    return q;\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/math/FormalPowerSeries.hpp
  requiredBy: []
  timestamp: '2022-04-10 12:39:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/math/FormalPowerSeries.hpp
layout: document
redirect_from:
- /library/cpp_src/math/FormalPowerSeries.hpp
- /library/cpp_src/math/FormalPowerSeries.hpp.html
title: cpp_src/math/FormalPowerSeries.hpp
---
